#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "echoreceiver.hh"
#include <clicknet/ether.h>
#include <clicknet/ip.h>
#include <clicknet/udp.h>
CLICK_DECLS
EchoReceiver::EchoReceiver()
{}

EchoReceiver::~ EchoReceiver()
{}

int EchoReceiver::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (cp_va_kparse(conf, this, errh, "SENDER", cpkM, cpElement, &sender, cpEnd) < 0) return -1;
	return 0;
}

void EchoReceiver::push(int, Packet *p)
{
	WritablePacket *q = p->uniqueify();
	
	click_ip *ipHdr = (click_ip *)q->data();
	click_udp *udpHdr = (click_udp *)(ipHdr + 1);
	char *rawContent = (char *)(udpHdr + 1);
	String content(rawContent, p->length()-sizeof(click_ip)-sizeof(click_udp));
	
	IPAddress from(ipHdr->ip_src);
	uint16_t fromPrt = ntohs(udpHdr->uh_sport);
	uint16_t toPrt = ntohs(udpHdr->uh_dport);

	if (toPrt == 7) {
		click_chatter("received ECHO with content %s from %s:%u", content.c_str(), from.unparse().c_str(), fromPrt);
		sender->generate(content, IPAddress(ipHdr->ip_src), ntohs(udpHdr->uh_sport), 7);
	} else {
		click_chatter("received ECHO with content %s from %s:%u", content.c_str(), from.unparse().c_str(), fromPrt);
	}
	
	p->kill();
}

CLICK_ENDDECLS
EXPORT_ELEMENT(EchoReceiver)
