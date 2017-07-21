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
	std::cout << "GET " << key << std::endl;
	return Value(key);
}

bool Handler::set(const int32_t key, const Value& value) {
	std::cout << "SET " << key << std::endl;
	return key % 2;
}

bool Handler::remove(const int32_t key) {
	std::cout << "REMOVE " << key << std::endl;
	return key % 2;
}

}

