/* 
 * File:   Socket.cpp
 * Author: xuanhungcao
 * 
 * Created on July 17, 2017, 3:26 PM
 */
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Socket.h"

namespace tcpserver {

Socket::Socket(const std::string& host, int port):
host_(host),
port_(port),
sockfd_(-1) {
}

Socket::Socket(const int socket):
sockfd_(socket) {
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
		std::cout << "Getaddrinfo: " << gai_strerror(err) << std::endl;
		return;
	}
	
	for (addr = addr0; addr != NULL; addr = addr->ai_next) {
		if ((sockfd_ = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1)
			continue;
		if (connect(sockfd_, addr->ai_addr, addr->ai_addrlen) == -1 ) {
			close();
			continue;
		}
		break;
	}
	if (sockfd_ == -1) {
		std::cout << "Error creating new socket!" << std::endl;
		return;
	}
	char host[INET_ADDRSTRLEN];
	inet_ntop(addr->ai_family, get_in_addr((struct sockaddr *)addr->ai_addr),
            host, sizeof(host));
	std::cout << "Connected to " << host << std::endl;
}

void Socket::close() {
	::close(sockfd_);
	sockfd_ = -1;
}

bool Socket::isOpen() {
	return sockfd_ != -1;
}

uint32_t Socket::read(char* buff, uint32_t len) {
	return recv(sockfd_, buff, len, 0);
}

uint32_t Socket::write(const char* buff, uint32_t len) {
	int total = 0;
	int byteleft = len;
	while (total < len) {
		int byte_sent = send(sockfd_, buff + total, byteleft, 0);
		if (byte_sent <= 0) 
			break;
		total += byte_sent;
		byteleft -= byte_sent;
	}
	return total;
}

void* Socket::get_in_addr(sockaddr* sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

} // namespace tcpserver


