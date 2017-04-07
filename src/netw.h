/*
	netw.h, rev 0.4, 07/04/2017 
	high level cross-platform network wrapper
    Copyright (C) 2017  pedro-javierf

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INC_NETW_H //Macro protection
#define INC_NETW_H


#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include "netwwin32.c"

#elif __linux__
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>//May not be needed
#include <unistd.h>
#include "netwlinux.c"

#endif



int initWinsock();
void stopWinsock();
int TCPSocketServer(unsigned short port);
int TCPSocketClient(const char* port, const char* serverName)
void socketClose(int socket);


#endif //End of macro protection