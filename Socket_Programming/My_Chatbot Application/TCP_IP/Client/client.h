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
#define PORT 8000
#define MAX_NAME_SZE 20
#define MAX_BUFFER_SIZE 1024

char client_name[MAX_BUFFER_SIZE] = {0};

int setup_client(int *client_sockfd);
void client_recv_from_server(int client_socket, char *recv_msg);
void client_send_to_server(int client_socket, char *send_msg);
int server_build_fdsets(int client_sockfd,fd_set *readfds,fd_set *writefds,fd_set *exceptfds);
int client_select(int maxval_fd, int client_sockfd,fd_set *readfds,fd_set *writefds);
