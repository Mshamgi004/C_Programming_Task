#include "server.h"

int server_build_fdsets(int server_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds)
{
	int maxval_fd = server_sockfd;

	FD_ZERO(readfds);
	FD_SET(server_sockfd, readfds);
	FD_SET(STDIN_FILENO, readfds);
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

	for(int i = 0; i < server.total_client; i++)
	{
		FD_SET(server.client_list[i].file_des, readfds);
		maxval_fd++;
	}
	return maxval_fd;
}
