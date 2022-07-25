#include "client.h"

int client_select(int maxval_fd, int client_sockfd,fd_set *readfds,fd_set *writefds)
{
	char recv_msg[MAX_BUFFER_SIZE];
	char send_msg[MAX_BUFFER_SIZE];

	bzero(recv_msg,sizeof(recv_msg));
	bzero(send_msg,sizeof(send_msg));

	int client_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);
	if(client_action == -1 || client_action == 0)
	{
		printf("ERROR: select");
		exit(1);
	}

	if(FD_ISSET(client_sockfd, readfds))
	{
		client_recv_from_server(client_sockfd, recv_msg);	
	}

	if(FD_ISSET(STDIN_FILENO,readfds))
	{
		if(read(0,send_msg,sizeof(send_msg)) > 0)
		{
			client_send_to_server(client_sockfd,send_msg);
		}
	}
	return 0;
}
