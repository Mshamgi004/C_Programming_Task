#include "client.h"

// Function defination for client_build_fdsets
int client_build_fdsets(int client_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds) 
{
	int maxval_fd = client_sockfd;   // Keeping the value of client_sockfd = maxval_fd

	FD_ZERO(readfds);     // Initializing readfds with zero value
	FD_SET(client_sockfd, readfds);    // Setting the client_sockfd as readfds
	FD_SET(client_sockfd, writefds);   // Setting the writefds to 0 so as to recive the commands from cmd
	FD_SET(STDIN_FILENO,readfds);   // Setting the readfds to 0 so as to recive the commands from cmd
	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);   // fcntl() used to nonblocking the application from the cmd 

	return maxval_fd;
}
