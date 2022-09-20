||-----------------------------------------------------------------------MY_CHATBOT APPLICATION-------------------------------------------------------------------||

||****************************************************************************************************************************************************************||
 TASK: TO CREATE A CHATBOT APPLICATION WHICH WILL COMMUNICATE BETWEEN TWO CLIENTS. BY DOING SO THE SERVER WILL STORE THE CLIENT DETAILS SUCH AS THE NAME,IP ADDRESS.       PORT NUMBER AND fd's IN A CLIENT_INFO.txt file.
||****************************************************************************************************************************************************************||


 OBJECTIVE 1: Maintain the connected client details in server's data structure and store them in a text file.
 OBJECTIVE 2: Respond to commands like LIST and CONNECT 
 OBJECTIVE 3: Communicate between clients through server by using select() system call.
 OBJECTIVE 4: Create a prompt on client side so as to make it user friendly application for clients.
 OBJECTIVE 5: Client should communicate with the other conneted clients whose data are stored in Server side of CLIENT_INFO.txt. And Client should have the                           flexibility to communicate with any connected client.
 OBJECTIVE 6: The CLIENT_INFO.txt has the details of the connected client's such as the name, ip address, port number and their fd's. And there should be updation 
              in the .text file after every new entry of client.
 


----------------------------------------------------------------------------------------------------------------------------------------------------------------------
LIST OF OUTPUTS ON TERMINAL OF UBUNTU 18.04 LTS

#1 : SERVER SIDE CONNECTION

Command : ./server

![Screenshot from 2022-09-20 14-42-45](https://user-images.githubusercontent.com/98145598/191218666-da7662c4-77aa-45c7-9653-6c12ed78e8d6.png)

#2 : CLIENT SIDE CONNECTION & PROMPT SHOWCASE FOR TAKING REQUIRED ACTION

COMMAND : ./client (Name of client).
        Note: Using command line argument for naming of the client

![Screenshot from 2022-09-20 14-48-07](https://user-images.githubusercontent.com/98145598/191219978-2ab313c6-65aa-4765-8469-a1ccd4cf6053.png)
![Screenshot from 2022-09-20 13-16-10](https://user-images.githubusercontent.com/98145598/191220072-8a5f550d-7bb0-4e4c-b014-ef7cb7233335.png)

#3 : SERVER SIDE SHOWCASE OF CONNECTED CLEINT INFORMATION

![Screenshot from 2022-09-20 14-53-44](https://user-images.githubusercontent.com/98145598/191221278-d823ac5e-aec9-4c7a-a91d-84bda89ee83c.png)

#4 : LISTING THE CONNECTED CLIENT DETAILS ON CLIENT SIDE SO AS TO COMMUNICATE

![Screenshot from 2022-09-20 13-21-53](https://user-images.githubusercontent.com/98145598/191231852-58039b04-df42-466f-bdd7-5d4fdc9bd68c.png)











