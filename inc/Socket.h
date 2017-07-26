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
	static const int DEFAULT_TIME_OUT = 5;
	
	Socket(const std::string& host, int port);
	Socket(const int socket);
	virtual ~Socket();
	
	uint32_t read(char* buff, uint32_t len);
	bool readAll(char* buff, uint32_t len);
	uint32_t write(const char* buff, uint32_t len);
	bool writeAll(const char* buff, uint32_t len);
	
	void open();
	void close();
	bool isOpen();
	
	int getSocket();
	void setSocket(int socket);
	
	void setTimeOut(int time_out);
private:
	std::string host_;
	int port_;
	int sockfd_;
	int time_out_;
	
	// Get sockaddr, IPv4 or IPv6
	void* get_in_addr(sockaddr* sa);
};

} // namespace tcpserver

#endif /* TCPSOCKET_H */

