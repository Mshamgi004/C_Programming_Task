//-----------------------------------MY CHATBOT APPLICATION-----------------------------------//
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


// Client side 


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

char client_name[MAX_NAME_SZE] = {0};   // Char buffer used to store the client name

//Function declaration
int client_create_socket(int *client_sockfd);
int client_recv_from_server(int socket_client, char *recv_msg);
int client_send_to_server(int socket_client, char *send_msg);
int client_build_fdsets(int listenfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int client_select(int maxval_fd, int listenfd, fd_set *readfds, fd_set *writefds);

int main(int argc, char *argv[]) 
{
	int client_sockfd = 0;   // Declaring the client_sockfd
	int new_socket = 0;   
	int maxval_fd = 0;    // A max sock_fd declared to hold the server_sockfd value

	// Declaring the read,write and except fd's for select()
	fd_set readfds;    
	fd_set writefds;
	fd_set exceptfds;

	// To check the name given from cmd in binary
	if(argc > 2) 
	{
        printf("****ERROR : Parameters error****");
        exit(0);
    }
    
	// Copying the string in client_name typed in cmd
    strcpy(client_name,argv[1]);

	if(client_create_socket(&client_sockfd) != 0) // Function call for setting up of client
	{
		printf("*****ERROR : Socket creation failed*****");
        exit(0);
    }
	else
	{
		maxval_fd = client_sockfd;   // Equalising the maxval_fd to client_fd
  	}
	
	while(1) 
	{
		maxval_fd = client_build_fdsets(client_sockfd, &readfds, &writefds, &exceptfds);   // server_socket will build the fd_sets and will return the maxval_fd
		client_select(maxval_fd,client_sockfd, &readfds, &writefds);     // Function call for select()
    } 
	close(client_sockfd);   // Closing the client_sockfd
	
	return 0;
}


// Function defination for setting up of client socket
int client_create_socket(int *client_sockfd) 
{
	int opt_port = 1;
	struct sockaddr_in client_address;   // Creating a sockaddr structure to hold the client_addressess

	if((*client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)   // Creating a client socket() 
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
    if( 0 != connect(*client_sockfd,(struct sockaddr *)&client_address,sizeof(struct sockaddr))) 
	{
        printf("****ERROR : Connect failed*****");
        return -1;
    }
	else
	{
		printf("------Client socket is ready to connect to server------\n");
		printf("--------------------------------------------\n");
		client_send_to_server(*client_sockfd,client_name);  // Function call for sending the client_name as the client_sockfd is the return type
	}
	
    return 0;
}

// Function defination to recv message from server
int client_recv_from_server(int client_socket, char *recv_msg) 
{
	int read_bytes = 0;    // Variable use to store the read_bytes 

	if((read_bytes = recv(client_socket, recv_msg, MAX_BUFFER_SIZE, 0)) > 0)   // recv() message from server
	{
		printf("%s\n",recv_msg);
	}
    else if(read_bytes == 0) 
    {
		printf("*****Client Disconnected*****\n");
		close(client_socket);
	}
    else 
    {
		printf("*****ERROR: recv() failed*****\n");
    }
	
	return 0;
}

// Function defination of sending message to the server
int client_send_to_server(int client_socket, char *send_msg) 
{
	int write_bytes = 0;   // Variable used for writing the message
	int len = strlen(send_msg);    // Declaring a socklen_t variable -> serlen

	if((write_bytes = send(client_socket, send_msg, len, 0)) <= 0)   // Storing the send buffer in serlen
	{
		perror("****ERROR: send() failed*****\n");
		return -1;
	}
	return write_bytes;
}

// Function defination for client_build_fdsets
int client_build_fdsets(int client_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds) 
{
	int maxval_fd = client_sockfd;   // Keeping the value of client_sockfd = maxval_fd

	FD_ZERO(readfds);     // Initializing readfds with zero value
	FD_SET(client_sockfd, readfds);    // Setting the client_sockfd as readfds
	FD_SET(client_sockfd, writefds);   // Setting the writefds to 0 so as to recive the commands from cmd
	FD_SET(STDIN_FILENO,readfds);   // Setting the readfds to 0 so as to recive the commands from cmd
	fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);   // fcntl() used to nonblocking the application from the cmd 

	return maxval_fd;
}

// Function declaration for client_select
int client_select(int maxval_fd,int client_sockfd, fd_set *readfds, fd_set *writefds) 
{
	// Declaring the char buffer for storing the sending and recieving message
	char recv_msgg[MAX_BUFFER_SIZE] ;
	char send_buff[MAX_BUFFER_SIZE] ;
	memset(recv_msgg, 0 ,sizeof(recv_msgg));
	memset(send_buff, 0 ,sizeof(send_buff));
    
	int action = select(maxval_fd+1,readfds,writefds,NULL,NULL);   // select() system call 

	if(action == -1 || action == 0) 
	{
        printf("****ERROR: select()****\n");
        exit(0);
    }
	// To check for all the clients in the file des inside the readfds
    if(FD_ISSET(client_sockfd,readfds)) 
    {	
     	// If its present in readfds then it will recieve the message
        client_recv_from_server(client_sockfd,recv_msgg);             
    }
	// To check the fd is set for sending the message so as to broadcast the message to all clients
    if(FD_ISSET(STDIN_FILENO,readfds)) 
    {
		if(read(0,send_buff,sizeof(send_buff)) > 0) 
		{
            client_send_to_server(client_sockfd,send_buff);
        }
    }
    return 0;
}

