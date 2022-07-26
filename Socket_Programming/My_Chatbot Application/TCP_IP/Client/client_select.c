#include "client.h"

// Function declaration for client_select
int client_select(int maxval_fd, int client_sockfd,fd_set *readfds,fd_set *writefds)
{
	// Declaring the char buffer for storing the sending and recieving message
	char recv_msg[MAX_BUFFER_SIZE];    
	char send_msg[MAX_BUFFER_SIZE];
	// Clearing the buffer initially to zero
	memset(recv_msg,0,sizeof(recv_msg));
	memset(send_msg,0,sizeof(send_msg));

	int client_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);  // select() system call 
	if(client_action == -1 || client_action == 0)
	{
		printf("ERROR: select");
		exit(1);
	}

	// To check for all the clients in the file des inside the readfds
	if(FD_ISSET(client_sockfd, readfds))
	{
		// If its present in readfds then it will recieve the message
		client_recv_from_server(client_sockfd, recv_msg);	
	}
	else
	{
		printf("Not able to recv the message\n");
	}

	// To check the fd is set for sending the message so as to broadcast the message to all clients
	if(FD_ISSET(0,readfds))
	{

		if(read(0,send_msg,sizeof(send_msg)) > 0)
		{
			client_send_to_server(client_sockfd,send_msg);
		}
		else
		{
			printf("Not able to send the message\n");
		}
	}
	else
	{
		printf("ERROR: in setting the readfds\n");
	}
	
	return 0;
}

