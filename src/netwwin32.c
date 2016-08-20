void stopWinsock()
{
	WSACleanup();
}

//Starts winsock API so we could use functions such as recv() send() etc..
int initWinsock()
{
	int error;
	WSAData wsaData;

	if ((error = WSAStartup(MAKEWORD(2, 2), &wsaData)) == SOCKET_ERROR) {
		return -1;
	}
	 
	return 0;

}
//Creates, binds and sends to listen a new TCP socket on the specified port
int TCPSocketServer(unsigned short port)
{
	if (port==0 || port >=65535){
		return -1;
		}

	// Create my socket
	int mySocket = socket(AF_INET, SOCK_STREAM, 0);

	// Make sure nothing bad happened
	if (mySocket == SOCKET_ERROR)
	{
		return -1;
	}

	// The address structure
	struct sockaddr_in server;

	// Fill the address structure with appropriate data
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = INADDR_ANY;

	// And now bind my socket
	if (bind(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		closesocket(mySocket);
		Sleep(5000);
		return -1;
	}

		// Mark my socket for listening
	if (listen(mySocket, 5) == SOCKET_ERROR)
	{
		closesocket(mySocket);
		Sleep(5000);
		return -1;

	}

	return mySocket;
	
	
}

int TCPSocketClient(const char* port, const char* serverName)
{
	
	// An error code we will use to get more information about our errors
	int error, iResult;

	// Create my socket
	int ConnectSocket;
	
	struct addrinfo *result = NULL,	*ptr = NULL;
	struct addrinfo hints;
	
	DWORD dwRetval;

	SecureZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
	
	//Get server info
	dwRetval = getaddrinfo(serverName,port,&hints,&result);
	
	if ( dwRetval != 0 ) {
		return -2;
    }

	
	// Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET)
		{
            return -3;
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
			
            continue;//Jumps to next iteration
        }
        break;
    }
	
	freeaddrinfo(result);

	return ConnectSocket;
}


//Will close and deallocate a socket and it's memory
void socketClose(int socket)
{

	closesocket(socket);

}
