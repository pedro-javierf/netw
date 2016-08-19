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

void socketClose(int socket)
{
	close(socket);
}
