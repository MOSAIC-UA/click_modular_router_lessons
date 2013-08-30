source::ICMPPingSource(10.0.0.1, 10.0.0.2);
responder::ICMPPingResponder;
switch::ListenEtherSwitch

elementclass Router { $src_mac, $dst_mac | 
	input [0]
		-> EtherEncap(0x0800, $src_mac, $dst_mac)
		-> [0] output

	input [1]
		-> Strip(14)
		-> MarkIPHeader
		-> [1] output
}

source
	-> [0] sourceRouter::Router(1A:7C:3E:90:78:41, 1A:7C:3E:90:78:43) [0]
	-> [0] switch
	
switch[0]
	-> [1] sourceRouter [1]
	-> source

responder
	-> [0] responderRouter::Router(1A:7C:3E:90:78:42, 1A:7C:3E:90:78:41) [0]
	-> [1] switch	
	
switch[1]
	-> [1] responderRouter [1]
	-> responder

switch[2]
	-> ToDump(switch.dump)
	-> Discard



