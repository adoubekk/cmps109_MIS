//Server.cpp
//Sequential Server for MIS client server model

#include "../TCP/headers/TCPServerSocket.h"
#include "../TCP/headers/TCPSocket.h"
#include "../MIS/MIS.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#define MAXSIZE 4096

using namespace std;

int main(){

	char data[MAXSIZE];
   char out[MAXSIZE] = "Hello from Server!";
   char err[MAXSIZE] = "I'm an error";

	TCPServerSocket* ServerSock = new TCPServerSocket("", 5532, 10);

	ServerSock->initializeSocket();

	TCPSocket* Sockelstiltskin = ServerSock->getConnection();

	Sockelstiltskin->readFromSocket(data, MAXSIZE);
   
   string src_name = "server_copy.mis";
   ofstream src_file;
   src_file.open(src_name);
   src_file << data;
   src_file.close();
   MIS* myMIS = new MIS();
   try {
      myMIS->makeParser(src_name);
   } catch (exception& e) {
      
   }
   myMIS->run();
   delete(myMIS);
   remove(src_name.c_str());
   
   Sockelstiltskin->writeToSocket(out, MAXSIZE);
   
   Sockelstiltskin->writeToSocket(err, MAXSIZE);
   
}