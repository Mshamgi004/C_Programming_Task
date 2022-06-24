// Task 1
// Create a C program for function having pointer as an argument and pass array as an argument of pointer 

#include<stdio.h>

int sumofElements(int *A, int size);

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

int main()
{
	int A[] = {1,2,3,4,5};
	int size = sizeof(A);///sizeof(A[0]);
	int total = sumOfElements(A,size);
	printf("The sum of elements is %d\n", total);
	//printf("The size of elements is %d\n", sizeof(A));
	printf("SOE -Size of A = %d\n, size of A[0] = %d\n", sizeof(A),sizeof(A[0]));
	return 0;
}	

	

/*
void Increament(int *a)
{	
	
	*a = (*a) + 1;
	printf("Address of variable = %d\n", &a);
}

int main()
{
	int a;
	a = 10;
	Increament(&a);
	printf("The value of a = %d\n",a);
	printf("Address of variable = %d\n", &a);
	
	return 0;
}		
*/


