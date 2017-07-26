/* 
 * File:   FramedTransport.cpp
 * Author: hungcx
 * 
 * Created on July 26, 2017, 11:10 AM
 */

#include "FramedTransport.h"

namespace tcpserver {

FramedTransport::FramedTransport(const std::shared_ptr<Socket>& socket):
socket_(socket) {
}

FramedTransport::~FramedTransport() {
}

void FramedTransport::setFrameSizeLen(int len) {
	frame_size_len_ = len;
}

bool FramedTransport::readFrame(char* buff) {
	int32_t frame_size;
	if (!socket_->readAll((char*) &frame_size, frame_size_len_)) 
		return false;
	if (!socket_-> readAll(buff, frame_size))
		return false;
	return true;
}

bool FramedTransport::writeFrame(const char* buff, uint32_t len) {
	if (!socket_->writeAll((char*) &len, frame_size_len_));
		return false;
	if (!socket_->writeAll(buff, len)) 
		return false;
	return true;
}

} // namespace tcpserver

