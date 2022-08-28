#include "server.h"

// Function defination of server_select
int server_select(int maxval_fd, int server_sockfd, fd_set* readfds, fd_set* writefds)
{
	// Declaring the new server sock_fd and char buffer for storing the sending and recieving message
	int new_server_sockfd = 0;
	char recv_buff[MAX_BUFFER_SIZE];
	char send_buff[MAX_BUFFER_SIZE];

	// To fill the send and recv buffer with string input
	memset(recv_buff, 0, sizeof(recv_buff));
	memset(send_buff, 0, sizeof(send_buff));

	int select_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);  // select() system call 

	// Checking for the working of select() system call
	if (select_action == -1 || select_action == 0)
	{
		printf("*****ERROR : select()*****");
		exit(0);
	}

	// To check the fd is set so as to accept the new connection request
	if (FD_ISSET(server_sockfd, readfds))
	{
		// Then accecpt the new connection
		accept_new_connection(server_sockfd, &new_server_sockfd);
		printf("\t||-----------------------New socket created = %d--------------------------||\n", new_server_sockfd);
	}

	// To check the fd is set for sending the message so as to broadcast the message to all clients
	if (FD_ISSET(STDIN_FILENO, readfds))
	{
		// To check for message to be send
		if (read(0, send_buff, sizeof(send_buff)) > 0)
		{
			// Then fill the send_buff with message
			for (int val1 = 0; val1 < server.total_client; val1++)
			{
				server_send_to_client(server.client_list[val1].file_des, send_buff);
			}
		}
	}

	for (int val2 = 0; val2 < server.total_client; val2++)
	{
		// To check for all the clients in the file des inside the readfds
		if (FD_ISSET(server.client_list[val2].file_des, readfds))
		{
			// If its present in readfds then it will recieve the message
			server_recv_from_client(server.client_list[val2].file_des, recv_buff);
		}
	}
	return 0;
}
