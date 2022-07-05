// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP which sends message continuosly and terminates by passing a specific string.
// Server Socket program.
// Server main file .c

#include "serverchat.h"

int main()
{
	int server_sockfd, new_server_sockfd;   // Declaring the socket file despcriptor = server_sockfd
	int bind_check;     // variable used for bind check
	int accept_check;   // variable used to check accepting the connection
	
	int opt_port;          // Variable used for setsockopt()
	
	socklen_t addr_size;    // storing the size of string in addr_size
	
	struct sockaddr_in server_address, client_address; // Creating a sockaddr structure to hold the address
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);   // Creating a server socket
	
	if(server_sockfd == -1)              // Checking for server_socket is created or not 
	{
		printf("Error in creating a server socket \n");
		return -1;
	}
	else
	{
		printf("Server Socket created succesfully ! \n");	
		
		printf("--------------------------------\n");
	}
	
	if(setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt_port , sizeof(opt_port)));			 // Forcefully sets the socket port number
	
	bzero(&server_address, sizeof(server_address));  // bzero() used to erase the data stored in buffer  
	
	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind_check = bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));  // Binding the socket
	
	if(bind_check == -1 )     // Checking for binding
	{
		printf("Error in binding \n");
		return -1;
	}
	else
	{
		printf("Socket binded succefully ! \n");
		
		printf("--------------------------------\n");
	}
	
	listen(server_sockfd, 5);     // Listening the incoming connection
	
        addr_size = sizeof(client_address);      /// addr_size used to store the client_address
	
	new_server_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &addr_size);   // Accepting the pending connection
	
	if(new_server_sockfd == -1)         // Checking for whethet message is accepted or not
	{
		printf("Error in accepting the message");
		return -1;
	}
	else
	{
		printf(".....Server sockfd is ready to accept the incoming messages....\n");
		
		printf("--------------------------------\n");
	}	
			
	server_func(new_server_sockfd);	 // Function calling of server_func
		
	close(server_sockfd);     // Closing the sockfd 
	
	return 0;
}	
