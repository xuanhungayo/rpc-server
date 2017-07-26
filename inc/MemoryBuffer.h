/* 
 * File:   MemoryBuffer.h
 * Author: hungcx
 *
 * Created on July 26, 2017, 3:07 PM
 */

#ifndef MEMORYBUFFER_H
#define MEMORYBUFFER_H

#include <cstdlib>
#include <cstdint>

namespace tcpserver {

class MemoryBuffer {
public:
	static const int DEFAULT_SIZE = 1024 * 1024;
	static const int MAX_SIZE = 64 * 1024 * 1024;
	
	MemoryBuffer();
	MemoryBuffer(uint32_t sz);
	virtual ~MemoryBuffer();
	
	uint32_t availableRead();
	
	bool read(char* buf, uint32_t len);
	bool write(const char* buf, uint32_t len);
private:
	void init();
	bool ensureCanWrite(uint32_t len);
	
	uint32_t buf_size_;
	char* buf_begin_;
	char* buf_end_;
	char* read_pos_;
	char* write_pos_;
};

} // namespace tcpserver

#endif /* MEMORYBUFFER_H */

