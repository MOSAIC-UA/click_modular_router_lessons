#include <click/config.h>
#include <click/args.hh>
#include <click/error.hh>
#include "simpleusinginfobase.hh"

CLICK_DECLS
SimpleUsingInfoBase::SimpleUsingInfoBase()
{}

SimpleUsingInfoBase::~ SimpleUsingInfoBase()
{}

int SimpleUsingInfoBase::configure(Vector<String> &conf, ErrorHandler *errh) {
    SimpleInfoBase* tempInfobase;
    
    int result =  Args(conf, this, errh).read_m("INFOBASE", ElementCastArg("SimpleInfoBase"), tempInfobase).complete();
    
    if (result < 0) return result;
    
    infobase = tempInfobase;
    return 0;
}

void SimpleUsingInfoBase::push(int, Packet *p){
    infobase->doSomething();
	output(0).push(p);
}

CLICK_ENDDECLS
EXPORT_ELEMENT(SimpleUsingInfoBase)
