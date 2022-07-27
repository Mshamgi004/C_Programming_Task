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

char client_name[MAX_NAME_SZE];   // Char buffer used to store the client name

//Function declaration
int client_create_socket(int *client_sockfd);
int client_recv_from_server(int socket_client, char *recv_msg);
int client_send_to_server(int socket_client, char *send_msg);
int client_build_fdsets(int listenfd, fd_set *readfds, fd_set *writefds, fd_set *exceptfds);
int client_select(int maxval_fd, int listenfd, fd_set *readfds, fd_set *writefds);
