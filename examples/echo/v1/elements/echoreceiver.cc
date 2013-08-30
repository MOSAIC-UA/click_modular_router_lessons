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
	if (cp_va_kparse(conf, this, errh, cpEnd) < 0) return -1;
	return 0;
}

void EchoReceiver::push(int, Packet *p)
{	
	p->kill();
}

CLICK_ENDDECLS
EXPORT_ELEMENT(EchoReceiver)
