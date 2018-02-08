#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>

class Server{
private:
	int listener, sock;
	struct sockaddr_in server, client;
public:
	Server(int port);
	void start();
};
