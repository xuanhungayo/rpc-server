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
#include "MemoryBuffer.h"
#include "FramedTransport.h"
#include "config.h"

namespace tcpserver {

// TODO
class NonblockingServer;

class IOThread {
public:
	IOThread(NonblockingServer* server);
	virtual ~IOThread();
	
	void run();
private:
	int epoll_fd_;
	NonblockingServer* server_;
	
	void registerEvent(int socket);
};

class WorkersManager {
	
};

class NonblockingServer {
public:
	
	
	NonblockingServer(int port);
	virtual ~NonblockingServer();

	void run();
private:
	friend class IOThread;
	friend class WorkersManager;
	
	int port_;
	
	IOThread io_thread_;
	
	MemoryBuffer in_buffer_;
	MemoryBuffer out_buffer_;
};

} // namespace tcpserver

#endif /* NONBLOCKINGSERVER_H */

