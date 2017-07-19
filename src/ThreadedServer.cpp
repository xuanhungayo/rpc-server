/* 
 * File:   ThreadedServer.cpp
 * Author: xuanhungcao
 * 
 * Created on July 19, 2017, 5:01 PM
 */

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
	
	std::vector<std::thread> threads;
	while (1) {
		std::shared_ptr<Socket> trans = ssocket->accept();
		threads.push_back(std::thread(&ThreadedServer::process, this, trans));
	}
	for(auto& _thread: threads) _thread.join();
}

void ThreadedServer::process(std::shared_ptr<Socket> trans) {
	std::shared_ptr<Protocol> protocol(new Protocol(trans));
	std::shared_ptr<Processor> processor(new Processor(protocol, handler_));
	while (processor->handleRequest()) {};
}

} // namespace tcpserver

