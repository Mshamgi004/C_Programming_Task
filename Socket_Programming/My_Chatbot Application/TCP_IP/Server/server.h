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

//MACROS
#define NO_OF_CLIENTS 10
#define PORT 8000
#define BACKLOG 5
#define MAX_NAME_SIZE 20
#define MAX_BUFFER_SIZE 1024

static int server_sockfd = 0;    // Static global variable of server_sockfd

// Structure to hold the name, ip-address, port and file des 
struct client 
{
    char client_name[MAX_NAME_SIZE];
    char chatwith[MAX_NAME_SZE];
    int chatwith_fd;
    int file_des;
    int port;
    char ip[INET_ADDRSTRLEN];
};

// Data structure to hold the total no of clients
struct server_data 
{
    	int total_client;
    	struct client client_list[NO_OF_CLIENTS];
}server;

// Function declaration
int setup_server(int *server_sockfd);
int accept_new_connection(int server_sockfd, int *new_server_sockfd);
void handle_connection(struct sockaddr_in client_address, int new_server_sockfd);
int recv_from_client(int client_socket, char *recv_msg);
int send_to_client(int client_socket, char *send_msg);
int server_build_fdsets(int server_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int server_select(int maxval_fd, int server_sockfd, fd_set *readfds, fd_set *writefds);
/*
 Working 
int process_recv_data(int socket,char *client_buffer);
int find_the_client_index_list(int socket);
int find_the_client_index_by_name(char *client_name);
*/
