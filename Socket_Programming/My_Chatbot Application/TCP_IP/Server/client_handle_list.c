void client_handle_list(char* client_buffer, char* ip, char* port_number)
{
	int wordExist = 0;
	char search[MAX_BUFFER_SIZE];

	FILE* fptr;
	fptr = fopen("CLIENT_INFO.txt", "w");
	if (fptr == NULL)
	{
		fprintf(stderr, "\nError to open the file\n");
		exit(1);
	}
	else
	{
		printf("----FILE OPENED SUCCESSFULLY----\n");
	}

	//fwrite (&detail, sizeof(struct client), 1, fptr);
	if (strlen(client_buffer) > 0)
	{
		// writing in the file using fputs()
		fputs(client_buffer, fptr);
		fputs("\n", fptr);
	}
	else
	{
		printf("Not able to print the name\n");
	}

	// if (strlen(ip) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(ip, fptr);
	// 	fputs("\n", fptr);
	// }
	// else
	// {
	// 	printf("Not able to print the ip address\n");
	// }
	// if(strlen(port_number) > 0)
	// {
	// 	// writing in the file using fputs()
	// 	fputs(port_number, fptr) ;
	// 	fputs("\n", fptr) ;
	// }
	// else
	// {
	// 	printf("Not able to print the port no\n");
	// }
	fclose(fptr);

	fptr = fopen("CLIENT_INFO.txt", "r");
	if(fptr == NULL)
	{
		fprintf(stderr,"\nError to open the file\n");
		exit(1);
	}
	else
	{
		printf("Contents in file are being readed\n");
	}
	
	/////////////////////////////////////////////BUILDING THE LOGIC : WORKING ///////////////////////////////////////////////
	//printf("NAME = %s\n", client_buffer);
	
	
	while (fscanf(fptr,"%s", client_buffer) != EOF) 
	{
        //printf("NAME = %s\n", client_buffer);

		printf("Comparing the names\n");
		if(strcmp(client_buffer,search) == 0)
		{
			// wordExist = 1;
			// break;
			printf("Client name stored\n");
		}
		// fclose(fptr);

		// if(wordExist == 1)
		// {	
		// 	printf("HIUHGES\n");
		// 	printf("Client name already registered\n");
		// }
		else
		{
			fptr = fopen("CLIENT_INFO.txt", "w");
			if(fptr == NULL)
			{
				fprintf(stderr, "\nError to open the file\n");
			}
			else
			{
				printf("Name added successfully\n");
			}

			if (strlen(client_buffer) > 0)
			{
				// writing in the file using fputs()
				fputs(client_buffer, fptr);
				fputs("\n", fptr);
			}
			else
			{
				printf("Not able to print the name\n");
			}
			printf("NEW CLIENT ADDED\n");

		}
    }
	// while(fgets(ip,INET_ADDRSTRLEN,fptr) != NULL)
	// {
	// 	printf("IP ADDRESS = %s\n", ip);
	// }
	// while(fgets(port_number,MAX_BUFFER_SIZE,fptr))
	// {
	// 	printf("Comparing the strings\n");
	// 	if(strstr(port_number,search) != NULL)
	// 	{
	// 		wordExist = 1;
	// 		break;
	// 	}
	// 	// fclose(fptr);

	// 	if(wordExist == 1)
	// 	{
	// 		printf("HIIIIIII");
	// 		printf("Client port no: already registered\n");
	// 	}
	// 	else
	// 	{
	// 		fptr = fopen("CLIENT_INFO.txt", "a+");
	// 		if(fptr == NULL)
	// 		{
	// 			fprintf(stderr, "\nError to open the file\n");
	// 		}
	// 		else
	// 		{
	// 			printf("Port no added successfully\n");
	// 		}
	// 	}
    //}
	fclose (fptr);
}
