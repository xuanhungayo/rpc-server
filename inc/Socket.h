/* 
 * File:   Socket.h
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 3:26 PM
 */

#ifndef SOCKET_H
#define SOCKET_H

#include <string>

namespace tcpserver {

class Socket {
public:
	// Constructor
	Socket(const std::string& host, int port);
	virtual ~Socket();
	
	// Read from the socket
	virtual uint32_t read(void* buff, uint32_t len);
	// Write to the socket
	virtual void write(const void* buff, uint32_t len);
	// Open a new socket
	void open();
	// Close the socket
	void close();
	bool isOpen();
protected:
	std::string host_;
	int port_;
	int sockfd_ = -1;
};

} // namespace tcpserver

#endif /* TCPSOCKET_H */

