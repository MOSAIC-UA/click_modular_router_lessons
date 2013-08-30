source::ICMPPingSource(10.0.0.1, 10.0.0.2, DATA "test");
responder::ICMPPingResponder;

source->responder
responder->source


