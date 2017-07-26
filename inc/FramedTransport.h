/* 
 * File:   FramedTransport.h
 * Author: hungcx
 *
 * Created on July 26, 2017, 11:09 AM
 */

#ifndef FRAMEDTRANSPORT_H
#define FRAMEDTRANSPORT_H

#include <memory>

#include "Socket.h"

namespace tcpserver {

class FramedTransport {
public:
	static const uint32_t FRAME_SIZE_LEN = 4;
	
	FramedTransport(const std::shared_ptr<Socket>& socket);
	virtual ~FramedTransport();
	
	bool readFrame(char* buff);
	bool writeFrame(const char* buff, uint32_t len);
	
	void setFrameSizeLen(int len);
private:
	std::shared_ptr<Socket> socket_;
	uint32_t frame_size_len_;
};

} // namespace tcpserver

#endif /* FRAMEDTRANSPORT_H */

