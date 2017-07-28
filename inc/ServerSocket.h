/* 
 * File:   ServerSocket.h
 * Author: xuanhungcao
 *
 * Created on July 18, 2017, 9:58 AM
 */

#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <memory>

#include "Socket.h"

namespace tcpserver {

class ServerSocket {
public:
	ServerSocket(int port);
	~ServerSocket();
	
	void listen();
	std::shared_ptr<Socket> accept();
	void close();
	int getServerSocket();
private:
	int port_;
	int server_socket_;
	const int BACKLOG = 10;
	
	// Get sockaddr, IPv4 or IPv6
	void* get_in_addr(sockaddr* sa);
};

}

#endif /* SERVERSOCKET_H */

