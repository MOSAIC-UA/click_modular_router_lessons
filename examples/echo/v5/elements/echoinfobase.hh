#ifndef CLICK_ECHOINFOBASE_HH
#define CLICK_ECHOINFOBASE_HH
#include <click/element.hh>
#include <click/vector.hh>
#include <click/timer.hh>
CLICK_DECLS

struct RequestData {
	IPAddress destinationIP;
	uint16_t sourcePort;
	unsigned int counter;
	Timestamp expirationTime;
};

typedef Vector<RequestData> RequestVector;

class EchoInfoBase: public Element { 
	public:
		EchoInfoBase();
		~EchoInfoBase();
		
		const char *class_name() const	{ return "EchoInfoBase"; }
		const char *port_count() const	{ return "0/0"; }
		const char *processing() const	{ return PUSH; }
		
		int configure(Vector<String>&, ErrorHandler*);
		
		void addRequest(const IPAddress &destinationIP, uint16_t sourcePort);
		bool removeRequest(const IPAddress &destinationIP, uint16_t sourcePort);
		
		void run_timer(Timer*);
				
	private:
		RequestVector requests;
		
		Timer timer;
};

CLICK_ENDDECLS
#endif // CLICK_ECHORECEIVER_HH