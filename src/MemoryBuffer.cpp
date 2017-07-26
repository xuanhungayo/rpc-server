/* 
 * File:   MemoryBuffer.cpp
 * Author: hungcx
 * 
 * Created on July 26, 2017, 3:08 PM
 */

#include <cstring>

#include "MemoryBuffer.h"

namespace tcpserver {

MemoryBuffer::MemoryBuffer():
buf_size_(DEFAULT_SIZE) {
	init();
}

MemoryBuffer::MemoryBuffer(uint32_t sz):
buf_size_(sz) {
	init();
}

void MemoryBuffer::init() {
	buf_begin_ = (char*) malloc(buf_size_);
	buf_end_ = buf_begin_ + buf_size_;
	
	read_pos_ = buf_begin_;
	write_pos_ = buf_begin_;
}

uint32_t MemoryBuffer::availableRead() {
	return (write_pos_ - read_pos_);
}

bool MemoryBuffer::read(char* buf, uint32_t len) {
	if (len > availableRead()) return false;
	memcpy(buf, read_pos_, len);
	read_pos_ += len;
	return true;
}

bool MemoryBuffer::ensureCanWrite(uint32_t len) {
	if (len <= buf_end_ - write_pos_) return true;
	buf_size_ *= 2;
	
	char* new_buffer = (char*) realloc(buf_begin_, buf_size_);
	read_pos_ = new_buffer + (read_pos_ - buf_begin_);
	write_pos_ = new_buffer + (write_pos_ - buf_begin_);
	buf_begin_ = new_buffer;
	buf_end_ = buf_begin_ + buf_size_;
	return 1;
}

bool MemoryBuffer::write(const char* buf, uint32_t len) {
	if (!ensureCanWrite(len)) return false;
	memcpy(write_pos_, buf, len);
	return true;
}

MemoryBuffer::~MemoryBuffer() {
	free(buf_begin_);
}

} // namespace tcpserver

