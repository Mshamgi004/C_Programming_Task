// Use of Struture_LIst.h so as to simplify the file operation

// Use of structure 
struct client 
{
	char client_name[1000];
	int port;
	char ip[INET_ADDRSTRLEN];

};

// Link list of structure client to accces the name, ip and port
struct link_list
{
    struct client file;
};
