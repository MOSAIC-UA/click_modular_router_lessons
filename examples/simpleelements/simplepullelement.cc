#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include "simplepullelement.hh"

CLICK_DECLS
SimplePullElement::SimplePullElement()
{}

SimplePullElement::~ SimplePullElement()
{}

int SimplePullElement::configure(Vector<String> &conf, ErrorHandler *errh) {
    if (Args(conf, this, errh).read_m("MAXPACKETSIZE", maxSize).complete() < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

Packet* SimplePullElement::pull(int){
	Packet* p = input(0).pull();
	if(p == 0){
		return 0;
	}
	click_chatter("Got a packet of size %d",p->length());
	if (p->length() > maxSize){
		p->kill();
		return 0;
	} else return p;
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimplePullElement)
