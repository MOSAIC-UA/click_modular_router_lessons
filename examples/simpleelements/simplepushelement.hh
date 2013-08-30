#ifndef CLICK_SIMPLEPUSHELEMENT_HH
#define CLICK_SIMPLEPUSHELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class SimplePushElement : public Element { 
	public:
		SimplePushElement();
		~SimplePushElement();
		
		const char *class_name() const	{ return "SimplePushElement"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return PUSH; }
		int configure(Vector<String>&, ErrorHandler*);
		
		void push(int, Packet *);
	private:
		uint32_t maxSize;
};

CLICK_ENDDECLS
#endif
