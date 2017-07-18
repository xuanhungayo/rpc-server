/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   client.cpp
 * Author: cpu10170-local
 *
 * Created on July 18, 2017, 1:49 PM
 */

#include <stdlib.h>
#include <iostream>

#include "Socket.h"

/*
 * Simple C++ Test Suite
 */

using tcpserver::Socket;

int main(int argc, char** argv) {
	Socket client("localhost", 3000);
	client.open();
	for(int i = 1; i <= 10000000; i++);
	char response[1024];
	client.read(response, 1024);
	std::cout << "Server response: " << response << std::endl; 
	
	char request[] = "Money";
	client.write(request, sizeof(request));
}

