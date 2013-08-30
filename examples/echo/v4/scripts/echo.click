///================================================================///
///
/// Authors: Bart Braem & Michael Voorhaen
///================================================================///

require(library routers/iprouter1int.click);


///===========================================================================///
/// Definitions of the different hosts and related address information.

AddressInfo(client_address 192.168.1.1/24 00:50:BA:85:84:B1);
AddressInfo(server_address 192.168.1.2/24 00:50:BA:85:84:D1);

client :: IPRouter1int(client_address, server_address);
server :: IPRouter1int(server_address, client_address);

/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// !!!!!!! DO NOT EDIT BELOW THIS LINE: Any changes made below, will be replaced prior to the project defense !!!!!!!!
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/// Note: The ListenEtherSwitch is used to emulate a local LAN network.
lan :: ListenEtherSwitch;

///===========================================================================///
/// The configuration of our small IP network

client[0]
	-> [0]lan[0]
	-> [0] client;
	
server[0]
	-> [1]lan[1]
	-> [0] server;
	
client[1]
	-> Discard;

server[1]
	-> Discard

/// Dump the traffic sniffed at the ListenEtherSwitches
lan[2]
	-> ToDump("lan.dump");
