/* 
 * File:   Socket.cpp
 * Author: xuanhungcao
 * 
 * Created on July 17, 2017, 3:26 PM
 */
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#include "config.h"
#include "Socket.h"

namespace tcpserver {

Socket::Socket(const std::string& host, int port) :
host_(host),
port_(port),
sockfd_(-1),
time_out_(DEFAULT_TIME_OUT) {
}

Socket::Socket(const int socket) :
sockfd_(socket) {
}

Socket::~Socket() {
	//close();
}

void Socket::open() {
	addrinfo hints, *addr0, *addr;
	int err;

	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((err = getaddrinfo(host_.c_str(), std::to_string(port_).c_str(), &hints, &addr0)) != 0) {
		std::cout << "Getaddrinfo: " << gai_strerror(err) << std::endl;
		return;
	}

	for (addr = addr0; addr != NULL; addr = addr->ai_next) {
		if ((sockfd_ = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd_, addr->ai_addr, addr->ai_addrlen) == -1) {
			close();
			perror("client: connect");
			continue;
		}
		break;
	}
	if (addr == NULL) {
		std::cout << "Error creating new socket!" << std::endl;
		freeaddrinfo(addr0);
		return;
	}

	timeval _timeval;
	_timeval.tv_sec = TIME_OUT;
	_timeval.tv_usec = 0;
	if (setsockopt(sockfd_, SOL_SOCKET, SO_RCVTIMEO, (const char*) &_timeval, sizeof (timeval)) == -1) {
		perror("client: setsockopt");
		freeaddrinfo(addr0);
		return;
	}

	char host[INET_ADDRSTRLEN];
	inet_ntop(addr->ai_family, get_in_addr((struct sockaddr*) addr->ai_addr),
			host, sizeof (host));
	std::cout << "Connected to " << host << std::endl;
	freeaddrinfo(addr0);

}

void Socket::close() {
	::close(sockfd_);
	sockfd_ = -1;
}

bool Socket::isOpen() {
	return sockfd_ != -1;
}

void Socket::setTimeOut(int time_out) {
	time_out_ = time_out;
}

uint32_t Socket::read(char* buff, uint32_t len) {
	int receive = recv(sockfd_, buff, len, 0);
	if (receive == -1) {
		perror("recv");
		return 0;
	}
	return receive;
}

bool Socket::readAll(char* buff, uint32_t len) {
	int total = 0;
	int byteleft = len;
	while (total < len) {
		int byte_read = recv(sockfd_, buff + total, byteleft, 0);
		if (byte_read == -1) perror("read");
		if (byte_read <= 0) break;
		total += byte_read;
		byteleft -= byte_read;
	}
	return total == len;
}

uint32_t Socket::write(const char* buff, uint32_t len) {
	int sent = send(sockfd_, buff, len, 0);
	if (sent <= 0) {
		perror("write");
		return 0;
	}
	return sent;
}

bool Socket::writeAll(const char* buff, uint32_t len) {
	int total = 0;
	int byteleft = len;
	while (total < len) {
		int byte_sent = send(sockfd_, buff + total, byteleft, 0);
		if (byte_sent == -1) perror("send");
		if (byte_sent <= 0) break;
		total += byte_sent;
		byteleft -= byte_sent;
	}
	return total == len;
}

int Socket::getSocket() {
	return sockfd_;
}

void Socket::setSocket(int socket) {
	sockfd_ = socket;
}

void* Socket::get_in_addr(sockaddr* sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

} // namespace tcpserver


