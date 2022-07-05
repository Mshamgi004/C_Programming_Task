// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP which sends message continuosly and terminates by passing a specific string.
// Server Socket program.
// Server soursce file .c

#include "serverchat.h"


void server_func(int new_server_sockfd)  // Function defination of server_func
{				
	int val;              // Declaring a variable to read and write
	char server_responce[1024];      // Creating a buffer = server_responce
			
	for(;;)           // Loop created to iterate the messages 
	{
		bzero(server_responce, 1024);           // Creating a buffer = server_responce
		read(new_server_sockfd, server_responce, sizeof(server_responce));    // Reading client message
		
		printf("Message from Client: %s\t To client : ", server_responce); // Printing the message received from client and sending it to server
		
		if(strcmp(server_responce, "Bye\n") == 0)       // strcmp() used to compare the string "Bye"
		{
			printf("---SERVER Disconnected---\n");
			break;
		}
		
		bzero(server_responce, 1024);	 // Creating a buffer = server_responce
		
		val = 0;     // initialized to zero  
		while ((server_responce[val++] = getchar()) != '\n');   // condition used to get the message and store in val
			
		write(new_server_sockfd, server_responce, val);       // Writing to the client to sent the message
	}
}	
