// Socket programming 
// Client socket for TCP conncetion

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
	// A socket file descpripter of integer type created for client
	int client_sockfd;
	
	// Creating a socket for client side
	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Client socket created successfully !!!\n");
	
	printf("---------------------------------\n");
	
	// Holds the address of socket
	struct sockaddr_in socket_address;
	
	// Declaring the family, port and address for sockfd
	socket_address.sin_family = AF_INET;
	socket_address.sin_port = 8000;
	socket_address.sin_addr.s_addr = INADDR_ANY;
	
	// Connecting to a remote host i.e the server 
	int connection = connect(client_sockfd, (struct sockaddr *) &socket_address, sizeof(socket_address));
	
	// Checking for connection establishment
	if(connection == -1)
	{
		printf("Not able to connect !!! \n");
	}
	
	// A char buffer(server_responce) being created to hold the message
	char server_responce[1024];
	
	// Reciveing the message 
	recv(client_sockfd, &server_responce, sizeof(server_responce), 0);
	
	// Printing the server's message stored in buffer
	printf("The server responce is %s \n", server_responce);
	
	printf("---------------------------------\n");
	
	// Printing the message recived 
	printf("Message recieved sucessfully from server !!! \n");
	
	// Closing the socket
	close(client_sockfd);
	
	return 0;
}		
