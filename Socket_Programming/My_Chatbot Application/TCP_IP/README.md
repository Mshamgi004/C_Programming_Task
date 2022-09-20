                                                                       MY_CHATBOT APPLICATION

********************************************************************************************************************************************************************
 TASK: TO CREATE A CHATBOT APPLICATION WHICH WILL COMMUNICATE BETWEEN TWO CLIENTS. BY DOING SO THE SERVER WILL STORE THE CLIENT DETAILS SUCH AS THE NAME, IP ADDRESS, PORT NUMBER AND FILE DESCRIPTOR IN A CLIENT_INFO.txt file.
********************************************************************************************************************************************************************

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
LIST OF OBJECTIVES

#1:  Maintain the connected client details in server's data structure and store them in a text file.
#2:  Respond to commands like LIST and CONNECT 
#3:  Communicate between clients through server by using select() system call.
#4:  Create a prompt on client side so as to make it user friendly application for clients.
#5:  Client should communicate with the other connected clients whose data are stored in Server side of CLIENT_INFO.txt. And Client should have the                      flexibility to communicate with any connected client.
#6:  The CLIENT_INFO.txt has the details of the connected client's such as the name, IP Address, port number and their file descriptor. And there should be updation 
     in the .text file after every new entry of client.
 


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
LIST OF OUTPUTS ON TERMINAL OF UBUNTU 18.04 LTS

#1 : SERVER SIDE CONNECTION

Command : ./server

![Screenshot from 2022-09-20 14-42-45](https://user-images.githubusercontent.com/98145598/191218666-da7662c4-77aa-45c7-9653-6c12ed78e8d6.png)

#2 : CLIENT SIDE CONNECTION & PROMPT SHOWCASE FOR TAKING REQUIRED ACTION

COMMAND : ./client (Name of client).
        Note: Using command line argument for naming of the client

![Screenshot from 2022-09-20 14-48-07](https://user-images.githubusercontent.com/98145598/191219978-2ab313c6-65aa-4765-8469-a1ccd4cf6053.png)
![Screenshot from 2022-09-20 13-16-10](https://user-images.githubusercontent.com/98145598/191220072-8a5f550d-7bb0-4e4c-b014-ef7cb7233335.png)

#3 : SERVER SIDE SHOWCASE OF CONNECTED CLIENT INFORMATION

![Screenshot from 2022-09-20 14-53-44](https://user-images.githubusercontent.com/98145598/191221278-d823ac5e-aec9-4c7a-a91d-84bda89ee83c.png)

#4 : LISTING THE CONNECTED CLIENT NAMES ON CLIENT SIDE SO AS TO COMMUNICATE

![Screenshot from 2022-09-20 13-21-53](https://user-images.githubusercontent.com/98145598/191231852-58039b04-df42-466f-bdd7-5d4fdc9bd68c.png)

#5 : CLIENT_INFO.txt file in server side holding the client information such as the name, IP Address, port number and file descriptor respectively

![Screenshot from 2022-09-20 15-48-10](https://user-images.githubusercontent.com/98145598/191233394-43586353-2014-44aa-9c30-10a35fd42811.png)

#6 : SHOWCASE OF COMMUNICATION BETWEEN CONNECTED CLIENTS

![Screenshot from 2022-09-20 16-05-36](https://user-images.githubusercontent.com/98145598/191236959-418fef22-614d-4843-a226-a16f1658b651.png)

COMMUNICATION BETWEEN CLIENT 1 to CLIENT 2
![Screenshot from 2022-09-20 14-32-46](https://user-images.githubusercontent.com/98145598/191237159-12c18ff9-b084-4413-b950-9af8c568c56d.png)
     
COMMUNICATION BETWEEN CLIENT 2 to CLIENT 1
![Screenshot from 2022-09-20 14-32-21](https://user-images.githubusercontent.com/98145598/191237243-540468fa-a3ff-4de0-ac89-9a757c1b4d7e.png)

     















