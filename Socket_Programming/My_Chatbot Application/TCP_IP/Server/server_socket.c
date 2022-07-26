#include "server.h"

// Function defination to setup the server socket fd
int setup_server(int *server_sockfd)
{
	int opt_port;          // Variable used for setsockopt()
	//int bind_check;        // Variable used for bind check
	
	struct sockaddr_in server_address; // Structure describing the internet sockaddr
	
	if((*server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) // Creating a server socket                         // Checking for server_socket is created or not 
	{
		printf("Error in creating the socket");
		exit(1);
	}
	else
	{
		printf(".......Server Socket created succesfully !...... \n");
	}
	//bzero(&server_address, sizeof(server_address));    //bzero clears any data 
	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;    
	server_address.sin_port = htons(PORT);   
	server_address.sin_addr.s_addr = INADDR_ANY;

	setsockopt(*server_sockfd, SOL_SOCKET, (SO_REUSEADDR|SO_REUSEPORT), &opt_port , sizeof(opt_port)); // Forcefully sets the socket port number

	if(0 != bind(*server_sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr))) // Binding the socket
	{
		printf("Error in binding \n");
	 	exit(1);
	}
	else
	{
		printf("Socket binded succefully to port no : %d!\n", server_address.sin_port);
	}
	
	if(0 != listen(*server_sockfd, BACKLOG))       // Listening the incoming connection
	{
		printf("Error in listening to the messages in queue \n");
		exit(1);
	}
	else
	{
		printf(".......Socket is listening....... \n");
	}
	return 0;
}	

