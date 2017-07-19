/* 
 * File:   ThreadedServer.h
 * Author: xuanhungcao
 *
 * Created on July 19, 2017, 5:01 PM
 */

#ifndef THREADEDSERVER_H
#define THREADEDSERVER_H

#include <memory>

#include "Socket.h"
#include "Handler.h"

namespace tcpserver {

class ThreadedServer {
public:
	ThreadedServer(const int port);
	virtual ~ThreadedServer();
	
	void run();
private:
	int port_;
	std::shared_ptr<Handler> handler_;
	
	void process(std::shared_ptr<Socket> trans);
};

} // namespace tcpserver

#endif /* THREADEDSERVER_H */

