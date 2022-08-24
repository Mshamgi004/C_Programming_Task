// Use of Struture_LIst.h so as to simplify the file operation

// Use of structure 
struct client_List
{
	char client_name[1000];
	char chatwith[1000];
	int chatwith_fd;
	int file_des;
	int port;
	char ip[INET_ADDRSTRLEN];

};

/*
// Link list of structure client to accces the name, ip and port
struct link_list
{
    struct client_List file[100];
};
*/
