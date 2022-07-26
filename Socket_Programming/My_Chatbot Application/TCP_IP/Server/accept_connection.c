#include "server.h"

// Function defination for accepting the new connection
int accept_new_connection(int server_sockfd, int *new_server_sockfd)
{	   
		struct sockaddr_in client_address;   // struct sockaddr_in in client_address
		socklen_t clilen;                    // Creating  a socklen_t variable -> clilen
		clilen = sizeof(struct sockaddr);       // Setting the sizeof client length
		
		bzero(&client_address, sizeof(client_address));   // Clearing the client address initially
		if((*new_server_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &clilen)) < 0)  // Accepting the pending connection
		{
			printf("Error in accepting the message");
			exit(1);
		}
		else
		{
			printf(".....Server sockfd is ready to accept the incoming messages....\n");
			handle_connection(client_address,*new_server_sockfd);   // Function call to populate the ip and port for handling the connection 
		}
		
		//handle_connection(client_address,*new_server_sockfd);   // Function call to populate the ip and port for handling the connection 
		
		return 0;
}		
