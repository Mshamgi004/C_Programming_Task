#include "client.h"

int server_build_fdsets(int client_sockfd,fd_set *readfds,fd_set *writefds,fd_set *exceptfds)
{
	int maxval_fd = client_sockfd;

	FD_ZERO(readfds);
	FD_SET(client_sockfd, readfds);
	FD_SET(client_sockfd, writefds);
	FD_SET(STDIN_FILENO, readfds);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

	return maxval_fd;
}
