#include "client.h"

// Function defination for setting up of client socket
int client_create_socket(int *client_sockfd) 
{
	int opt_port = 1;
	struct sockaddr_in client_address;   // Creating a sockaddr structure to hold the client_addressess

	if((*client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a client socket() 
	{
        printf("*****ERROR : Socket creation failed*****\n");
        return -1;
    }
	else
	{
		printf("-------Client socket created sucessfully-------\n");
		printf("-----------------------------------------------\n");
	}

	setsockopt(*client_sockfd, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT), &opt_port, sizeof(opt_port));
	
	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(SERVER_PORT); 
	client_address.sin_addr.s_addr = INADDR_ANY;
	
	// Creating a connection status which will connect to a remote host
    if( 0 != connect(*client_sockfd,(struct sockaddr *)&client_address,sizeof(struct sockaddr))) 
	{
        printf("****ERROR : Connect failed*****");
        return -1;
    }
	else
	{
		printf("------Client socket is ready to connect to server------\n");
		printf("--------------------------------------------\n");
		client_send_to_server(*client_sockfd,client_name);  // Function call for sending the client_name as the client_sockfd is the return type
	}
    return 0;
}
