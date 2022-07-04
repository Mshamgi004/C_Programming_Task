// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP for sending messages from both sides continuously.
// Server Socket program.

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
	int server_sockfd, new_server_sockfd;    // Declaring the socket file despcriptor = server_sockfd & new_server_sockfd
	
	int bind_check;        // Variable to store the bind check
	int accept_check;      // Variable to store the accept check
	
	int opt_port;          // Variable used for setsockopt()
	
	char server_responce[1024];         // Creating a buffer = server_responce
	
	socklen_t clilen;      // Defining the socklen_t address
	
	struct sockaddr_in server_address, client_address;   // Creating a sockaddr structure to hold the address
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Creating a server socket
	
	if(server_sockfd == -1)                            // Checking for server_socket is created or not 
	{
		printf("Error in creating the socket");
		return -1;
	}
	printf("....Server Socket created succesfully !.... \n");
	
	// Forcefully sets the socket port number
	if(setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_port , sizeof(opt_port))); // Forcefully sets the socket port number
	
	bzero(&server_address, sizeof(server_address));    //bzeoro clears any data or text what it is referring to
	
	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;    
	server_address.sin_port = htons(PORT);   
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind_check = bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));  // Binding the socket
	
	if(bind_check == -1)                  // Bind checking
	{
		printf("Error in binding \n");
	 	return -1;
	}
	printf("Socket binded succefully ! \n");
	
	listen(server_sockfd, 6);          // Listening the incoming connection
	
    	while(1)
	{   
		clilen = sizeof(client_address);       // Setting the sizeof client length
		
		new_server_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &clilen);  // Accepting the pending connection
		
		if(new_server_sockfd == -1)        // Checking for whethet message is accepted or not
		{
			printf("Error in accepting the message");
			return -1;
		}
		printf(".....Server sockfd is ready to accept the incoming messages....\n");
	
		// Loop created to iterate the messages 
		for(;;)                                         
		{
			bzero(server_responce, 1024);     // bzero() used to erase the data stored in buffer           
			
			recv(new_server_sockfd, server_responce, sizeof(server_responce), 0);  //recv() function to used by server to recive message from client
					
			printf("Client messsage recieved: %s ");
			gets(server_responce);       
			
			printf("------------------------------------\n");
	
			bzero(server_responce, 1024);     // bzero() used to erase the data stored in buffer 
					
			printf("Enter message to be send to server: %s ");
			gets(server_responce);
			
			send(new_server_sockfd, server_responce, strlen(server_responce), 0);  // send() function to send message to client 
		}	
	}	
	close(new_server_sockfd);	// Closing the server sockfd
	
	return 0;
}	
	
	
		
		
	
	

