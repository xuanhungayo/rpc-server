/* 
 * File:   Handler.h
 * Author: xuanhungcao
 *
 * Created on July 19, 2017, 9:55 AM
 */

#ifndef HANDLER_H
#define HANDLER_H

#include "Types.h"

namespace tcpserver {

class Handler {
public:
	Handler();
	virtual ~Handler();
	
	Value get(const int32_t key);
	bool set(const int32_t key, const Value& value);
	bool remove(const int32_t key);
private:

};

} // namespace tcpserver

#endif /* HANDLER_H */

