/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xuanhungayo
 *
 * Created on July 17, 2017, 9:41 PM
 */

#include <iostream>

#include "Socket.h"

using tcpserver::Socket;

int main(int argc, char** argv) {
	Socket socket("localhost", 3490);
	socket.open();
	char s[13];
	socket.read(s, 13);
	std::cout << s << std::endl;
	
	socket.close();
	return 0;
}

