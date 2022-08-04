# Makefile for Server


CC = gcc
OBJ = server
CFLAGS = -c -Wall

all:	$(OBJ)	
		$(CC) server_main.c server_socket.c server_select.c server_build_fdsets.c accept_connection.c connection_handler.c recv_from_client.c send_to_client.c process_recv_data.c find_the_client_index_by_name.c find_the_client_index_list.c cleanup.c server_delete_client.c client_handle_list.c  -o server

$(OBJ) :	server_main.o server_socket.o server_select.o server_build_fdsets.o accept_connection.o connection_handler.o recv_from_client.o send_to_client.o process_recv_data.o find_the_client_index_by_name.o find_the_client_index_list.o cleanup.o server_delete_client.o client_handle_list.o  -o $(OBJ)

server_main.o :		server_main.c
		$(CC)	$(CFLAGS)	server_main.c

server_socket.o :		server_socket.c
		$(CC)	$(CFLAGS)	server_socket.c

server_select.o :		server_select.c
		$(CC)	$(CFLAGS)	server_select.c

server_build_fdsets.o :		server_build_fdsets.c
		$(CC)	$(CFLAGS)	server_build_fdsets.c

accept_connection.o :		accept_connection.c
		$(CC)	$(CFLAGS)	accept_connection.c

connection_handler.o :		connection_handler.c
		$(CC)	$(CFLAGS)	connection_handler.c

recv_from_client.o :		recv_from_client.c
		$(CC)	$(CFLAGS)	recv_from_client.c

send_to_client.o :		send_to_client.c
		$(CC)	$(CFLAGS)	send_to_client.c

process_recv_data.o :		process_recv_data.c
		$(CC)	$(CFLAGS)	process_recv_data.c

find_the_client_index_by_name.o :		find_the_client_index_by_name.c
		$(CC)	$(CFLAGS)	find_the_client_index_by_name.c	

find_the_client_index_list.o :		find_the_client_index_list.c
		$(CC)	$(CFLAGS)	find_the_client_index_list.c	

cleanup.o :		cleanup.c
		$(CC)	$(CFLAGS)	cleanup.c		

server_delete_client.o :		server_delete_client.c
		$(CC)	$(CFLAGS)	server_delete_client.c		

client_handle_list.o :		client_handle_list.c
		$(CC)	$(CFLAGS)	client_handle_list.c		


exec:		
		./server

