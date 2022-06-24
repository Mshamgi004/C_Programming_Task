#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "tttlib.h"


int main()
{
	int gameStatus;
	char mark;
	int choice;
	int player;
	
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
	
