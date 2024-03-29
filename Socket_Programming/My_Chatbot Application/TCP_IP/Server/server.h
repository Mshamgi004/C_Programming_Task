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
#define CONNECTED "Connected to client....."

//static int server_sockfd;  // Static global variable of server_sockfd

// Structure to hold the name, ip-address, port and file des 
struct client 
{
	char client_name[MAX_NAME_SZE];
	char chatwith[MAX_NAME_SZE];
	int chatwith_fd;
	int file_des;
	int port;
	char ip[INET_ADDRSTRLEN];
	//char client_password[MAX_BUFFER_SIZE];
};

// Data structure to hold the total no of clients
struct server_data 
{
	int total_client;
	struct client client_list[NO_OF_CLIENTS];
};

struct server_data server;
struct client values;



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
//int server_check_detail(char *cleint_buffer);
//void display();
//int get_client_details(char *client_buffer, char *ip, char *port_number);
//int get_client_details(char *client_buffer, char *ip, char *port_numebr);
int get_client_details(char *client_buffer, char *ip, char *port_number,int new_server_sockfd);
void server_delete_client(int client_socket);
void cleanup(void);
