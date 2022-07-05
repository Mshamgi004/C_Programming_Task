// Socket Programming application
// Task: To buid a chat-box between Server and Client using TCP which sends message continuosly and terminates by passing a specific string.


// Inclusion of header files and function prototype

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include <netdb.h>

#define PORT 8000

void server_func(int new_server_sockfd);      // Function prototype of server_func.
