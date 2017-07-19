/* 
 * File:   Processor.h
 * Author: xuanhungcao
 *
 * Created on July 19, 2017, 11:14 AM
 */

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <memory>

#include "Protocol.h"
#include "Handler.h"

namespace tcpserver {

class Processor {
public:
	Processor(const std::shared_ptr<Protocol>& protocol, const std::shared_ptr<Handler>& handler);
	virtual ~Processor();
	
	bool handleRequest();
private:
	std::shared_ptr<Protocol> protocol_;
	std::shared_ptr<Handler> handler_;
};

} // namespace tcpserver

#endif /* PROCESSOR_H */

