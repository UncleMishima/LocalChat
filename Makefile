chat: main.o getch.o Client.o Server.o chat.o
	g++ main.o getch.o Client.o Server.o chat.o -o chat -lpthread

main.o: main.cpp
	g++ -c main.cpp -o main.o

getch.o: getch.cpp
	g++ -c getch.cpp -o getch.o

Client.o: Client.cpp
	g++ -c Client.cpp -o Client.o

Server.o: Server.cpp
	g++ -c Server.cpp -o Server.o

chat.o: chat.cpp
	g++ -c chat.cpp -o chat.o -lpthread

clean