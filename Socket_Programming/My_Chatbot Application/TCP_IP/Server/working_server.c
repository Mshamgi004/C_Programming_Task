//-----------------------------------MY CHATBOT APPLICATION-----------------------------------//
/*
 TASK: TO CREATE A CHATBOT APPLICATION WHICH WILL COMMUNICATE BETWEEN TWO CLIENTS.
	   BY DOING SO THE SERVER WILL STORE THE CLIENT DETAILS SUCH AS THE  NAME, fd's , PORT  & IP ADDRESS IN A clientlist.txt file.
*/

// OBJECTIVE 1: Maintain the connected client details in server's data structure
// OBJECTIVE 2: Respond to command like LIST and CONNECT 
// OBJECTIVE 3: Communicate between clients through server by using select() system call.


//STEP 1 : creating a socket file descriptor
//STEP 2 : binding the socket with port and IP
//STEP 3 : listening to the client requests
//STEP 4 : accept the TCP conenction from the client side
//STEP 5 : recv/send for data communication
//STEP 6 : closing the file descriptor


//TASK-1 --> maintain the connected clients details in server data structure
//TASK-3 --> respond to command like LIST and CONNECT from clients
//TASK-4 --> communication between clients through server 

// Server side


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

//Macros
#define SERVER_PORT 9000
#define LISTEN_BACKLOG 5
#define MAX_NAME_SZE 20
#define NO_OF_CLIENTS 10
#define MAX_BUFFER_SIZE 1024
#define MAX 10000
#define CONNECTED "Connected ....."

static int server_sockfd = 0;  // Static global variable of server_sockfd

// Structure to hold the name, ip-address, port and file des 
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

//Function declarations
int setup_server(int* server_sockfd);
int accept_new_connection(int server_sockfd, int* new_server_sockfd);
int server_recv_from_client(int socket_client, char* recv_msg);
int server_send_to_client(int socket_client, char* send_msg);
int server_build_fdsets(int server_sockfd, fd_set* readfds, fd_set* writefds, fd_set* exceptfds);
int server_select(int maxval_fd, int server_sockfd, fd_set* readfds, fd_set* writefds);
void handle_connection(struct sockaddr_in client_information, int new_server_sockfd);
int process_recv_data(int socket, char* buffer);
int find_the_client_index_list(int socket);
int find_the_client_index_by_name(char* name);
void client_handle_list(char* client_buffer, char* ip, char* port_number);
void server_delete_client(int client_socket);
void cleanup(void);


int main()
{
	struct server_data server;
	// Declaring the read ,write and except fd's for select()	
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;

	int maxval_fd = 0;   // A max sock_fd declared to hold the server_sockfd value

	memset(&server, 0, sizeof(struct server_data));   // Clearing the structure to hold the total clients
	printf("--------SERVER STARTED--------!!!\n");
	printf("---------------------------------\n");

	if (setup_server(&server_sockfd) != 0)   // Function call for setting up of server
	{
		printf("*****ERROR : Creation socket failed******");
		exit(0);
	}
	else
	{
		maxval_fd = server_sockfd;   // Equalising the max_fd to server_fd
	}

	while (1)
	{
		maxval_fd = server_build_fdsets(server_sockfd, &readfds, &writefds, &exceptfds);   // server_socket will build the fd_sets and will return the maxval_fd 
		server_select(maxval_fd, server_sockfd, &readfds, &writefds);     // Function call for select()
	}
	printf("Storing the data");
	//client_handle_list(detail);

	cleanup();
	printf("Bye From server\n");

	return 0;
}


// Function call to setup the server socket fd
int setup_server(int* server_sockfd)
{
	int opt_port = 1;
	struct sockaddr_in server_address;  // Structure describing the internet sockaddr

	if ((*server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a server socket         
	{
		perror("*****ERROR : Socket creation failed******");
		return -1;
	}
	else
	{
		printf("-------Server socket created sucessfully-------\n");
		printf("-----------------------------------------------\n");
	}

	// Declaring the family, port and address for sockfd
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(SERVER_PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	setsockopt(*server_sockfd, SOL_SOCKET, (SO_REUSEADDR | SO_REUSEPORT), &opt_port, sizeof(opt_port));   // Focrcefully sets the port

	if (0 != bind(*server_sockfd, (struct sockaddr*)&server_address, sizeof(struct sockaddr)))   // Binding the socket
	{
		printf("******ERROR : Socket bind failed******");
		return -1;
	}
	else
	{
		printf("------Socket Binded successfully-----\n");
		printf("-------------------------------------\n");
	}

	if (0 != listen(*server_sockfd, LISTEN_BACKLOG))    // Listening the incoming connection
	{
		printf("******ERROR : socket listen failed******");
		return -1;
	}
	else
	{
		printf("------Server socket is ready to listen------\n");
		printf("--------------------------------------------\n");
	}
	return 0;

}

// Function defination for accepting the new connection
int accept_new_connection(int server_sockfd, int* new_server_sockfd)
{
	struct sockaddr_in client_address;  // struct sockaddr_in in client_address
	int server_length;    // Creating a variable -> server_length
	server_length = sizeof(struct sockaddr);   // assigning the address to the variable server_length

	bzero(&client_address, sizeof(client_address));  // Clearing the client address initially

	if ((*new_server_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &server_length)) < 0)  // Accepting the pending connection
	{
		printf("******ERROR :Accept failed*******");
		return -1;
	}
	else
	{
		printf("----Socket is ready to accept the incoming client details----\n");
		printf("-------------------------------------------------------------\n");
		handle_connection(client_address, *new_server_sockfd);  // Function call to populate the ip and port for handling the connection 
	}

	return 0;
}

// Function defination for recieving the name from client
int server_recv_from_client(int client_socket, char* recv_msg)
{
	int read_bytes = 0;   // Variable use to store the read_bytes
	memset(recv_msg, 0, strlen(recv_msg));  // Clearing the buffer initially

	if ((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0)) > 0)
	{
		process_recv_data(client_socket, recv_msg);
	}
	else if (read_bytes == 0)
	{
		printf("*****Client Disconnected*****\n");
		server_delete_client(client_socket);
	}
	else
	{
		printf("*****ERROR: recv() failed*****\n");
	}

	return 0;
}

// Function defination to send the message to client
int server_send_to_client(int client_socket, char* send_msg)
{
	int write_bytes = 0;   // Variable used for writing the message
	int server_length;   // Creating a variable -> server_length  
	server_length = strlen(send_msg);   // assigning the address to the variable server_length

	if ((write_bytes = send(client_socket, send_msg, server_length, 0)) > 0)   // send() message
	{

		printf("\n[CLIENT : %d]", client_socket);
	}
	else
	{
		perror("*****Error : send failed*****");
		return -1;
	}
	return write_bytes;
}

// Function defination of server_build_fdsets
int server_build_fdsets(int server_sockfd, fd_set* readfds, fd_set* writefds, fd_set* exceptfds)
{
	int maxval_fd = server_sockfd;   // Keeping the value of server_sockfd = maxval_fd

	FD_ZERO(readfds);  //Initializing readfds with zero value
	FD_SET(server_sockfd, readfds);  // Setting the server_sockfd as readfds
	FD_SET(STDIN_FILENO, readfds);   // Setting the readfds to a 0 value so as to capture in readfdsq
	fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);   // fcntl() used to nonblocking the application from the cmd 

	// Loop use to fill the readfds with all the socket fd's 
	for (int val = 0; val < server.total_client; val++)
	{
		FD_SET(server.client_list[val].file_des, readfds);
		maxval_fd++;
	}
	return maxval_fd;
}

// Function defination of server_select
int server_select(int maxval_fd, int server_sockfd, fd_set* readfds, fd_set* writefds)
{
	// Declaring the new server sock_fd and char buffer for storing the sending and recieving message
	int new_server_sockfd = 0;
	char recv_buff[MAX_BUFFER_SIZE];
	char send_buff[MAX_BUFFER_SIZE];

	// To fill the send and recv buffer with string input
	memset(recv_buff, 0, sizeof(recv_buff));
	memset(send_buff, 0, sizeof(send_buff));

	int select_action = select(maxval_fd + 1, readfds, writefds, NULL, NULL);  // select() system call 

	// Checking for the working of select() system call
	if (select_action == -1 || select_action == 0)
	{
		printf("*****ERROR : select()*****");
		exit(0);
	}

	// To check the fd is set so as to accept the new connection request
	if (FD_ISSET(server_sockfd, readfds))
	{
		// Then accecpt the new connection
		accept_new_connection(server_sockfd, &new_server_sockfd);
		printf("New socket created = %d\n", new_server_sockfd);
	}

	// To check the fd is set for sending the message so as to broadcast the message to all clients
	if (FD_ISSET(STDIN_FILENO, readfds))
	{
		// To check for message to be send
		if (read(0, send_buff, sizeof(send_buff)) > 0)
		{
			// Then fill the send_buff with message
			for (int val1 = 0; val1 < server.total_client; val1++)
				server_send_to_client(server.client_list[val1].file_des, send_buff);
		}
	}

	for (int val2 = 0; val2 < server.total_client; val2++)
	{
		// To check for all the clients in the file des inside the readfds
		if (FD_ISSET(server.client_list[val2].file_des, readfds))
		{
			// If its present in readfds then it will recieve the message
			server_recv_from_client(server.client_list[val2].file_des, recv_buff);
		}
	}
	return 0;
}


// Function defination to delete the client
void server_delete_client(int socket_fd_delete)
{
	int delete = 0;
	int index = 0;

	// Iterating the variable till tital no. of clients
	for (delete = 0; delete < NO_OF_CLIENTS; delete++)
	{
		// Condition for deleting the client
		if (server.client_list[delete].file_des == socket_fd_delete)
		{
			server.total_client--;
			printf("-------Socket deleted = [%d]\n", socket_fd_delete);
		}
	}

	close(socket_fd_delete);
}


// Function defination to handle the client
void handle_connection(struct sockaddr_in client_information, int new_server_sockfd)
{
	//get the name, IP Address and port no: client 
	char ip[INET_ADDRSTRLEN] = { 0 };  // char buffer to store the ip address of connected clients
	char client_buffer[MAX_BUFFER_SIZE] = { 0 };   // char buffer to store the name of connected clients
	int port = ntohs(client_information.sin_port);
	char port_number[MAX_BUFFER_SIZE];
	
	inet_ntop(AF_INET, &(client_information.sin_addr), ip, INET_ADDRSTRLEN);
	
	server_recv_from_client(new_server_sockfd, client_buffer);  // Function call to recieve the name from client

	printf("---------------------------------\n");
	printf("\n[CLIENT NAME] : %s\n", client_buffer);
	printf("---------------------------------\n");
	printf("\n[IP ADDRESS]  : %s\n", ip);
	printf("---------------------------------\n");
	sprintf(port_number,"%d",port);
	printf("\n[Port NUMBER] : %s\n",port_number); 
	printf("---------------------------------\n");


	printf("Storing client data in CLIENT_INFO.txt\n");

	client_handle_list(client_buffer, ip, port_number);
	// To check for the no. of clients connected 
	if (server.total_client >= NO_OF_CLIENTS)
	{
		printf("****ERROR : No more space for client to save****\n");
	}

	//populate the new client data and saving it in client_list
	strncpy(server.client_list[server.total_client].client_name, client_buffer, strlen(client_buffer));
	server.client_list[server.total_client].port = port;
	strcpy(server.client_list[server.total_client].ip, ip);
	server.client_list[server.total_client].file_des = new_server_sockfd;

	server.total_client++;

}

//processing the received data from clients
int process_recv_data(int socket, char* buffer)
{
	// Creating the chatting and sending buffer to store the message 
	char chat_c[MAX_BUFFER_SIZE];
	char send_buffer[MAX_BUFFER_SIZE] = { 0 };

	int index_sender = 0;    // Variable for index_sender verifier
	int index_receiver = 0;  // Variable for index_reciever verifier
	int len = 0;

	index_sender = find_the_client_index_list(socket); // Storing the index values of client in index_sender

	
	if (strncmp(buffer, "LIST", 4) == 0) // Providing the list to client by server using cmd 
	{
		// Setting the buffer initially
		memset(buffer, 0, sizeof(send_buffer));

		// Creating a loop to iterate over a sending message
		for (int val_send = 0; val_send < server.total_client; val_send++)
		{
			// Concaneting the buffer value to client name's 
			strcat(buffer, server.client_list[val_send].client_name);
			strcat(buffer, "&");
		}
		server_send_to_client(socket, buffer);   // sending it to client
		goto out;
	}
	// else
	// {
	// 	printf("****Can't list the items*****\n");
	// }

	if (strncmp(buffer, "CONNECT", 7) == 0)     // To connect to another client
	{
		sscanf(buffer, "%*[^:]:%s", chat_c);
		strcpy(server.client_list[index_sender].chatwith, chat_c);

		index_receiver = find_the_client_index_by_name(server.client_list[index_sender].chatwith);
		server.client_list[index_sender].chatwith_fd = server.client_list[index_receiver].file_des;
		server_send_to_client(server.client_list[index_sender].file_des, CONNECTED);
		goto out;
	}

	if (strlen(server.client_list[index_sender].chatwith) != 0)
	{
		snprintf(send_buffer, sizeof(send_buffer), "[%s] : %s", server.client_list[index_sender].client_name, buffer);
		printf("-----------------------\n");
		printf("Buffer = %s\n", send_buffer);

		server_send_to_client(server.client_list[index_sender].chatwith_fd, send_buffer);
	}

out:
	return 0;
}

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

void cleanup()
{
	close(server_sockfd);
	for (int i = 0; i < server.total_client; i++)
	{
		close(server.client_list[i].file_des);
	}
}


void client_handle_list(char* client_buffer, char* ip, char* port_number)
{
	int val_read;
	FILE* fptr;
	fptr = fopen("CLIENT_INFO.txt", "a+");
	if (fptr == NULL)
	{
		fprintf(stderr, "\nError to open the file\n");
		exit(1);
	}
	else
	{
		printf("FILE OPENED SUCCESSFULLY\n");
	}

	//fwrite (&detail, sizeof(struct client), 1, fptr);
	if (strlen(client_buffer) > 0)
	{
		// writing in the file using fputs()
		fputs(client_buffer, fptr);
		fputs("\n", fptr);
	}
	else
	{
		printf("Not able to print the name\n");
	}

	if (strlen(ip) > 0)
	{
		// writing in the file using fputs()
		fputs(ip, fptr);
		fputs("\n", fptr);
	}
	else
	{
		printf("Not able to print the ip address\n");
	}
	if(strlen(port_number) > 0)
	{
		// writing in the file using fputs()
		fputs(port_number, fptr) ;
		fputs("\n", fptr) ;
	}
	else
	{
		printf("Not able to print the port no\n");
	}
	
	printf("-----CONTENT IN THE FILE ARE-------\n");
 
    while (fgets(client_buffer,MAX_BUFFER_SIZE, fptr) != NULL) 
	{
        printf("NAME = %s\n", client_buffer);
    }
	while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
	{
		printf("IP ADDRESS = %s\n", ip);
	}
	while(fgets(port_number,MAX_BUFFER_SIZE,fptr) != NULL)
	{
		printf("Port_number = %s\n", port_number);
	}

	
	fclose (fptr);
}
