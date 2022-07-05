// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP which sends message continuosly and terminates by passing a specific string.
// Client Socket program.
// Client main file .c



#include "clientchat.h"   

int main()
{	
	int client_sockfd;   // Declaring the socket file despcriptor = client_sockfd
	
	int opt_port = 1;    // Variable used for setsockopt()
	
	struct sockaddr_in client_address;       // Creating a sockaddr structure to hold the address   
	
	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);   // Creating a client socket
	
	printf("Client Socket created succesfully ! \n");   
	
	printf("--------------------------------\n");
	
	if(client_sockfd == -1)       // Checking the status of creation of client socket
	{
		printf("Error in creating a client socket \n");
		return -1;
	}
	else
	{
        	printf("Socket successfully created..\n");
        	
        	printf("--------------------------------\n");	
        }	
	if(setsockopt(client_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_port , sizeof(opt_port)));  // Forcefully sets the socket port number 
	
	
	bzero(&client_address, sizeof(client_address));    // bzero() used to erase the data stored in buffer 
	
	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(PORT);
	client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// Creating a connection status which will connect to a remote host
	int connection = connect(client_sockfd, (struct sockaddr *) &client_address, sizeof(client_address));
	
	if(connection == -1)   // Checking for the connection
	{
		printf("Error in connection to remote host \n");
		return -1;
	}
	else
	{
		printf("Connected to server...\n");
		
		printf("--------------------------------\n");
	}	
	
	client_func(client_sockfd);      // Calling the client_func
	
	close(client_sockfd);    // closing the client_sockfd
	
	return 0;
}	
