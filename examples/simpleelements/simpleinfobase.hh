#ifndef CLICK_SIMPLEINFOBASE_HH
#define CLICK_SIMPLEINFOBASE_HH
#include <click/element.hh>
CLICK_DECLS

class SimpleInfoBase : public Element { 
	public:
		SimpleInfoBase();
		~SimpleInfoBase();
		
		const char *class_name() const	{ return "SimpleInfoBase"; }
		const char *port_count() const	{ return "0"; }
		const char *processing() const	{ return AGNOSTIC; }
		int configure(Vector<String>&, ErrorHandler*);
		
        void doSomething();
    
	private:
		uint32_t digit;
};

CLICK_ENDDECLS
#endif
