/* 
 * File:   ServerSocket.cpp
 * Author: xuanhungcao
 * 
 * Created on July 18, 2017, 9:58 AM
 */
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "config.h"
#include "ServerSocket.h"

namespace tcpserver {

ServerSocket::ServerSocket(int port) :
port_(port),
server_socket_(-1) {
}

ServerSocket::~ServerSocket() {
	close();
}

void ServerSocket::listen() {
	addrinfo hints, *addr0, *addr;
	int err;

	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if ((err = getaddrinfo(NULL, std::to_string(port_).c_str(), &hints, &addr0)) != 0) {
		std::cout << "Getaddrinfo: " << gai_strerror(err) << std::endl;
		return;
	}

	for (addr = addr0; addr != NULL; addr = addr->ai_next) {
		if ((server_socket_ = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (bind(server_socket_, addr->ai_addr, addr->ai_addrlen) == -1) {
			perror("server: bind");
			close();
			continue;
		}
		break;
	}

	freeaddrinfo(addr0);

	if (server_socket_ == -1) {
		std::cout << "Error creating new socket!" << std::endl;
		return;
	}

	if (::listen(server_socket_, BACKLOG) == -1) {
		perror("server: listen");
		return;
	}

	std::cout << "Server running on port " << port_ << std::endl;
	std::cout << "Waiting for connection ..." << std::endl;
}

std::shared_ptr<Socket> ServerSocket::accept() {
	sockaddr_storage client_addr;
	socklen_t addr_size = sizeof (client_addr);
	int new_socket = ::accept(server_socket_, (sockaddr*) & client_addr, &addr_size);

	if (new_socket == -1) {
		perror("server: accept");
		return nullptr;
	}

	timeval _timeval;
	_timeval.tv_sec = TIME_OUT;
	_timeval.tv_usec = 0;
	if (setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*) &_timeval, sizeof (timeval)) == -1) {
		perror("server: setsockopt");
		return nullptr;
	}

	char client_ip[INET_ADDRSTRLEN];
	inet_ntop(client_addr.ss_family,
			get_in_addr((struct sockaddr *) &client_addr),
			client_ip, sizeof (client_ip));
	std::cout << "Got connection from " << client_ip << std::endl;

	return std::make_shared<Socket>(new_socket);
}

int ServerSocket::getServerSocket() {
	return server_socket_;
}


void ServerSocket::close() {
	::close(server_socket_);
	server_socket_ = -1;
}

void* ServerSocket::get_in_addr(sockaddr* sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

}
