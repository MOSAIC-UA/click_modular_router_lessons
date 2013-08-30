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
}

int EchoSender::send(const String &conf, Element *e, void *, ErrorHandler * errh){
	return 0;
}

void EchoSender::add_handlers() { 
	add_write_handler("send", &send, (void *)0);
}


CLICK_ENDDECLS
EXPORT_ELEMENT(EchoSender)
