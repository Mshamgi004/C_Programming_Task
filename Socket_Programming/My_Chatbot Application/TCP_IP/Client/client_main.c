#include "client.h"

int main() 
{
	int client_sockfd = 0;   // Declaring the client_sockfd
	int new_socket = 0;   
	int maxval_fd = 0;    // A max sock_fd declared to hold the server_sockfd value

	// Declaring the read,write and except fd's for select()
	fd_set readfds;    
	fd_set writefds;
	fd_set exceptfds;

	// // To check the name given from cmd in binary
	// if(argc > 2) 
	// {
    //     printf("****ERROR : Parameters error****");
    //     exit(0);
    // }
    
	// // Copying the string in client_name typed in cmd
    // strcpy(client_name,argv[1]);
	//printf("Tell your name :%s",client_name);

	if(client_create_socket(&client_sockfd) != 0) // Function call for setting up of client
	{
		printf("*****ERROR : Socket creation failed*****");
        exit(0);
    }
	else
	{
		maxval_fd = client_sockfd;   // Equalising the maxval_fd to client_fd
  	}
	

	while(1) 
	{
		maxval_fd = client_build_fdsets(client_sockfd, &readfds, &writefds, &exceptfds);   // server_socket will build the fd_sets and will return the maxval_fd
		client_select(maxval_fd,client_sockfd, &readfds, &writefds);     // Function call for select()
    } 
	close(client_sockfd);   // Closing the client_sockfd
	
	return 0;
}
