// Socket Programming
// TCP based Client-Server program for passing a sing message from Client to Server and vice-versa

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>

int main()
{
	// Declaring the socket file descriptor for server and client
	int server_sockfd, client_sockfd;
	
	// Declaring the variables for bind and accept check
	int bind_check;
	int accept_check;
	
	// A type defination of socklen_t used to return length and size
	socklen_t addr_size;
	
	// Holds the address of socket
	struct sockaddr_in server_address, client_address;
	
	// A char buffer to store the messages
	char server_responce[1024];
	
	// Creating a socket for server side
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Checking for socket created 
	if(server_sockfd == -1)
	{
		printf("Error in creating the socket!\n");
		return -1;
	}	
	printf(".......Server socket created successfully......\n");
	
	printf("-----------------------------------------------\n");
	
	// memset() function used to fill the memory to the server_address and initializing it with zero
	memset(&server_address, '\0', sizeof(server_address));
	
	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8000);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// Binding the socket to associate a socket with a port on the local machine
	bind_check = bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
	
	// Checking the binding condition
	if(bind_check == -1)
	{
		printf("Error in binding");
		return -1;
	}
	
	
	// Server socket ready to listen to incoming connection
	listen(server_sockfd, 6);
	
	printf("......Listening to incoming messages......\n");
	
	printf("------------------------------------------\n");
	while(1)
	{	
		// Passing the client_address size to a variable addr_size
		addr_size = sizeof(client_address);
		
		// Accepting the pending connection on the port you are listening 
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &addr_size);
		
		printf("--------Client is connected-------- \n");
		
		printf("------------------------------------\n");
		
		// bzero() function used to clear the buffer.
		bzero(server_responce, 1024);
		//strcpy(server_responce, "Hello I am Server !!!");
		
		// Reciveing the message from Client side
		recv(client_sockfd, server_responce, sizeof(server_responce), 0);
		printf("Message from Client: %s\n", server_responce);
		
		printf("------------------------------------\n");
		
		// bzero() function again used to claer the buffer
		bzero(server_responce, 1024);
		
		// Passing a string to buffer which has to be send to client
		strcpy(server_responce, "HI THIS IS SERVER !!");
		printf("Server message to client: %s\n", server_responce);
		
		printf("------------------------------------\n");
		
		// Sending the message to Client side
		send(client_sockfd, server_responce, strlen(server_responce), 0); 	
		
		//close(server_sockfd);
		close(client_sockfd);
		
		// End of Application 
		printf(".....Client disconnected..... \n");
		
		printf("----------END OF APPLICATION----------\n");
		
	}
	
	return 0;
}	
		
				
	
	
