#include "server.h"


// Function call to setup the server socket fd
int setup_server(int* server_sockfd)
{
	int opt_port = 1;
	struct sockaddr_in server_address;  // Structure describing the internet sockaddr

	if ((*server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a server socket         
	{
		perror("\t*********************ERROR : Socket creation failed*************************\n");
		return -1;
	}
	else
	{
		printf("\t--------------------Server socket created sucessfully-----------------------\n");
		printf("\t----------------------------------------------------------------------------\n");
	}

	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	setsockopt(*server_sockfd, SOL_SOCKET, (SO_REUSEADDR), &opt_port, sizeof(opt_port));   // Focrcefully sets the port

	if (0 != bind(*server_sockfd, (struct sockaddr*)&server_address, sizeof(struct sockaddr)))   // Binding the socket
	{
		printf("\t***********************ERROR : Socket bind failed***************************\n");
		return -1;
	}
	else
	{
		printf("\t-----------------------Socket Binded successfully---------------------------\n");
		printf("\t----------------------------------------------------------------------------\n");
	}

	if (0 != listen(*server_sockfd, LISTEN_BACKLOG))    // Listening the incoming connection
	{
		printf("\t**********************ERROR : Socket listen failed**************************\n");
		return -1;
	}
	else
	{
		printf("\t--------------------Server socket is ready to listen------------------------\n");
		printf("\t----------------------------------------------------------------------------\n");
	}
	return 0;

}
