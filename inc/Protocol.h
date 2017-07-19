/* 
 * File:   Protocol.h
 * Author: xuanhungcao
 *
 * Created on July 18, 2017, 3:49 PM
 */

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <memory>

#include "Types.h"
#include "Handler.h"
#include "Socket.h"

namespace tcpserver {

class Protocol {
public:
	Protocol(const std::shared_ptr<Socket>& socket);
	virtual ~Protocol();
	
	uint32_t readType(char& type);
	uint32_t readBool(bool& _bool);
	uint32_t readI32(int32_t& inum);
	uint32_t readValue(Value& value);

	uint32_t writeType(char type);
	uint32_t writeBool(bool _bool);
	uint32_t writeI32(int32_t inum);
	uint32_t writeValue(const Value& value);
private:
	std::shared_ptr<Socket> socket_;
};

} // namespace tcpserver

#endif /* PROTOCOL_H */

