/* 
 * File:   Processor.cpp
 * Author: xuanhungcao
 * 
 * Created on July 19, 2017, 11:14 AM
 */

#include "Processor.h"

namespace tcpserver {

Processor::Processor(const std::shared_ptr<Protocol>& protocol, const std::shared_ptr<Handler>& handler) :
protocol_(protocol),
handler_(handler) {
}

Processor::~Processor() {
}

bool Processor::handleRequest() {
	char type;
	if (protocol_->readType(type) == 0) {
		return 0;
	}
	
	switch (type) {

	case 0: // Get
	{ 
		int32_t key;
		protocol_->readI32(key);
		Value value = handler_->get(key);
		protocol_->writeValue(value);
		break;
	}

	case 1: // Set
	{ 
		int32_t key; Value value;
		protocol_->readI32(key);
		protocol_->readValue(value);
		protocol_->writeBool(handler_->set(key, value));
		break;
	}

	case 2: // Remove 
	{
		int32_t key;
		protocol_->readI32(key);
		protocol_->writeBool(handler_->remove(key));
	}
	
	}
	
	return 1;
}

} // namespace tcpserver
