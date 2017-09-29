#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include "simplepushelement.hh"

CLICK_DECLS
SimplePushElement::SimplePushElement()
{}

SimplePushElement::~ SimplePushElement()
{}

int SimplePushElement::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (Args(conf, this, errh).read_m("MAXPACKETSIZE", maxSize).complete() < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

void SimplePushElement::push(int, Packet *p){
	click_chatter("Got a packet of size %d",p->length());
	if (p->length() > maxSize)  p->kill();
	else output(0).push(p);
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimplePushElement)
