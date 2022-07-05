// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP which sends message continuosly and terminates by passing a specific string.
// Client Socket program.
// Client soursce file .c

#include "clientchat.h"


void client_func(int client_sockfd)    // Function defination of client_func
{
	int value;    // Declaring a variable to read and write
	char client_responce[1024];      // Creating a buffer = client_responce
	 
	for(;;)          // Loop created to iterate the messages 
	{
		bzero(client_responce, sizeof(client_responce));     // Creating a buffer = server_responce
		
		printf("Client message to server:  ");	// Sending message to server by client
		
		value = 0;     // initialized to zero  
		while ((client_responce[value++] = getchar()) != '\n');  // condition used to get the message and store in val
			
		write(client_sockfd, client_responce, value);       // Writing to the server to sent the message
		
		bzero(client_responce, sizeof(client_responce));  // Checking the writing message
		
		read(client_sockfd, client_responce, sizeof(client_responce));   // Reading client message
		printf("Server message recived: %s \n", client_responce);  // Server message recieved
		
		if(strcmp(client_responce, "Bye\n")== 0)      // strcmp() used to compare the string "Bye"
		{
			printf("...Client disconnected... \n");	
			break;
		}
	}
}	
