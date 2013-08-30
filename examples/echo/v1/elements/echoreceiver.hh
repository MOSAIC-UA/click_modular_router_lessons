#ifndef CLICK_ECHORECEIVER_HH
#define CLICK_ECHORECEIVER_HH
#include <click/element.hh>
#include "echosender.hh"
CLICK_DECLS

class EchoReceiver: public Element { 
	public:
		EchoReceiver();
		~EchoReceiver();
		
		const char *class_name() const	{ return "EchoReceiver"; }
		const char *port_count() const	{ return "1/0"; }
		const char *processing() const	{ return PUSH; }
		
		int configure(Vector<String>&, ErrorHandler*);
		
		void push(int, Packet *);
		
};

CLICK_ENDDECLS
#endif // CLICK_ECHORECEIVER_HH