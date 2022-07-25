#include "server.h"

int server_select(int maxval_fd, int server_sockfd, fd_set *readfds, fd_set *writefds)
{
	int new_server_sockfd = 0;
	char recv_msg[MAX_BUFFER_SIZE];
	char send_msg[MAX_BUFFER_SIZE];
	bzero(recv_msg, sizeof(recv_msg));
	bzero(send_msg, sizeof(send_msg));

	int select_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);

	if(select_action == -1 || select_action == 0)
	{
		printf("Error in select");
		exit(1);
	} 

	// To check the server_sockfd
	if(FD_ISSET(server_sockfd,readfds))
	{
		accept_new_connection(server_sockfd, &new_server_sockfd);
		printf("New socket created = %d\n", new_server_sockfd);
	}

	if(FD_ISSET(STDIN_FILENO, readfds))
	{
		if(read(0, send_msg, sizeof(send_msg)) > 0)
		{
			for(int val = 0; val < server.total_client; val++)
			{
				send_to_client(server.client_list[val].file_des, send_msg);
			}
		}	
	}
	for(int val1 = 0; val1 < server.total_client; val1++)
	{
		if(FD_ISSET(server.client_list[val1].file_des,readfds))
		{
			recv_from_client(server.client_list[val1].file_des, recv_msg);
		}
	}
	return 0;
	
}
