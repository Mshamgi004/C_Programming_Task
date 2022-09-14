// Function declaration for client_select
#include "client.h"

int client_select(int maxval_fd,int client_sockfd, fd_set *readfds, fd_set *writefds) 
{
	// Declaring the char buffer for storing the sending and recieving message
	char recv_msgg[MAX_BUFFER_SIZE] ;
	char send_buff[MAX_BUFFER_SIZE] ;
	memset(recv_msgg, 0 ,sizeof(recv_msgg));
	memset(send_buff, 0 ,sizeof(send_buff));
    
	int client_action = select(maxval_fd+1,readfds,writefds,NULL,NULL);   // select() system call 
	
	// To check if select() sys call is working or not
	if(client_action == -1 || client_action == 0) 
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
