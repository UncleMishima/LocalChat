#include "Client.h"

#include "chat.h"

Client::Client(int port){
	sock = socket(AF_INET, SOCK_STREAM, 0);
	server.sin_port = htons(port);
	server.sin_family = AF_INET;
}

bool Client::con(const char* ip){
	server.sin_addr.s_addr = inet_addr(ip);
	return !(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0);
}

void Client::chat(){
	_chat(sock);
}
