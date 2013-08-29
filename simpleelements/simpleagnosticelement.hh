#ifndef CLICK_SIMPLEAGNOSTICELEMENT_HH
#define CLICK_SIMPLEAGNOSTICELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class SimpleAgnosticElement : public Element { 
	public:
		SimpleAgnosticElement();
		~SimpleAgnosticElement();
		
		const char *class_name() const	{ return "SimpleAgnosticElement"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return AGNOSTIC; }
		int configure(Vector<String>&, ErrorHandler*);
		
		void push(int, Packet *);
		Packet* pull(int);
	private:
		uint32_t maxSize;
};

CLICK_ENDDECLS
#endif
