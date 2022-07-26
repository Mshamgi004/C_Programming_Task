#include "server.h"

// Function defination of server_select
int server_select(int maxval_fd, int server_sockfd, fd_set *readfds, fd_set *writefds)
{
	// Dclaring the new server sock_fd and char buffer for storing the sending and recieving message
	int new_server_sockfd = 0;
	char recv_msg[MAX_BUFFER_SIZE];
	char send_msg[MAX_BUFFER_SIZE];
	// Clearing the buffer initially to zero
	memset(recv_msg, 0, sizeof(recv_msg));
	memset(send_msg, 0 , sizeof(send_msg));

	int select_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);  // select() system call 
	
	// Checking for the working of select() system call
	if(select_action == -1 || select_action == 0)
	{
		printf("Error in select");
		exit(0);
	} 
	else
	{
		printf("Not able to select()\n");
	}
	// To check the fd is set so as to accept the new connetcion request
	if(FD_ISSET(server_sockfd,readfds))
	{
		accept_new_connection(server_sockfd, &new_server_sockfd);
		printf("New socket created = %d\n", new_server_sockfd);
	}
	else
	{
		printf("Not able to accept the new connection\n");
	}

	// To check the fd is set for sending the message so as to broadcast the message to all clients
	if(FD_ISSET(0, readfds))
	{
		if(read(0, send_msg, sizeof(send_msg)) > 0)
		{
			for(int val = 0; val < server.total_client; val++)
			{
				send_to_client(server.client_list[val].file_des, send_msg);
			}
		}	
	}
	else
	{
		printf("Not able to send message to client\n");
	}

	for(int val1 = 0; val1 < server.total_client; val1++)
	{
		// To check for all the clients in the file des inside the readfds
		if(FD_ISSET(server.client_list[val1].file_des,readfds))
		{	
			// If its present in readfds then it will recieve the message
			recv_from_client(server.client_list[val1].file_des, recv_msg);
		}
		else
		{
			printf("Not able to recieve the message from client \n");
		}

	}
		
	return 0;
	
}
