#ifndef CLICK_SIMPLEAGNOSTICELEMENT11_HH
#define CLICK_SIMPLEAGNOSTICELEMENT11_HH
#include <click/element.hh>
CLICK_DECLS

class SimpleAgnosticElement11 : public Element { 
	public:
		SimpleAgnosticElement11();
		~SimpleAgnosticElement11();
		
		const char *class_name() const	{ return "SimpleAgnosticElement11"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return AGNOSTIC; }
		int configure(Vector<String>&, ErrorHandler*);
		
		Packet *simple_action(Packet *);
	private:
		uint32_t maxSize;
};

CLICK_ENDDECLS
#endif
