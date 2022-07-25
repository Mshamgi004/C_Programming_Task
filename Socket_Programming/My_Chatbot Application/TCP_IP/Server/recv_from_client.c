#include "server.h"

void recv_from_client(int client_socket, char *recv_msg)
{
	int read_bytes = 0;
	bzero(recv_msg,strlen(recv_msg));

	if((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0 )) > 0)
	{
		printf("Server is ready to recieve message \n");
	}
	else
	{	
		printf("Error in recieveing the message\n");
	}
}	
