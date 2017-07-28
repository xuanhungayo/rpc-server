/* 
 * File:   NonblockingServer.cpp
 * Author: xuanhungcao
 * 
 * Created on July 21, 2017, 10:59 AM
 */

#include <iostream>
#include <sys/fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "NonblockingServer.h"

namespace tcpserver {

// TODO

IOThread::IOThread(NonblockingServer* server):
server_(server),
epoll_fd_(epoll_create(1)) {
}

IOThread::~IOThread(){
}

void IOThread::run() {
//	std::shared_ptr<ServerSocket> ssocket(new ServerSocket(server_->port_));
//	ssocket->listen();
//	registerEvent(ssocket->getServerSocket());
//
//
//	epoll_event* events = (epoll_event*) calloc(MAX_EVENT, EVENT_SIZE);	
//	//  Main event loop
//	while (1) {
//		int event_num = epoll_wait(epoll_fd_, events, MAX_EVENT, TIME_OUT);
//		if (event_num == -1) {
//			perror("epoll wait");
//			continue;
//		}
//		
//		for(int i = 0; i < event_num; i++) {
//			// Close socket if any error occurs
//			if (events[i].events & EPOLLERR || events[i].events & EPOLLUP) {
//				std::cout << "Error on fd: " << events[i].data.fd << "\n";
//				close(events[i].data.fd);
//				continue;
//			}
//			
//			// Listener event
//			if (events[i].data.fd == ssocket->getServerSocket()) {
//				std::shared_ptr<Socket> socket = ssocket->accept();
//				registerEvent(ssocket)
//			}
//		}
//	}
}


NonblockingServer::NonblockingServer(int port):
port_(port),
io_thread_(this) {
}

NonblockingServer::~NonblockingServer(){
}



} // namespace tcpserver

