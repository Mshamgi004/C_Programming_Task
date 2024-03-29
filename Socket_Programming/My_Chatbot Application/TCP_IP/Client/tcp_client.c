//------------------------------------------------------------------------------MY CHATBOT APPLICATION------------------------------------------------------------------------------//

/*
 TASK: TO CREATE A CHATBOT APPLICATION WHICH WILL COMMUNICATE BETWEEN TWO CLIENTS.
	   BY DOING SO THE SERVER WILL STORE THE CLIENT DETAILS SUCH AS THE  NAME, fd's , PORT  & IP ADDRESS IN A clientlist.txt file.
*/

/*
#1: Maintain the connected client details in server's data structure and store them in a text file. 
#2: Respond to commands like LIST and CONNECT 
#3: Communicate between clients through server by using select() system call. 
#4: Create a prompt on client side so as to make it user friendly application for clients. 
#5: The CLIENT_INFO.txt has the details of the connected client's such as the name, IP Address, port number and their file descriptor. And there should be updation in the .text file after every new entry of client and also the status of deletion of the client should be shown in the text file after their exist. 
#   PS: There is the concept of file modification done in between the running applcation as whenever any client connects to the server it's data is being shown in the text file and if the client connected gets disconnected from the application then there should be a status of client deleted from the the text file on the spot. 
#6: Client should communicate with the other connected clients whose data are stored in Server side of CLIENT_INFO.txt. And Client should have the flexibility to communicate with any connected client.
*/

// Socket programming steps client
//STEP 1 : creating a socket file descriptor
//STEP 2 : connect to the server
//STEP 3 : recv/send for data communication
//STEP 4 : closing the file descriptor


//**************************************************************************************CLIENT***************************************************************************************// 



//Header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<sys/select.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<fcntl.h>


// MACROS
#define SERVER_PORT 9000
#define MAX_NAME_SZE 20
#define MAX_BUFFER_SIZE 1024
#define NO_OF_CLIENTS 10
#define CONNECTED "------CONNECTED TO SERVER-------"

char client_name[MAX_NAME_SZE];// = { 0 };   // Char buffer used to store the client name

//char password[MAX_BUFFER_SIZE];  // Char buffer used to store the password of the login client user

//Function declaration
int client_create_socket(int* client_sockfd);
int client_recv_from_server(int socket_client, char *recv_msg);
int client_send_to_server(int socket_client, char *send_msg);
int client_build_fdsets(int listenfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int client_select(int maxval_fd, int listenfd, fd_set *readfds, fd_set *writefds);
//int LIST_clients(char* buffer, char* send_buffer);
//int CONNECT_to_Client(char* buffer, char* chat_c);
//int find_the_client_index_list(int socket);
//int find_the_client_index_by_name(char* name);
int Client_decision();//(int client_sockfd, char* send_buffer);
//void server_delete_client(int socket_fd_delete); 

// Main function
//int main()
int main(int argc, char* argv[])
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


// Function defination for setting up of client socket
int client_create_socket(int* client_sockfd)
{
	int opt_port = 1;
	//char get_name[1024];
	struct sockaddr_in client_address;   // Creating a sockaddr structure to hold the client_addressess

	if ((*client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a client socket() 
	{
		printf("\t||*******************ERROR : Socket creation failed***********************||\n");
		return -1;
	}
	else
	{
		printf("\t--------------------Client socket created sucessfully-----------------------\n");
		printf("\t----------------------------------------------------------------------------\n");
	}

	// printf("Enter your name: \n");
	// fgets(get_name, 1024, stdin);
	// printf("Name = %s\n", get_name);
	// strcpy(client_name, get_name);
	// printf("Name = %s\n", client_name);

	setsockopt(*client_sockfd, SOL_SOCKET, (SO_REUSEADDR), &opt_port, sizeof(opt_port));

	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(SERVER_PORT);
	client_address.sin_addr.s_addr = INADDR_ANY;
	//client_address.sin_addr.s_addr = 0×0A7E4051;   // for connecting with any other machine at same network

	// Creating a connection status which will connect to a remote host
	if (0 != connect(*client_sockfd, (struct sockaddr*)&client_address, sizeof(struct sockaddr)))
	{
		printf("\t||*********************ERROR : connect() failed***************************||\n");
		return -1;
	}
	else
	{
		printf("\t--------------Client socket is ready to connect to server-------------------\n");
		printf("\t----------------------------------------------------------------------------\n");

		//printf("Enter your name:");
		//scanf("%s\n", client_name);
		client_send_to_server(*client_sockfd, client_name);  // Function call for sending the client_name as the client_sockfd is the return type
	}

	return 0;
}


// Function defination for client_build_fdsets
int client_build_fdsets(int client_sockfd, fd_set* readfds, fd_set* writefds, fd_set* exceptfds)
{
	int maxval_fd = client_sockfd;   // Keeping the value of client_sockfd = maxval_fd

	FD_ZERO(readfds);     // Initializing readfds with zero value
	FD_SET(client_sockfd, readfds);    // Setting the client_sockfd as readfds
	FD_SET(client_sockfd, writefds);   // Setting the writefds to 0 so as to recive the commands from cmd
	FD_SET(STDIN_FILENO, readfds);   // Setting the readfds to 0 so as to recive the commands from cmd
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);   // fcntl() used to nonblocking the application from the cmd 

	return maxval_fd;
}

// Function declaration for client_select
int client_select(int maxval_fd, int client_sockfd, fd_set* readfds, fd_set* writefds)
{
	// Declaring the char buffer for storing the sending and recieving message
	char recv_msgg[MAX_BUFFER_SIZE];
	char send_buff[MAX_BUFFER_SIZE];
	memset(recv_msgg, 0, sizeof(recv_msgg));
	memset(send_buff, 0, sizeof(send_buff));

	int action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);   // select() system call 

	// To check if the select() sys call is working or not
	if (action == -1 || action == 0)
	{
		printf("\t||***************************ERROR: select()******************************||\n");
		exit(0);
	}
	// To check for all the clients in the file des inside the readfds
	if (FD_ISSET(client_sockfd, readfds))
	{
		// If its present in readfds then it will recieve the message
		client_recv_from_server(client_sockfd, recv_msgg);
	}
	// To check the fd is set for sending the message so as to broadcast the message to all clients
	if (FD_ISSET(STDIN_FILENO, readfds))
	{
		if (read(0, send_buff, sizeof(send_buff)) > 0)
		{
			client_send_to_server(client_sockfd, send_buff);
		}
		else
		{
			printf("\tNot able to enter the send_to_server\n");
		}
	}
	return 0;
}

// Function defination of sending message to the server
int client_send_to_server(int client_socket, char* send_msg)
{
	int write_bytes = 0;   // Variable used for writing the message
	int len = strlen(send_msg);    // Declaring a socklen_t variable -> serlen
	char buffer[MAX_BUFFER_SIZE];
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE];
	int client_sockfd;

	// printf("Enter your name: \n");
	// fgets(buffer, 1024, stdin);
	// printf("Name = %s\n", buffer);
	// strcpy(client_name, buffer);
	// printf("Name = %s\n", client_name);
	// //printf("Enter your name:");
	// //scanf("%s\n", client_name);
	// strcpy(send_msg, client_name);
	//printf("Mess = %s\n", send_msg);

	if ((write_bytes = send(client_socket, send_msg, len, 0)) <= 0)   // Storing the send buffer in serlen
	{
		perror("\t||************************ERROR: send() failed****************************||\n");
		return -1;
	}
	else
	{
		//printf("--------ENTER THE APPLICATION--------\n");
		Client_decision();//(client_sockfd, send_buffer);
	}
	//Client_decision(client_sockfd, send_buffer);
	return write_bytes;
}



// Function defination to recv message from server
int client_recv_from_server(int client_socket, char* recv_msg)
{
	int read_bytes = 0;    // Variable use to store the read_bytes 
	int socket_fd_delete;

	if ((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0)) > 0)   // recv() message from server
	{
		printf("%s\n", recv_msg);

	}
	else if (read_bytes == 0)
	//else
	{
		printf("\t**********************CLIENT DISCONNECTED****************************\n");
		//server_delete_client(socket_fd_delete);
		close(client_socket);
	}
	else
	{
		printf("\t||***********************ERROR: recv() failed*****************************||\n");
	}

	return 0;
}


// Function defination for client decision
int Client_decision()//(int client_sockfd, char* send_buffer)
{
	int choice = 0;
	//char recv_msg[MAX_BUFFER_SIZE];
	//char buffer[MAX_BUFFER_SIZE];
	//char chat_c[MAX_BUFFER_SIZE];
	//int client_socket;
	//int socket_fd_delete;
	
	printf("\t||----You have entered the application. Now choose what you have to do----||\n");
	printf("\t||    Note: Please select a number between 1 to 3.                        ||\n");
	printf("\t||************************************************************************||\n");
	printf("\n\
	1. 	Press 1 to know the other client details\n\
	2. 	Press 2 to chat with a client\n\
	3.	Press 3 to exit\n");
	printf("\nEnter your choice:\n");
	printf("\n______________\n");
	scanf("\n%d", &choice);

	switch (choice)
	{
		case 1:
		{
			printf("LIST all client details\n");
			//LIST_clients(buffer, send_buffer);
			break;
		}
		case 2:
		{
			printf("Enter name of client to chat with:\n");
			//CONNECT_to_Client(buffer, chat_c);
			break;
		}
		case 3:
		{
			printf("Exit the application\n");
			//server_delete_client(socket_fd_delete);
			break;
		}
		// default:
		//  	printf("wrong Input\n");
		// 	break;
	}
	getchar();
		return 0;
}

