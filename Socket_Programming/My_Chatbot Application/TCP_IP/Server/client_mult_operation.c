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
#define MAX_NAME_SZE 20
#define MAX_BUFFER_SIZE 1024

char client_name[MAX_NAME_SZE] ={0};



int main()
{	
	int client_sockfd = 0;      // Declaring the socket file despcriptor = client_sockfd
	int opt_port = 1;      // Variable used for setsockopt()
	char client_responce[1024];     // Creating a buffer = server_responce
	
	struct sockaddr_in client_address;    // Creating a sockaddr structure to hold the address

	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);   // Creating a client socket
	if(client_sockfd == -1)                   // Checking the status of creation of client socket
	{
		printf("Error in creating a client socket \n");
		return -1;
	}
	printf(".....Client Socket created succesfully.... ! \n");		 
	
	setsockopt(client_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt_port , sizeof(opt_port)); 

	bzero(&client_address, sizeof(client_address)); // bzero()   
	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(PORT);
	client_address.sin_addr.s_addr = INADDR_ANY;
	
	// Creating a connection status which will connect to a remote host
	int connection = connect(client_sockfd, (struct sockaddr *) &client_address, sizeof(client_address));
	if(connection == -1)
	{
		printf("Error in connecting to the server\n");
	}	
	
	printf(".....Client connected to server....!!!\n");
	
	
		for(;;)
		{	
			
			int read_bytes = 0;
			int write_bytes = 0;
			int write_name = 0;
			char send_msg[32];
			char recv_msg[32];
			int client_socket;
			
			bzero(send_msg, sizeof(send_msg)); 
			printf("Please tell your name\n");
			gets(send_msg);
			
			bzero(send_msg, sizeof(send_msg));  
			write_bytes = send(client_socket, send_msg, strlen(send_msg), 0); 
			
				
			bzero(recv_msg,sizeof(recv_msg));     // bzero() used to erase 
				
			read_bytes = recv(client_socket, recv_msg, sizeof(recv_msg), 0); //recv() 
			printf("Client messsage recieved: %s \n");
			gets(recv_msg);       
		
			printf("---------------------------\n");						
		}
		close(client_sockfd);    // Closing the client_socket
		return 0;
}	 

