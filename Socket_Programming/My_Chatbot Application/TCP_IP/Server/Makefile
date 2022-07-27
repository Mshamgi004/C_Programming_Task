CC = gcc
OBJ = server

all:			
		$(CC) server_main.c server_socket.c server_select.c server_build_fdsets.c accept_connection.c connection_handler.c recv_from_client.c send_to_client.c process_recv_data.c find_the_client_index_by_name.c find_the_client_index_list.c cleanup.c  -o server

exec:		
		./server
