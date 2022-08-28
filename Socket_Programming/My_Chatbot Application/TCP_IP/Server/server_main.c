#include "server.h"

int main()
{	
    // fd_set for reading, writing and exception for socket fd
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
    int server_sockfd;

	int maxval_fd = 0;   // A max sock_fd declared to hold the server_sockfd value

	memset(&server, 0, sizeof(struct server_data));   // Clearing the structure to hold the total clients
	printf("\t||---------------------------SERVER STARTED-------------------------------||\n");
	printf("\t||************************************************************************||\n");
	

	if (setup_server(&server_sockfd) != 0)   // Function call for setting up of server
	{
		printf("*****ERROR : Creation socket failed******");
		exit(0);
	}
	else
	{
		maxval_fd = server_sockfd;   // Equalising the max_fd to server_fd
	}

	while (1)
	{
		maxval_fd = server_build_fdsets(server_sockfd, &readfds, &writefds, &exceptfds);   // server_socket will build the fd_sets and will return the maxval_fd 
		server_select(maxval_fd, server_sockfd, &readfds, &writefds);     // Function call for select()
	}

	cleanup();
	printf("Bye From server\n");

	return 0;
}
