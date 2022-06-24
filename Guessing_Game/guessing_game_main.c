// Create a guessing game //

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "guess.h"


int main()
{
	int randnum = 0;
	int guess = 0;
	int maxnum = 5;
	time_t t;
	
	//srand((unsigned) time(&t));
	
	//randnum = rand() % 21;
	
	printf("\n This is a guessing game.");
	printf("You must choose a number between 0 to 20",randnum);
	
	for(maxnum = 5; guess > 0; --guess)
	{
		printf("\nYou have %d tries left.", guess, guess == 1 ? "y" : "ies");
		printf("\nEnter a guess: ");
		scanf("%d", &guess);
		
		if(guess == randnum)
		{
			printf("\nCongragulation. You guessd it!\n");
			break;
		}
		else if(guess < 0 || guess > 20)
		{
			printf("I said the number is betwwn 0 and 20.");
		}
		else if(randnum > guess)
		{
			printf("Sorry, %d is wrong. My number is greater than that.\n",guess);
		}
		else if(randnum < guess)
		{
			printf("Sorry, %d is wrong . My number is less than that.\n",guess);
		}
		printf("You have five tries and you have failed. The number was %d\n", randnum);
	}
	return 0;
}						 

