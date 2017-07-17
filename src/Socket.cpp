/* 
 * File:   Socket.cpp
 * Author: xuanhungcao
 * 
 * Created on July 17, 2017, 3:26 PM
 */
#include <cstring>
#include <iostream>
#include <sys/socket.h>	
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include "Socket.h"

namespace tcpserver {

Socket::Socket(const std::string& host, int port):
host_(host),
port_(port) {
}

Socket::~Socket() {
	close();
}

void Socket::open() {
	addrinfo hints, *addr0, *addr;
	int err;
	
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	if ((err = getaddrinfo(host_.c_str(), std::to_string(port_).c_str(), &hints, &addr0)) != 0) {
		std::cout << "getaddrinfo: " << gai_strerror(err) << std::endl;
		return;
	}
	
	for (addr = addr0; addr != NULL; addr = addr->ai_next) {
		if ((sockfd_ = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1)
			continue;
		break;
	}
	freeaddrinfo(addr0);
	if (sockfd_ == -1) std::cout << "error creating new socket!" << std::endl;
	else {
		char peer_host[INET_ADDRSTRLEN];
		inet_ntop(addr->ai_family, get_in_addr(addr->ai_addr), peer_host, sizeof(peer_host));
	}
}

void Socket::close() {
	close(sockfd_);
	sockfd_ = -1;
}

bool Socket::isOpen() {
	return sockfd_ != -1;
}

uint32_t Socket::read(void* buff, uint32_t len) {
	return recv(sockfd_, buff, len, 0);
}

void Socket::write(const void* buff, uint32_t len) {
	send(sockfd_, buff, len, 0);
}

void* Socket::get_in_addr(sockaddr* sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

} // namespace tcpserver


