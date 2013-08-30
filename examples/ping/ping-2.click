source::ICMPPingSource(10.0.0.1, 10.0.0.2);
responder::ICMPPingResponder;
switch::ListenEtherSwitch

source
	-> EtherEncap(0x0800, 1A:7C:3E:90:78:41, 1A:7C:3E:90:78:42)
	-> [0] switch
	
switch[0]
	-> Strip(14)
	-> MarkIPHeader
	-> source
	
responder
	-> EtherEncap(0x0800, 1A:7C:3E:90:78:41, 1A:7C:3E:90:78:42)
	-> [1] switch	
	
switch[1]
	-> Strip(14)
	-> MarkIPHeader
	-> responder

switch[2]
	-> ToDump(switch.dump)
	-> Discard


