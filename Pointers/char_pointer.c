#include<stdio.h>

int main()
{
    // Declaring the variable and pointer
    int i = 1025;
    int *p;
    p = &i; // Storing the address of i in pointer p

    // Printing the values of all the cases in int pointers
    printf("The address of p = %d\n",p);
    printf("THe value of p = %d\n", *p);
    printf("The size of integer = %d\n", sizeof(int));
    printf("The address of  = %d\n",p+1);
    printf("The value of p = %d\n", *(p+1));

    // Declaring a char pointer
    char *p1;
    // Typecasting of int pointer to char pointer
    p1 = (char*)p;

    // Printing the values of all the cases in  char pointer 
    printf("The address of p1 = %d\n",p1);
    printf("THe value of p1 = %d\n", *p1);
    printf("The size of integer = %d\n", sizeof(char));
    printf("The address of p1 = %d\n",p1+1);
    printf("The value of p1 = %d\n", *(p1+1));
    return 0;
}       
