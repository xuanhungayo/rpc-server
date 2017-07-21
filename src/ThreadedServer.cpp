/* 
 * File:   ThreadedServer.cpp
 * Author: xuanhungcao
 * 
 * Created on July 19, 2017, 5:01 PM
 */

#include <iostream>
#include <thread>
#include <vector>

#include "Socket.h"
#include "ServerSocket.h"
#include "Protocol.h"
#include "Processor.h"
#include "ThreadedServer.h"

namespace tcpserver {

ThreadedServer::ThreadedServer(const int port):
port_(port),
handler_(std::make_shared<Handler>()) {
}

ThreadedServer::~ThreadedServer() {
}

void ThreadedServer::run() {
	std::shared_ptr<ServerSocket> ssocket(new ServerSocket(port_));
	ssocket->listen();
	
	while (1) {
		std::shared_ptr<Socket> trans = ssocket->accept();
		std::thread client(&ThreadedServer::process, this, trans);
		client.detach();
	}
}

void ThreadedServer::process(std::shared_ptr<Socket> socket) {
	std::shared_ptr<Protocol> protocol(new Protocol(socket));
	std::shared_ptr<Processor> processor(new Processor(protocol, handler_));
	while (processor->handleRequest()) {};
	socket->close();
}

} // namespace tcpserver

