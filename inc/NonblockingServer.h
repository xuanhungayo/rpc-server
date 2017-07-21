/* 
 * File:   NonblockingServer.h
 * Author: xuanhungcao
 *
 * Created on July 21, 2017, 10:59 AM
 */

#ifndef NONBLOCKINGSERVER_H
#define NONBLOCKINGSERVER_H

#include <memory> 
#include <thread>
#include <sys/epoll.h>

#include "ServerSocket.h"
#include "Handler.h"
#include "Protocol.h"
#include "Processor.h"
#include "config.h"

namespace tcpserver {

class NonblockingServer {
public:
	NonblockingServer(int port);
	virtual ~NonblockingServer();
	
	void run();
private:
	int port_;
	int epoll_fd_;
	
	void addEvent(std::shared_ptr<Socket> socket);
	void IOThread();
};

} // namespace tcpserver

#endif /* NONBLOCKINGSERVER_H */

