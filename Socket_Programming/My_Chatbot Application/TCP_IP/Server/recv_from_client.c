#include "server.h"

// Function defination for recieving the name from client
int recv_from_client(int client_socket, char *recv_msg)
{
	int read_bytes = 0;    // Variable use to store the read_bytes
	memset(recv_msg,0,strlen(recv_msg));     // Clearing the buffer initially

	// recv() function used to recieve the name of client
	if((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0 )) > 0)
	{ 
		printf("Server is ready to recieve the name \n");
	}
	else
	{	
		printf("Error in recieveing the name \n");
	}
	return 0;
}	
