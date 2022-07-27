#include "server.h"

// Function defination for accepting the new connection
int accept_new_connection(int server_sockfd, int *new_server_sockfd) 
{
    struct sockaddr_in client_address;  // struct sockaddr_in in client_address
    int server_length;    // Creating a variable -> server_length
    server_length = sizeof(struct sockaddr);   // assigning the address to the variable server_length
    
	bzero(&client_address,sizeof(client_address));  // Clearing the client address initially
        
    if((*new_server_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &server_length)) < 0)  // Accepting the pending connection
    {
        printf("******ERROR :Accept failed*******");
        return -1;
    }
	else
	{	
		printf("----Socket is ready to accept the incoming client details----\n");
		printf("-------------------------------------------------------------\n");
		handle_connection(client_address ,*new_server_sockfd);  // Function call to populate the ip and port for handling the connection 
	}
    
    return 0;
}
