#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "echosender.hh"
#include <clicknet/ether.h>
#include <clicknet/ip.h>
#include <clicknet/udp.h>
#include "echoreceiver.hh"

CLICK_DECLS
EchoSender::EchoSender()
{}

EchoSender::~ EchoSender()
{}

int EchoSender::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (cp_va_kparse(conf, this, errh, "MAXPACKETSIZE", cpkM, cpInteger, &maxSize, cpEnd) < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

void EchoSender::generate(const String &content, const IPAddress &to, uint16_t toPort, uint16_t fromPort) {
	click_chatter("sending ECHO with content %s to %s:%u", content.c_str(), to.unparse().c_str(), toPort);
	
	int tailroom = 0;
	int packetsize = sizeof(click_udp) + content.length();
	int headroom = sizeof(click_ether)+sizeof(click_ip); 
	WritablePacket *packet = Packet::make(headroom,0,packetsize, tailroom); 
	if (packet == 0 ) return click_chatter( "cannot make packet!"); 
	
	click_udp *udpHdr = (click_udp *)packet->data();
	udpHdr->uh_sport = htons(fromPort);
	udpHdr->uh_dport = htons(toPort);
	udpHdr->uh_ulen = htons(sizeof(click_udp) + content.length());

	memcpy((char *)(udpHdr+1), content.data(), content.length());
	
	packet->set_dst_ip_anno(to);
	
	output(0).push(packet);
}

int EchoSender::send(const String &conf, Element *e, void *, ErrorHandler * errh){
	EchoSender *me = (EchoSender *) e;
	String content;
	IPAddress to;
	if(cp_va_kparse(conf, me, errh, "CONTENT", cpkM, cpString, &content, "TO", cpkM, cpIPAddress, &to, cpEnd) < 0) 
		return -1; 
	if (content.length() > me->maxSize) {
		return errh->error("Content '%s' exceeds the maximum size of %u byte", content.c_str(), me->maxSize);
	}
	me->generate(content, to, 7, 1234);
	return 0;
}

void EchoSender::add_handlers() { 
	add_write_handler("send", &send, (void *)0);
}


CLICK_ENDDECLS
EXPORT_ELEMENT(EchoSender)
