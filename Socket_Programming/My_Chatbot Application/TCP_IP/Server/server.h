//Header files
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// #include<sys/socket.h>
// #include<sys/types.h>
// #include<sys/select.h>

// #include<netinet/in.h>
// #include<arpa/inet.h>

// #include<unistd.h>
// #include<fcntl.h>

#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#endif

// MACROS
#define SERVER_PORT 9000
#define MAX_NAME_SZE 20
#define MAX_BUFFER_SIZE 1024
#define NO_OF_CLIENTS 3
#define CONNECTED "Client already Connected...."

char client_name[MAX_NAME_SZE];   // Char buffer used to store the client name

//Function declaration
int client_create_socket(int *client_sockfd);
int client_recv_from_server(int socket_client, char *recv_msg);
int client_send_to_server(int socket_client, char *send_msg);
int client_build_fdsets(int listenfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int client_select(int maxval_fd, int client_sockfd, fd_set *readfds, fd_set *writefds);
int LIST_clients(char* buffer, char* send_buffer);
int CONNECT_to_Client(char* buffer, char* chat_c);
int find_the_client_index_list(int socket);
int find_the_client_index_by_name(char* name);
int Client_decision(int client_sockfd, char* send_buffer);
void server_delete_client(int socket_fd_delete); 

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

/*
//Header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/select.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<fcntl.h>

#include "Structure_list.h"

//Macros
#define SERVER_PORT 9000
#define LISTEN_BACKLOG 5
#define MAX_NAME_SZE 20
#define NO_OF_CLIENTS 10
#define MAX_BUFFER_SIZE 1024
#define CONNECTED "Connected ....."

//static int server_sockfd = 0;  // Static global variable of server_sockfd

// Structure to hold the name, ip-address, port and file des 
// Structure to hold the name, ip-address, port and file des 
struct client_List
{
	char client_name[MAX_NAME_SZE];
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
	struct client_List client_list[NO_OF_CLIENTS];
};

struct client_List values;
struct server_data server;

//Function declarations
int setup_server(int *server_sockfd);
int accept_new_connection(int server_sockfd, int *new_server_sockfd);
int server_recv_from_client(int socket_client, char *recv_msg);
int server_send_to_client(int socket_client, char *send_msg);
int server_build_fdsets(int server_sockfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int server_select(int maxval_fd, int server_sockfd, fd_set *readfds, fd_set *writefds);
void handle_connection(struct sockaddr_in client_information, int new_server_sockfd);
int process_recv_data(int socket,char *buffer);
int find_the_client_index_list(int socket);
int find_the_client_index_by_name(char *name);
void client_handle_list(char* client_buffer, char* ip, char* port_number);
int get_client_name(char *client_buffer);
void server_delete_client(int socket_fd_delete);
void cleanup(void);
*/
