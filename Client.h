#pragma once

#include <sys/socket.h>
#include <arpa/inet.h>

class Client{
private:
	int sock;
	struct sockaddr_in server;
public:
	Client(int port);
	bool con(const char* ip);
	void chat();
};
