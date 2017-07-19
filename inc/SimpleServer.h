/* 
 * File:   SimpleServer.h
 * Author: xuanhungcao
 *
 * Created on July 19, 2017, 9:49 AM
 */

#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include "ServerSocket.h"
#include "Handler.h"
#include "Protocol.h"
#include "Processor.h"

namespace tcpserver {

class SimpleServer {
public:
	SimpleServer(int port);
	virtual ~SimpleServer();
	
	void run();
private:
	int port_;
};

}

#endif /* SIMPLESERVER_H */

