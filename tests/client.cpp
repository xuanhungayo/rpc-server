/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.cpp
 * Author: cpu10170-local
 *
 * Created on July 18, 2017, 1:49 PM
 */

#include <stdlib.h>
#include <iostream>
#include <memory>

#include "Socket.h"
#include "Protocol.h"

/*
 * Simple C++ Test Suite
 */

using namespace tcpserver;

int main(int argc, char** argv) {
	std::shared_ptr<Socket> client(new Socket("localhost", 3000));
	client->open();
	Protocol protocol(client);
	
	protocol.writeType(2);
	protocol.writeI32(1);
	
	bool response = 0;
	protocol.readBool(response);
	if (response) {
		std::cout << "Yes yes yes\n";
	}
		
	client->close();
}

