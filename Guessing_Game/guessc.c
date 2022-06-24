#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "guess.h"



int randnum = 0;
int guess = 0;
int maxnum = 5;
time_t t;

srand((unsigned) time(&t));
	
randnum = rand() % 21;
