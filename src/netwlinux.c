int TCPSocketServer(unsigned short port)
{
	if (port==0 || port >=65535){
		return -1;
		}
		
	int socket_desc;
    struct sockaddr_in server;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
		return -1;
    }
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        return -1;
    }
     
    //Listen
    listen(socket_desc , 3);
	return socket_desc;

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

	memset(&hints, 0, sizeof(hints));
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
	
	if (ConnectSocket == INVALID_SOCKET) {
        return -4;
    }

	
	return ConnectSocket;
}


void socketClose(int socket)
{
	close(socket);
}
