//------------------------------------------------------------------------------MY CHATBOT APPLICATION------------------------------------------------------------------------------//

/*
 TASK: TO CREATE A CHATBOT APPLICATION WHICH WILL COMMUNICATE BETWEEN TWO CLIENTS.
	   BY DOING SO THE SERVER WILL STORE THE CLIENT DETAILS SUCH AS THE  NAME, fd's , PORT  & IP ADDRESS IN A clientlist.txt file.
*/

// OBJECTIVE 1: Maintain the connected client details in server's data structure
// OBJECTIVE 2: Respond to command like LIST and CONNECT 
// OBJECTIVE 3: Communicate btween clients through server by using select() system call.

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

char client_name[MAX_NAME_SZE] = { 0 };   // Char buffer used to store the client name

//Function declaration
int client_create_socket(int* client_sockfd);
int client_recv_from_server(int socket_client, char* recv_msg);
int client_send_to_server(int socket_client, char* send_msg);
int client_build_fdsets(int listenfd, fd_set* readfds, fd_set* writefds, fd_set* exceptfds);
int client_select(int maxval_fd, int listenfd, fd_set* readfds, fd_set* writefds);
int LIST_clients(char* buffer, char* send_buffer);
int CONNECT_to_Client(char* buffer, char* chat_c);
int find_the_client_index_list(int socket);
int find_the_client_index_by_name(char* name);
int Client_decision(int client_sockfd, char* send_buffer);
void server_delete_client(int socket_fd_delete); 

struct client
{
	char client_name[MAX_NAME_SZE];
	char chatwith[MAX_NAME_SZE];
	int chatwith_fd;
	int file_des;
	int port;
	char ip[INET_ADDRSTRLEN];

}detail;

// Data structure to hold the total no of clients
struct server_data
{
	int total_client;
	struct client client_list[NO_OF_CLIENTS];

}server;

int main(int argc, char* argv[])
{
	int client_sockfd = 0;   // Declaring the client_sockfd
	int new_socket = 0;
	int maxval_fd = 0;    // A max sock_fd declared to hold the server_sockfd value

	// Declaring the read,write and except fd's for select()
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;

	// To check the name given from cmd in binary
	if (argc > 2)
	{
		printf("****ERROR : Parameters error****");
		exit(0);
	}

	// Copying the string in client_name typed in cmd
	strcpy(client_name, argv[1]);

	if (client_create_socket(&client_sockfd) != 0) // Function call for setting up of client
	{
		printf("*****ERROR : Socket creation failed*****");
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
	struct sockaddr_in client_address;   // Creating a sockaddr structure to hold the client_addressess

	if ((*client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a client socket() 
	{
		printf("*****ERROR : Socket creation failed*****\n");
		return -1;
	}
	else
	{
		printf("-------Client socket created sucessfully-------\n");
		printf("-----------------------------------------------\n");
	}

	setsockopt(*client_sockfd, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT), &opt_port, sizeof(opt_port));

	// Declaring the family, port and address for sockfd
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(SERVER_PORT);
	client_address.sin_addr.s_addr = INADDR_ANY;


	// Creating a connection status which will connect to a remote host
	if (0 != connect(*client_sockfd, (struct sockaddr*)&client_address, sizeof(struct sockaddr)))
	{
		printf("****ERROR : Connect failed*****");
		return -1;
	}
	else
	{
		printf("------Client socket is ready to connect to server------\n");
		printf("--------------------------------------------\n");
		client_send_to_server(*client_sockfd, client_name);  // Function call for sending the client_name as the client_sockfd is the return type
	}

	return 0;
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
	{
		printf("*****Client Disconnected*****\n");
		server_delete_client(socket_fd_delete);
		close(client_socket);
	}
	else
	{
		printf("*****ERROR: recv() failed*****\n");
	}

	return 0;
}

//  To list all client details
int LIST_clients(char* buffer, char* send_buffer)
{
	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;
	//char buffer[MAX_BUFFER_SIZE];
	int socket;

	index_sender = find_the_client_index_list(socket);
	if (strncmp(buffer, "LIST", 4) == 0) // Providing the list to client by server using cmd 
	{
        // Setting the buffer initially
		memset(buffer, 0, sizeof(send_buffer));
        
        // Creating a loop to iterate over a sending messageG
		for (int val_send = 0; val_send < server.total_client; val_send++)
		{
            // Concaneting the buffer value to client name's 
            printf("List of clients connected\n");
			strcat(buffer, server.client_list[val_send].client_name);
			strcat(buffer, "\n");
		}
		//server_send_to_client(socket, buffer);   // sending it to client
		client_send_to_server(socket, buffer);
	}
	return 0;
}


// Function defination to communicate with all clients
int CONNECT_to_Client(char* buffer, char* chat_c)
{
	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;
	char send_buffer[MAX_BUFFER_SIZE];

	if (strncmp(buffer, "CONNECT", 7) == 0)     // To connect to another client
	{
		sscanf(buffer, "%*[^:]:%s", chat_c);
		strcpy(server.client_list[index_sender].chatwith, chat_c);

		index_receiver = find_the_client_index_by_name(server.client_list[index_sender].chatwith);
		server.client_list[index_sender].chatwith_fd = server.client_list[index_receiver].file_des;
		//server_send_to_client(server.client_list[index_sender].file_des, CONNECTED);
		client_send_to_server(server.client_list[index_sender].file_des, CONNECTED);

	}

	if (strlen(server.client_list[index_sender].chatwith) != 0)
	{
		snprintf(send_buffer, sizeof(send_buffer), "[%s] : %s", server.client_list[index_sender].client_name, buffer);
		printf("-----------------------\n");
		printf("Buffer = %s\n", send_buffer);

		//server_send_to_client(server.client_list[index_sender].chatwith_fd, send_buffer);
		client_send_to_server(server.client_list[index_sender].chatwith_fd, send_buffer);
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


	if ((write_bytes = send(client_socket, send_msg, len, 0)) <= 0)   // Storing the send buffer in serlen
	{
		perror("****ERROR: send() failed*****\n");
		return -1;
	}
	else
	{
		printf("--------ENTER THE APPLICATION--------\n");
		//Client_decision(client_sockfd, send_buffer);
	}
	Client_decision(client_sockfd, send_buffer);
	return write_bytes;
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

	if (action == -1 || action == 0)
	{
		printf("****ERROR: select()****\n");
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
			("Not able to enter the send_to_server\n");
		}
	}
	return 0;
}

/*
//processing the received data from clients
int process_recv_data(int client_socket, char* buffer)
{
	// Creating the chatting and sending buffer to store the message 
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE] = { 0 };

	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;

	//index_sender = find_the_client_index_list(socket); // Storing the index values of client in index_sender

	LIST_clients(buffer, send_buffer);

	CONNECT_to_Client(buffer, chat_c);

	return 0;
}
*/


//find index of the client data structure from client socket
int find_the_client_index_list(int socket)
{
	int index = 0;
	for (int index_val = 0; index_val < server.total_client; index_val++)
	{
		if (server.client_list[index_val].file_des == socket)
		{
			index = index_val;
		}
	}
	return index;
}

//find index of the client data structure from client name
int find_the_client_index_by_name(char* name)
{
	int index = 0;
	for (int index_val1 = 0; index_val1 < server.total_client; index_val1++)
	{
		if (strcmp(server.client_list[index_val1].client_name, name) == 0)
		{
			index = index_val1;
		}
	}
	return index;
}


// Client decision for creating the promt on client side
int Client_decision(int client_sockfd, char* send_buffer)
{
	int choice;
	int option;
	char recv_msg[MAX_BUFFER_SIZE];
	char buffer[MAX_BUFFER_SIZE];
	char chat_c[MAX_BUFFER_SIZE];
	int client_socket;
	int socket_fd_delete;
	
	printf("---------------------------------------------------------------------------------\n");
	printf("\n\
	1. 	Press 1 to know the other client details\n\
	2. 	Press 2 to chat with a client\n\
	3.	Press 3 to exit\n");
	printf("Enter your choice:");
	printf("\n---------------------------------------------------------------------------------\n");
	
	
	scanf("%d", &choice);

	switch (choice)
	{
		case 1:
		{
			printf("LIST all client details\n");
			LIST_clients(buffer, send_buffer);
			break;
		}
		case 2:
		{
			printf("Enter name of client to chat with:\n");
			CONNECT_to_Client(buffer, chat_c);
			break;
		}
		case 3:
		{
			printf("Exit the application\n");
			server_delete_client(socket_fd_delete);
			break;
		}
		// default:
		//  	printf("wrong Input\n");
		// 	break;
	}
	getchar();
		return 0;
}


// Function defination to delete the client
void server_delete_client(int socket_fd_delete) 
{
    int delete = 0;
    int index = 0;

	// Iterating the variable till tital no. of clients
    for(delete = 0; delete < NO_OF_CLIENTS; delete++) 
	{
		// Condition for deleting the client
        if(server.client_list[delete].file_des == socket_fd_delete) 
		{
			printf("-------Socket deleted = [%d]\n",socket_fd_delete);
        }
    }
    close(socket_fd_delete);
}
