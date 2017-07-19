/* 
 * File:   SimpleServer.cpp
 * Author: xuanhungcao
 * 
 * Created on July 19, 2017, 9:49 AM
 */

#include <memory>

#include "SimpleServer.h"

namespace tcpserver {

SimpleServer::SimpleServer(const int port):
port_(port) {
}

SimpleServer::~SimpleServer() {
}

void SimpleServer::run() {
	std::shared_ptr<ServerSocket> ssocket(new ServerSocket(port_));
	ssocket->listen();
	std::shared_ptr<Handler> handler(new Handler());
	
	while (1) {
		std::shared_ptr<Protocol> protocol(new Protocol(ssocket->accept()));
		std::shared_ptr<Processor> processor(new Processor(protocol, handler));
		while (processor->handleRequest()) {};
	}
}

}

