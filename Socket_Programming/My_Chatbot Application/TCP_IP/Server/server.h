
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
#define BACKLOG 5
#define MAX_NAME_SIZE 20
#define MAX_BUFFER_SIZE 1024


static int server_sockfd = 0;

// Data structure
struct client 
{
    char client_name[MAX_NAME_SIZE];
    int file_des;
    int port;
    char ip[INET_ADDRSTRLEN];
};

struct server_data 
{
    	int total_client;
    	struct client client_list[NO_OF_CLIENTS];
}server;

// Function declaration
int setup_server(int *server_sockfd);
int accept_new_connection(int server_sockfd, int *new_server_sockfd);
void handle_connection(struct sockaddr_in client_address, int new_server_sockfd);
void recv_from_client(int client_socket, char *recv_msg);
void send_to_client(int client_socket, char *send_msg);
void client_handle_list(char client_name);

int server_build_fdsets(int server_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int server_select(int maxval_fd, int server_sockfd, fd_set *readfds, fd_set *writefds);

struct sockaddr_in server_address, client_address;



