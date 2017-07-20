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
#include <memory>
#include <thread>

#include "Socket.h"
#include "Protocol.h"

#define CLIENT_NUM 10
#define REQ_PER_CLIENT 100

/*
 * Simple C++ Test Suite
 */

using namespace tcpserver;

void aClient() {
	std::shared_ptr<Socket> client(new Socket("localhost", 3000));
	client->open();
	Protocol protocol(client);
	
	//std::this_thread::sleep_for(std::chrono::duration<int, std::ratio<1>>(rand() % 5));
	for(int i = 0; i < REQ_PER_CLIENT; i++) {
		char type = rand()% 3;
		protocol.writeType(type);
		switch (type) {
		case 0: {
			protocol.writeI32(1);
			
			int32_t response;
			protocol.readI32(response);
			if (response) std::cout << "GET SUCCESS\n";
			break;
		}
		case 1: {
			protocol.writeI32(1);
			protocol.writeI32(1);
			
			bool response;
			protocol.readBool(response);
			if (response) std::cout << "SET SUCCESS\n";
			break;
		}
		case 2: {
			protocol.writeI32(1);
			
			bool response;
			protocol.readBool(response);
			if (response) std::cout << "REMOVE SUCCESS\n";
			break;
		}
		}
	}
		
	client->close();
}

int main(int argc, char** argv) {
	std::thread clients[CLIENT_NUM];
	time_t begin = clock();
	for (int i = 0; i < CLIENT_NUM; i++) clients[i] = std::thread(aClient);
	for (auto& client : clients) client.join();
	time_t end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "--Performance: " << int(CLIENT_NUM * REQ_PER_CLIENT / time) << " requests per second\n";
	return 0;
}


