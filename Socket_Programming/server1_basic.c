// Socket programming
// Server socket for TCP connection

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>


int main()
{
	// A socket file descpripter of integer type created for server
	int server_sockfd;
	
	// Creating a socket for server side
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);        //  SOCK_STREAM for TCP connection.....
	printf("Server socket created sucessfully !!!\n");
	
	printf("---------------------------------\n");
	
	// Holds the address of socket
	struct sockaddr_in socket_address;
	
	// // A char buffer(server_message) being created to hold the message
	char server_message[1024] = "Hi from server!!!";
	
	// Declaring the family, port and address for sockfd
	socket_address.sin_family = AF_INET;
	socket_address.sin_port = 8000;
	socket_address.sin_addr.s_addr = INADDR_ANY;
	
	// Binding the socket to associate a socket with a port on the local machine
	bind(server_sockfd, (struct sockaddr *)&socket_address, sizeof(struct sockaddr));
	printf("Server is binded sucessfully !!!\n");
	
	printf("---------------------------------\n");
	
	// Server socket ready to listen to incoming connection
	listen(server_sockfd, 5);
	printf("Server is waiting for incoming connection......\n");
	
	// A socket of type client being created to accept the message
	int client_socket;
	
	// Accepting the pending connection on the port you are listening 
	client_socket = accept(server_sockfd, NULL, NULL);
	printf("Connction established !!!\n");
	
	printf("---------------------------------\n");
	
	// Sending the message stored in buffer through the new socket
	send(client_socket, server_message, sizeof(server_message), 0);
	
	printf("---------------------------------\n");
	
	// Printing the acknowledgement message
	printf("Mesage recieved to client succesfully !!!\n");
	
	// Closing the socket
	close(server_sockfd);
	
	return 0;
}	
