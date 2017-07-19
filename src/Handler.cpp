/* 
 * File:   Handler.cpp
 * Author: xuanhungcao
 * 
 * Created on July 19, 2017, 9:55 AM
 */

#include <iostream>

#include "Handler.h"

namespace tcpserver {

Handler::Handler() {
}

Handler::~Handler() {
}

Value Handler::get(const int32_t key) {
	std::cout << "GET" << std::endl;
	return Value(1);
}

bool Handler::set(const int32_t key, const Value& value) {
	std::cout << "SET" << std::endl;
	return 1;
}

bool Handler::remove(const int32_t key) {
	std::cout << "REMOVE" << std::endl;
	return 1;
}

}

