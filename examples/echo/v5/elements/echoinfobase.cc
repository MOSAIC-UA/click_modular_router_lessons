#include <click/config.h>
#include <click/confparse.hh>
#include <click/error.hh>
#include "echoinfobase.hh"
CLICK_DECLS
EchoInfoBase::EchoInfoBase(): timer(this)
{
	
}

EchoInfoBase::~ EchoInfoBase()
{}

int EchoInfoBase::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (cp_va_kparse(conf, this, errh, cpEnd) < 0) return -1;
		
	timer.initialize(this); 
	timer.schedule_now();
	
	return 0;
}


void EchoInfoBase::addRequest(const IPAddress &destinationIP, uint16_t sourcePort) {
	click_chatter("adding request to %s from port %u", destinationIP.unparse().c_str(), sourcePort);
	RequestData data;
	data.destinationIP = destinationIP;
	data.sourcePort = sourcePort;
	data.counter=1;
	data.expirationTime = Timestamp::now()+Timestamp::make_msec(10000);
	requests.push_back(data);
}

bool EchoInfoBase::removeRequest(const IPAddress &destinationIP, uint16_t sourcePort) {
	for (RequestVector::iterator i = requests.begin(); i!= requests.end(); i++){
		if (i->destinationIP==destinationIP && i->sourcePort == sourcePort) {
			requests.erase(i);
			click_chatter("removing request from %s from port %u", destinationIP.unparse().c_str(), sourcePort);
			return true;
		}
	}
	return false;
}

void EchoInfoBase::run_timer(Timer*){ 
	for (RequestVector::iterator i = requests.begin(); i!= requests.end(); ){
		if (i->expirationTime < Timestamp::now()) {
			click_chatter("removing request from %s from port %u", i->destinationIP.unparse().c_str(), i->sourcePort);
			i = requests.erase(i);
		} else {
			i++;
		}
	}
	timer.schedule_after_msec(1000);
}


CLICK_ENDDECLS
EXPORT_ELEMENT(EchoInfoBase)

// generate Vector template instance
#include <click/vector.cc>
#if EXPLICIT_TEMPLATE_INSTANCES
template class RequestVector;
#endif