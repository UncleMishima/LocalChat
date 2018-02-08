#include <stdio.h>

#include "Server.h"
#include "chat.h"

Server::Server(int port){
	listener = socket(AF_INET, SOCK_STREAM, 0);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);
}

void Server::start(){

	bind(listener,(struct sockaddr *)&server , sizeof(server));

	int c = sizeof(struct sockaddr_in);

	listen(listener, 1);

	sock = accept(listener, (struct sockaddr *)&client, (socklen_t*)&c);
	if(sock>0){
		printf("Client connect ok.\n");
		_chat(sock);
	}
	else printf("Client can't connect.\n");
}
