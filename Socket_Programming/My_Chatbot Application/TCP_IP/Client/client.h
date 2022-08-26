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

//char client_name[MAX_NAME_SZE] = { 0 };   // Char buffer used to store the client name

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
