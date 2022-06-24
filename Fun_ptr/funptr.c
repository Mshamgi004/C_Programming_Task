#include<stdio.h>
#include "funptr.h"



int sumOfElements(int *A, int size)

{
	int i;
	int sum = 0;
	//int size = sizeof(A)/sizeof(A[0]);
	printf("SOE - size of A = %d\n, size of A[0] = %d\n", sizeof(A),sizeof(A[0]));
	
	for(i = 0; i < size; i++)
	{
		sum+= A[i];
	}
	return sum;
}	

