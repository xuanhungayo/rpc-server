/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: cpu10170-local
 *
 * Created on July 17, 2017, 6:22 PM
 */

#include <stdlib.h>
#include <iostream>

#include "Socket.h"
/*
 * Simple C++ Test Suite
 */

using tcpserver::Socket;

void ClientTest() {
	Socket socket("localhost", 8585);
	socket.open();
	socket.read()
}

int main(int argc, char** argv) {
	ClientTest();

	return (EXIT_SUCCESS);
}

