#include "server.h"

int setup_server(int port, int backlog)
{
	int opt_port = 1;
	int bind_check;
	int server_sockfd;
	
	struct sockaddr_in server_address;
	char server_responce[1024];
	
	socklen_t addr_size;
	addr_size = sizeof(server_responce);
	
	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd == -1)
	{
		printf("Error in creating the socket");
		return -1;
	}
	else
	{
		printf("-----Socket created successfully-----\n");
	}
	
	if(setsockopt(server_sockfd, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT), &opt_port , sizeof(opt_port)));  // Forcefully sets the socket port number	

	bzero(&server_address, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	// Checking for the address matching
	// if (INADDR_NONE == addr_size);
  	// {
    // 	perror("inet_addr() failed");
    // 	exit(1); /* or whatever error handling you choose. */
  	// }

	bind_check = bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
	if(bind_check == -1)
	{
		printf("Error in binding");
		return -1;
	}
	else
	{
		printf("--------Binding successfull--------\n");
		printf("The port is binded to : %d\n", PORT);
	}
	
	listen(server_sockfd, BACKLOG);

	return server_sockfd;
}	
