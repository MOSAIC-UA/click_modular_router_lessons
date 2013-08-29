#ifndef CLICK_SIMPLEPULLELEMENT_HH
#define CLICK_SIMPLEPULLELEMENT_HH
#include <click/element.hh>
CLICK_DECLS

class SimplePullElement : public Element { 
	public:
		SimplePullElement();
		~SimplePullElement();
		
		const char *class_name() const	{ return "SimplePullElement"; }
		const char *port_count() const	{ return "1/1"; }
		const char *processing() const	{ return PULL; }
		int configure(Vector<String>&, ErrorHandler*);
		
		Packet* pull(int);
	private:
		uint32_t maxSize;
};

CLICK_ENDDECLS
#endif
