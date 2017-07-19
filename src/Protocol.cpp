/* 
 * File:   Protocol.cpp
 * Author: xuanhungcao
 * 
 * Created on July 18, 2017, 3:49 PM
 */

#include "Protocol.h"

namespace tcpserver {

Protocol::Protocol(const std::shared_ptr<Socket>& socket):
socket_(socket) {
}

Protocol::~Protocol() {
}

uint32_t Protocol::readType(char& type) {
	return socket_->read((char*)&type, 1);
}

uint32_t Protocol::readBool(bool& _bool) {
	return socket_->read((char*)&_bool, 1);
}

uint32_t Protocol::readI32(int32_t& inum) {
	return socket_->read((char*)&inum, 4);
}

uint32_t Protocol::readValue(Value& value) {
	return socket_->read((char*)&value.foo, 4);
}


uint32_t Protocol::writeType(char type) {
	return socket_->write((char*)&type, 1);
}

uint32_t Protocol::writeBool(bool _bool) {
	return socket_->write((char*)&_bool, 1);
}

uint32_t Protocol::writeI32(int32_t inum) {
	return socket_->write((char*)&inum, 4);
}

uint32_t Protocol::writeValue(const Value& value) {
	return socket_->write((char*)&value.foo, 4);
}

} // namespace tcpserver