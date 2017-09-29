#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include "simpleinfobase.hh"

CLICK_DECLS
SimpleInfoBase::SimpleInfoBase()
{}

SimpleInfoBase::~ SimpleInfoBase()
{}

int SimpleInfoBase::configure(Vector<String> &conf, ErrorHandler *errh) {
	return Args(conf, this, errh).read_m("DIGIT", digit).complete();
}

void SimpleInfoBase::doSomething() {
    click_chatter("SimpleInfobase is configured with digit %d", digit);
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimpleInfoBase)
