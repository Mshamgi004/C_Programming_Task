#include "client.h"

int main(int argc, char *argv[])
{	
	int client_sockfd = 0;   // Declaring the client_sockfd
	int maxval_fd = 0;    // A max sock_fd declared to hold the server_sockfd value
	
	// Declaring the read,write and except fd's for select()
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;

	// Toc check the name given from cmd in binary
	if(argc > 2)
	{
		printf("ERROR\n");
		exit(0);
	}
	else
	{
		// Copying the string in client_name typed in cmd
		strcpy(client_name,argv[1]);
	}

	if(setup_client(&client_sockfd) != 0)   // Function call for setting up of client
	{
		printf("Error : Socket creation failed");
		exit(1);
	}
	else
	{
		printf("-----Client socket created successfully----\n");
		//maxval_fd = client_sockfd;     // Equalising the max_fd to client_fd
	}
	maxval_fd = client_sockfd;     // Equalising the max_fd to client_fd
	
	while(1)
	{
		maxval_fd = client_build_fdsets(client_sockfd, &readfds, &writefds, &exceptfds);  // server_socket will build the fd_sets and will return the maxval_fd
		client_select(maxval_fd, client_sockfd, &readfds, &writefds);    // Function call for select()
	}
	
	close(client_sockfd);   // Closing the client_sockfd
	return 0;
}
