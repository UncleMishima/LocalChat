#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "getch.h"
#include "Server.h"
#include "Client.h"

int main(){

	char ch, buff[50]={};
	Client client(8888);
	Server server(8888);

	printf(	"Press 'i' to connect to server.\n"
			"Press 's' to start server.\n");
	
	do ch=getch(); while((ch!='i') && (ch !='s'));

	switch(ch){
		case'i':
			printf("input ip:");
			scanf("%s", buff);
			if(!client.con(buff))
				printf("Can't connect to server.\n");
			else
				client.chat();
			break;
		case's':
			server.start();
			break;
	}

	printf("Press any key to exit...");
	getch();
}
