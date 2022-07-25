#include "server.h"


int main()
{	
	
	int server_sockfd, new_server_sockfd;
	char client_name[32];
	char recv_msg[1024];
	char send_msg[1024];
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
	int maxval_fd = 0;

	bzero(&server,sizeof(struct server_data));
	printf("-------SERVER STARTED!!!------\n");
	
	// Socket server function call
	setup_server(&server_sockfd);

	maxval_fd = server_sockfd;
	
	//accept_new_connection(server_sockfd,new_server_sockfd);
	while(1)
	{	
		maxval_fd = server_build_fdsets(server_sockfd, &readfds, &writefds, &exceptfds);
		server_select(maxval_fd, server_sockfd, &readfds, &writefds);
	}
	printf("END OF APPLICATION -> SERVER\n");
	
	return 0;
}
