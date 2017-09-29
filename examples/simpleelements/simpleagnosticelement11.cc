#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include "simpleagnosticelement11.hh"

CLICK_DECLS
SimpleAgnosticElement11::SimpleAgnosticElement11()
{}

SimpleAgnosticElement11::~ SimpleAgnosticElement11()
{}

int SimpleAgnosticElement11::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (Args(conf, this, errh).read_m("MAXPACKETSIZE", maxSize).complete() < 0) return -1;
	if (maxSize <= 0) return errh->error("maxsize should be larger than 0");
	return 0;
}

// this method only works for 1/1 elements, i.e. 'simple packetfilters'
Packet* SimpleAgnosticElement11::simple_action(Packet *p){
	click_chatter("Got a packet of size %d",p->length());
	if (p->length() > maxSize){
		p->kill();
		return 0;
	} else {
		return p;
	}
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimpleAgnosticElement11)
