#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<netdb.h>

#define PORT 8000
#define SERVERERROR (-1)
#define BACKLOG 4
#define LENGTH_NAME 32


// Function Prototypes 
int setup_server(int port, int backlog);
int accept_new_connection(int server_sockfd);
int check(int exp, const char *msg);
void *handle_connection(int client_sockfd);

