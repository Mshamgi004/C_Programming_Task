// Use of array in terms of pointers

#include<stdio.h>

int main()
{
/*
	// Normal initialization of pointers and printing the values of array
	int arr[5];
	int val = 5;
	int *pval;
	pval = &val;
	
	printf("The address of pval = %d\n", pval);
	printf("The value of pval = %d\n", *pval);
	
	pval = pval + 1;
	
	printf("The address of pval = %d\n", pval);
	printf("The value of pval = %d\n", *pval);
	
	return 0;
*/	
	// Pointers using array concept implementation 
	int arr[5] = {1,2,3,4,5};
	int *pval;
	pval = &arr[0];
	
	
	printf("The address of pval = %d\n", pval);
	printf("The value of pval = %d\n", *pval);
	
	printf("The address of pavl = %d\n", pval+1);
	printf("The value of pval = %d\n", *(pval+1));
	
	return 0;
	

}	
