################################################################### Makefile for Client side ########################################################################

CC = gcc
OBJ = client
CFLAGS = -c -Wall

all:		
		$(CC) client_main.c client_socket.c client_select.c client_build_fdsets.c client_send_to_server.c client_recv_from_server.c Client_decision.c  -o client

$(OBJ) :	client_main.o client_socket.o client_select.o client_build_fdsets.o client_send_to_server.o client_recv_from_server.o Client_decision.o  -o $(OBJ)

client_main.o :		client_main.c
		$(CC)	$(CFLAGS)	client_main.c

client_socket.o :		client_socket.c
		$(CC)	$(CFLAGS)	client_socket.c

client_select.o :		client_select.c
		$(CC)	$(CFLAGS)	client_select.c

client_build_fdsets.o :		client_build_fdsets.c
		$(CC)	$(CFLAGS)	client_build_fdsets.c

#LIST_Client.o :		LIST_Client.c
#		$(CC)	$(CFLAGS)	LIST_Client.c

#CONNECT_to_Client.o :		CONNECT_to_Client.c
#		$(CC)	$(CFLAGS)	CONNECT_to_Client.c

client_recv_from_server.o :		client_recv_from_server.c
		$(CC)	$(CFLAGS)	client_recv_from_server.c

client_send_to_server.o :		client_send_to_server.c
		$(CC)	$(CFLAGS)	client_send_to_server.c


#find_the_client_index_by_name.o :		find_the_client_index_by_name.c
#		$(CC)	$(CFLAGS)	find_the_client_index_by_name.c	

#find_the_client_index_list.o :		find_the_client_index_list.c
#		$(CC)	$(CFLAGS)	find_the_client_index_list.c	

#server_delete_client.o :		server_delete_client.c
#		$(CC)	$(CFLAGS)	server_delete_client.c		

Client_decision.o :		Client_decision.c
		$(CC)	$(CFLAGS)	Client_decision.c		


exec:		
		./client

