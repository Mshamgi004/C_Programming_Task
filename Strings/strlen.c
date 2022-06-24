// C program to reverse the string and also for bubble sorting the string....
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{	
	// Declaring the character strings and variables 
	char str[100];
	char name[25][50], temp[25];
	int num1, num2, val1, val2;

	printf("\n\nPrint individual characters of string in reverse order :\n");
	printf("----------------------------------------------------------\n");
	printf("Input the string :");
	scanf("%s", str);

	// strlen() function used to calculate the length of the string
	num1 = strlen(str);

	printf("The characters of the string in reverse are : \n");

	// Loop to perform the reverse order of the string
	for (num2 = num1; num2 >= 0; num2--)
	{
		printf("%c", str[num2]);
	}

	printf("\n");
	printf("----------------------------------------------------------");

	printf("\n\nSorts the strings of an array using bubble sort :  \n");
	printf("---------------------------------------------------------\n");

	printf("Input number of strings :");
	scanf("%d", &val1);

	printf("Input string %d : \n", val1);

	// Creating the bubble sorting logic 
	for (num2 = 0; num2 < val1; num2++)
	{
		scanf("%s", name[num2]);
	}
	for(num2 = 1; num2 <= val1; num2++)
	{
		for(val2 = 0; val2 <= val1-num2; val2++)
		{
			if(strcmp(name[val2],name[val2 + 1])>0)
			{
				strncpy(temp,name[val2], sizeof(temp) - 1);
				strncpy(name[val2],name[val2 + 1], sizeof(name[val2]) - 1);
				strncpy(name[val2 + 1],temp, sizeof(name[val2] + 1) - 1);
			}
		}	
	}
	printf("The strings appear after sorting :\n");
	
	for (num2 = 0; num2 <= val1; num2++)
	{
		printf("%s\n", name[num2]);
	}		
	return 0;
}

