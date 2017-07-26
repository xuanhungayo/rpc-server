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

NonblockingServer::NonblockingServer(int port):
port_(port),
epoll_fd_(epoll_create(1)) {
}

NonblockingServer::~NonblockingServer() {
}

void NonblockingServer::run() {
	std::shared_ptr<ServerSocket> ssocket(new ServerSocket(port_));
	std::thread io_thread(&NonblockingServer::IOThread, this);
	io_thread.detach();
	ssocket->listen();
	while (1) {
		std::shared_ptr<Socket> socket = ssocket->accept();
		addEvent(socket);
	}
}

void NonblockingServer::addEvent(std::shared_ptr<Socket> socket) {
	epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = socket->getSocket();
	if (epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, event.data.fd, &event) == -1) {
		perror("Add event");
	};
}

void NonblockingServer::IOThread() {
	epoll_event* events = (epoll_event*) calloc(MAX_EVENT, EVENT_SIZE);
	int event_num;
	std::shared_ptr<Socket> socket(new Socket(0));
	std::shared_ptr<Handler> handler(new Handler());
	std::shared_ptr<Protocol> protocol(new Protocol(socket));
	Processor processor(protocol, handler);
	
	while (1) {
		if ( (event_num = epoll_wait(epoll_fd_, events, MAX_EVENT, TIME_OUT)) == -1) {
			perror("epoll wait");
			continue;
		}
		for(int i = 0; i < event_num; i++) {
			if (events[i].events & EPOLLERR && events[i].events & EPOLLHUP) {
				std::cout << "Error on fd: " << events[i].data.fd << "\n";
				close(events[i].data.fd);
			}
	
			else {
				socket->setSocket(events[i].data.fd);
				if (!processor.handleRequest()) {
					close(events[i].data.fd);
				}
			}
		}
	}
}

} // namespace tcpserver

