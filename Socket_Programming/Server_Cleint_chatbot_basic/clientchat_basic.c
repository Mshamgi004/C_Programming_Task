// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP for sending messages from both sides continuously.
// Client Socket program.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>

#define PORT 8000


int main()
{	
	int client_sockfd;      // Declaring the socket file despcriptor = client_sockfd
	
	int opt_port;      // Variable used for setsockopt()

	char client_responce[1024];     // Creating a buffer = server_responce
	
	struct sockaddr_in client_address;    // Creating a sockaddr structure to hold the address

	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);   // Creating a client socket
	
	printf(".....Client Socket created succesfully.... ! \n");
	
	if(client_sockfd == -1)                   // Checking the status of creation of client socket
	{
		printf("Error in creating a client socket \n");
		return -1;
	}		 
	
	if(setsockopt(client_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_port , sizeof(opt_port)));  // Forcefully sets the socket port number

	bzero(&client_address, sizeof(client_address)); // bzero() used to erase the data stored in buffer  
	
	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(PORT);
	client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// Creating a connection status which will connect to a remote host
	int connection = connect(client_sockfd, (struct sockaddr *) &client_address, sizeof(client_address));
	
	printf(".....Client connected to server....!!!\n");
	// Loop created to iterate the messages 
	while(1)
	{
		// Loop created to iterate the messages 
		for(;;)
		{
			bzero(client_responce, sizeof(client_responce));   // bzero() used to erase the data stored in buffer  
			
			printf("Enter message to be send to server: %s ");
			gets(client_responce);
			
			printf("------------------------------------\n");
				
			send(client_sockfd, client_responce, strlen(client_responce), 0);  // send() function to send message to client 
				
			bzero(client_responce, sizeof(client_responce));
				
			recv(client_sockfd, client_responce, sizeof(client_responce), 0);  //recv() function to used by server to recive message from client
				
			printf("Server messsage recieved: %s ");
			gets(client_responce);
		}
		
	}	
	close(client_sockfd);    // Closing the client_socket
	
	return 0;
}	 
	
	
