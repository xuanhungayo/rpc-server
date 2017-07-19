/* 
 * File:   Types.h
 * Author: xuanhungcao
 *
 * Created on July 19, 2017, 10:09 AM
 */

#ifndef TYPES_H
#define TYPES_H

#define TYPE_SIZE 1
#define VALUE_SIZE 4

#include <stdint.h>

struct Value {
	int32_t foo;
	Value() {}
	Value(int32_t _foo): foo(_foo) {}
};

#endif /* TYPES_H */

