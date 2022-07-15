#include "server.h"

int accept_new_connection(int server_sockfd)
{	
	int client_sockfd;
	
	struct sockaddr client_address;
	
	socklen_t addr_size;
	addr_size = sizeof(client_address);
	
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &addr_size);
	if(client_sockfd == -1)
	{
		printf("Error in accepting the message\n");
		return -1;
	}
	else
	{
		printf("--------Server socket ready to accept the messages-------\n");
	}
	return client_sockfd;
}
