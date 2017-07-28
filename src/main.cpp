/* 
 * File:   main.cpp
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 9:41 PM
 */

#include <iostream>

#include "SimpleServer.h"
#include "ThreadedServer.h"
#include "NonblockingServer.h"

using tcpserver::SimpleServer;
using tcpserver::ThreadedServer;
using tcpserver::NonblockingServer;

int main(int argc, char** argv) {
	ThreadedServer server(3000);
	server.run();
	return 0;
}

