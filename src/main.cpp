/* 
 * File:   main.cpp
 * Author: xuanhungcao
 *
 * Created on July 17, 2017, 9:41 PM
 */

#include <iostream>

#include "ServerSocket.h"
#include "Socket.h"

using tcpserver::ServerSocket;
using tcpserver::Socket;

int main(int argc, char** argv) {
	ServerSocket ssocket(3000);
	ssocket.listen();
	while (1) {
		std::shared_ptr<Socket> transporter = ssocket.accept();
		char welcome[] = "Hi there";
		transporter->write(welcome, sizeof(welcome));
		
		char request[1024];
		transporter->read(request, 1024);
		std::cout << "Request from client: " << request	 << std::endl; 
	}
	return 0;
}

