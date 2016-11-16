#include "../headers/TCPSocket.h"
#include "../headers/TCPServerSocket.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	char buffer[1024];

	TCPServerSocket* ServerSock = new TCPServerSocket("127.0.0.1", 5532, 10);

	ServerSock->initializeSocket();

	TCPSocket* Sock1 = ServerSock->getConnection();

	Sock1->readFromSocket(buffer, 1024);

	for(int i= 0; i < 10; i++){
		cout << buffer[i] << endl;
	}

}