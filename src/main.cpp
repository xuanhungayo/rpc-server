/* 
 * File:   main.cpp
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 9:41 PM
 */

#include <iostream>

#include "SimpleServer.h"
#include "ThreadedServer.h"

using tcpserver::SimpleServer;
using tcpserver::ThreadedServer;

int main(int argc, char** argv) {
	SimpleServer server(3000);
	server.run();
	return 0;
}

