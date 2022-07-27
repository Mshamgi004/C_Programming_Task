#include "server.h"

// Function defination of server_build_fdsets
int server_build_fdsets(int server_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds) 
{
	int maxval_fd = server_sockfd;   // Keeping the value of server_sockfd = maxval_fd

	FD_ZERO(readfds);  //Initializing readfds with zero value
	FD_SET(server_sockfd, readfds);  // Setting the server_sockfd as readfds
	FD_SET(STDIN_FILENO,readfds);   // Setting the readfds to a 0 value so as to capture in readfdsq
	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);   // fcntl() used to nonblocking the application from the cmd 
	
	// Loop use to fill the readfds with all the socket fd's 
	for(int val = 0; val < server.total_client; val++) 
	{
        FD_SET(server.client_list[val].file_des,readfds);
        maxval_fd++;
    }
    return maxval_fd;
}
