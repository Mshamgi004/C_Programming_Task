// Create a Tic-Tac-Toe game .....

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice;
int player;

int checkWin();
void displayBoard();
void markBoard(char marks);

// Function declaration to check if the player wins ...
int checkWin()
{
	int returnValue = 0;
	
	if (square[1] == square[2] && square[2] == square[3])
	{
		returnValue = 1;
	}
	else if (square[4] == square[5] && square[5] == square[6])
	{
		returnValue = 1;
	}
	else if (square[7] == square[8] && square[8] == square[9])
	{
		returnValue = 1;
	}
	else if (square[1] == square[4] && square[4] == square[7])
	{
		returnValue = 1;
	}
	else if (square[2] == square[5] && square[5] == square[8])
	{
		returnValue = 1;
	}
	else if (square[3] == square[6] && square[6] == square[9])
	{
		returnValue = 1;
	}
	else if (square[1] == square[5] && square[5] == square[9])
	{
		returnValue = 1;
	}
	else if (square[3] == square[5] && square[5] == square[7])
	{
		returnValue = 1;
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
	{
		returnValue = 1;
	}
	else
	{
		returnValue = -1;
	}
	return returnValue;
}

// Function declaration to print the board 
void displayBoard()
{
	system("cls");
	
	printf("\n\n\tTic Tac Toe\n\n");
	
	printf("Player 1 (X) - Player 2 (0)\n\n\n");
	
	printf("	|	|	\n");
	printf("   %c	|   %c	|   %c	\n", square[1], square[2], square[3]);
	
	printf("_______	|______	|______	\n");
	printf("	|	|	\n");
	
	printf("   %c	|   %c	|   %c	\n", square[4], square[5], square[6]);
	
	printf("_______	|______	|______	\n");
	printf("	|	|	\n");
	
	printf("   %c	|   %c	|   %c	\n", square[7], square[8], square[9]);
	printf("	|	|	\n");
}

// Function declaration to set the board with correct character using X and 0 values.....
void markBoard(char mark)
{
	if (choice == 1 && square[1] == '1')
	{
		square[1] = mark;
	}
	else if (choice == 2 && square[2] == '2')
	{
		square[2] = mark;
	}
	else if (choice == 3 && square[3] == '3')
	{
		square[3] = mark;
	}
	else if (choice == 4 && square[4] == '4')
	{
		square[4] = mark;
	}
	else if (choice == 5 && square[5] == '5')
	{
		square[5] = mark;
	}
	else if (choice == 6 && square[6] == '6')
	{
		square[6] = mark;
	}
	else if (choice == 7 && square[7] == '7')
	{
		square[7] = mark;
	}			
	else if (choice == 8 && square[8] == '8')
	{
		square[8] = mark;
	}
	else if (choice == 9 && square[9] == '9')
	{
		square[9] = mark;
	}
	else
	{
		printf("Invalid move");
		player--;
		getchar();
	}
}	
			
		
int main()
{
	int gameStatus;
	char mark;
	player = 1;
	
	do
	{
		displayBoard();
		
		// Change turns logic
		player = (player % 2) ? 1 : 2;
		
		// Get the input
		printf("Player %d please enter a number: ", player);
		scanf("%d",&choice);
		
		// Set the correct character based on player turn
		mark = (player == 1) ? 'X' : '0';
		
		// Set the board based on user choice or invalid choice
		markBoard(mark);
		
		gameStatus = checkWin();
		
		player++;
	}
	while(gameStatus == -1);
	{
		if(gameStatus == 1)
		{
			printf("==>\aPlayer %d won ", --player);
		}	
		else
		{
			printf("==>\aGame Drawn");
		}		
	}
	return 0;
}	
		
			




