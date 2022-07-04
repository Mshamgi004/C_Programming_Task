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
		// Declaring the socket file descriptor for client
		int sockfd;
		
		// A type defination of socklen_t used to return length and size
		socklen_t addr_size;
		
		// Holds the address of socket
		struct sockaddr_in address;
		
		// A char buffer to store the messages
		char client_responce[1024];
		
		// Creating a socket for server side
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		
		// Checking for socket created 
		if(sockfd == -1)
		{
			printf("Error in creating the socket!\n");
			return -1;
		}	
		
		printf(".......Client socket created successfully......\n");
		
		printf("-----------------------------------------------\n");
		
		// memset() function used to fill the memory to the server_address and initializing it with zero
		memset(&address, '\0', sizeof(address));
		
		// Declaring the family, port and address for sockfd
		address.sin_family = AF_INET;
		address.sin_port = htons(8000);
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		
		// Connecting the server side 
		connect(sockfd, (struct sockaddr *)&address, sizeof(address));
		
		printf("........Connected to Server........ \n");
		
		printf("-----------------------------------------------\n");
		
		// bzero() function used to clear the buffer.
		bzero(client_responce, 1024);
		
		// Passing a string to buffer which has to be send to client
		strcpy(client_responce, "Hello, I am Client.");
		printf("Client message to server: %s\n", client_responce);
		
		printf("-----------------------------------------------\n");
		
		// Sending the message to Client side
		send(sockfd, client_responce, strlen(client_responce), 0);
		
		// bzero() function again used to claer the buffer
		bzero(client_responce, 1024);
		//strcpy(server_responce, "I am fine !!!");
		// Reciveing the message from Server side
		recv(sockfd, client_responce, sizeof(client_responce), 0);
		printf("Message recived from Server: %s\n", client_responce);
		
		printf("-----------------------------------------------\n");
		
		//close(sockfd);
		close(sockfd);
		
		// End of application
		printf("....Disconnected from Server....\n");
		
		printf("----------END OF APPLICATION----------\n");
		return 0;
}	
		
				
	
	
