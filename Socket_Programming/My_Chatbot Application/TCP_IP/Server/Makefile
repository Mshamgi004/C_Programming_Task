CC = gcc
OBJ = server

all:			
		$(CC) server_main.c server_socket.c server_select.c server_build_fdsets.c accept_connection.c connection_handler.c recv_from_client.c send_to_client.c -o server

exec:		
		./server
