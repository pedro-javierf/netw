#ifndef INC_NETW_H
#define INC_NETW_H


#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include "netwwin32.cpp"

#else
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>//May not be needed
#include <unistd.h>
#include "netwlinux.cpp"

#endif



int initWinsock();
void stopWinsock();
int TCPSocketServer(unsigned short port);
int TCPSocketClient(unsigned short port, const char* serverName);
void socketClose(int socket);


#endif