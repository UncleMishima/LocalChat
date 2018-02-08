#include <pthread.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "chat.h"
#include "getch.h"

void* readFunc(void *pSock){
	int sock = *(int*)pSock;
	char ch;
	while(recv(sock, &ch, 1 , 0)>0){
		printf("%c", ch);
		fflush(stdout);
	}
	return 0;
}

void* writeFunc(void *pSock){
	int sock = *(int*)pSock;
	char ch;
	do{
		ch=getch();
		printf("%c", ch);
		fflush(stdout);
	}while(send(sock, &ch, 1, 0)>0);
}

void _chat(int sock){
	int status_addr;
	pthread_t ptread, ptwrite;
	
	pthread_create(&ptread, NULL, readFunc, (void*) &sock );
	pthread_create(&ptwrite, NULL, writeFunc, (void*)&sock);
	
	pthread_join(ptread, (void**)&status_addr);
	pthread_join(ptwrite, (void**)&status_addr);
	
	return;
}
