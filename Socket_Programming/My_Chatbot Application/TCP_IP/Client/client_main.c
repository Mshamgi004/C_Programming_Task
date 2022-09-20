#include "client.h"

int main(int argc, char* argv[])
//int main()
{
	//char get_name[1024];
	int client_sockfd = 0;   // Declaring the client_sockfd
	int maxval_fd = 0;    // A max sock_fd declared to hold the server_sockfd value

	// Declaring the read,write and except fd's for select()
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;

	//char buffer1[1000];         // char buffer[] used to store the name
	//char buffer2[1000];         // char buffer[] used to store the password

	// printf("Please enter your name: ");                  
	// scanf("%s", buffer1);                           // Entering the name from client side.
	//fgets(buffer, 1000, stdin);
	//strcpy(client_name, buffer1);            // Copying the recived name in buffer and sending it to the client_name
	
	// printf("\tYou are logged in !!!. Create a password for registration\n");
	// scanf("%s",buffer2);


	// strcpy(password, buffer2);
	//fgets(client_name, MAX_BUFFER_SIZE, stdin);          // fgets() used to recieve the name of the client
	// if(fgets(client_name, MAX_BUFFER_SIZE, stdin) != NULL)
	// {
	// 	char *array;
	// 	int length;
	// 	int number;

	// 	for(number = 0; number < length; number++)
	// 	{
	// 		if(array[number] = '\n')
	// 		{
	// 			array[number] = '\0';
	// 			break;
	// 		}
	// 	}
	// }
	// if(strlen(client_name < 2 || strlen(client_name) >= MAX_BUFFER_SIZE - 1))
	// {
	// 	printf("\nName must be more than one and less than ");
	// }
	//To check the name given from cmd in binary
	if (argc > 2)
	{
		printf("\t||**********************ERROR : Parameters error****************************\n");
		exit(0);
	}

	strcpy(client_name, argv[1]);

	// printf("\tYou are logged in !!!. Create a password for registration\n");
	// scanf("%s",buffer2);


	// strcpy(password, buffer2);
	// printf("Enter your name: \n");
	// fgets(get_name, 1024, stdin);
	// printf("Name = %s\n", get_name);
	// strcpy(client_name, get_name);
	// printf("Name = %s\n", client_name);
	//fgets(client_name, MAX_BUFFER_SIZE, stdin);
	// Copying the string in client_name typed in cmd
	//strcpy(client_name, argv[1]);

	printf("\t||---------------------------CLIENT STARTED-------------------------------||\n");
	printf("\t||************************************************************************||\n");

	if (client_create_socket(&client_sockfd) != 0) // Function call for setting up of client
	{
		printf("\t||*******************ERROR : Socket creation failed*************************\n");
		exit(0);
	}
	else
	{
		maxval_fd = client_sockfd;   // Equalising the maxval_fd to client_fd
	}

	while (1)
	{
		maxval_fd = client_build_fdsets(client_sockfd, &readfds, &writefds, &exceptfds);   // server_socket will build the fd_sets and will return the maxval_fd
		client_select(maxval_fd, client_sockfd, &readfds, &writefds);     // Function call for select()
	}
	close(client_sockfd);   // Closing the client_sockfd

	return 0;
}
