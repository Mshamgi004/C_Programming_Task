// Use of structure in basic level

#include<stdio.h>

struct date 
{
/*
	int day;
	int month;
	int year;
*/
	char day[3];	
};

int main()
{
		
	struct date myDates[10] = {{1,2,2000}, {2,3,2000}, {3,3,2000}};
	
/*
	today.day = 21;
	today.month = 6;
	today.year = 2022;
*/
	myDates.day[0] = '1,2,2000';
	myDates.day[1] = '2,3,2000';
	myDates.day[2] = '3,3,2000';
	printf("The date is = %d / %d / %d \n",myDates.day[0], myDates.day[1], myDates.day[2] );

	return 0;
} 

	
