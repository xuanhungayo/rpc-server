/* 
 * File:   Socket.h
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 3:26 PM
 */

#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>	
#include <netdb.h>
#include <string>

namespace tcpserver {

class Socket {
public:
	// Constructor
	Socket(const std::string& host, int port);
	Socket(const int socket);
	virtual ~Socket();
	
	// Read from the socket
	uint32_t read(char* buff, uint32_t len);
	// Write to the socket
	uint32_t write(const char* buff, uint32_t len);
	// Open a new socket
	void open();
	// Close the socket
	void close();
	// Check if there is an open socket
	bool isOpen();
	
	int getSocket();
	void setSocket(int socket);
protected:
	std::string host_;
	int port_;
	int sockfd_;
	
	// Get sockaddr, IPv4 or IPv6
	void* get_in_addr(sockaddr* sa);
};

} // namespace tcpserver

#endif /* TCPSOCKET_H */

