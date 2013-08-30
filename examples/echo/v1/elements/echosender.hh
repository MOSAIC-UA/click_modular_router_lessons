#ifndef CLICK_ECHOSENDER_HH
#define CLICK_ECHOSENDER_HH
#include <click/element.hh>
CLICK_DECLS

class EchoReceiver;

class EchoSender: public Element { 
	public:
		EchoSender();
		~EchoSender();
		
		const char *class_name() const	{ return "EchoSender"; }
		const char *port_count() const	{ return "0/1"; }
		const char *processing() const	{ return PUSH; }
		
		int configure(Vector<String>&, ErrorHandler*);
		
		static int send(const String &conf, Element *e, void *thunk, ErrorHandler *errh);
		void add_handlers();
		
		void generate(const String &content, const IPAddress &to, uint16_t toPort, uint16_t fromPort);
	private:
		int maxSize;
};

CLICK_ENDDECLS
#endif // CLICK_ECHOSENDER_HH