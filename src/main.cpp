/* 
 * File:   main.cpp
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 9:41 PM
 */

#include <iostream>

#include "SimpleServer.h"

using tcpserver::SimpleServer;

int main(int argc, char** argv) {
	SimpleServer server(3000);
	server.run();
	return 0;
}

