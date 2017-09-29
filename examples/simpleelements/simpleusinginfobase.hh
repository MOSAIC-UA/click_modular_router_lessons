#ifndef CLICK_SIMPLEUSINGINFOBASE_HH
#define CLICK_SIMPLEUSINGINFOBASE_HH
#include <click/element.hh>
#include "simpleinfobase.hh"
CLICK_DECLS

class SimpleUsingInfoBase : public Element {
	public:
		SimpleUsingInfoBase();
		~SimpleUsingInfoBase();
		
		const char *class_name() const	{ return "SimpleUsingInfoBase"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return PUSH; }
		int configure(Vector<String>&, ErrorHandler*);
    
        void push(int, Packet *);
		
	private:
		SimpleInfoBase* infobase;
};

CLICK_ENDDECLS
#endif
