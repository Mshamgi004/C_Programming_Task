#include "client.h"

int main()
{	
	int client_sockfd;
	int new_socket = 0;
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
	int maxval_fd = 0;
	
	if(setup_client(&client_sockfd) != 0)
	{
		printf("Error : Socket creation failed");
		exit(1);
	}
	else
	{
		printf("-----Client socket created successfully----\n");
	}
	maxval_fd = client_sockfd;
	
	while(1)
	{
		maxval_fd = server_build_fdsets(client_sockfd, &readfds, &writefds, &exceptfds);
		client_select(maxval_fd, client_sockfd, &readfds, &writefds);
	}
	
	close(client_sockfd);
	return 0;
}
