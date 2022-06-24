// Implementing the nested structures 
// 1. Embedded nested Stucture usage 
// 2. Seperate nested Structure

#include<stdio.h>
#include<stdlib.h>

// Parent stucture used for displaying the time
struct time
{
		// Embedded date for displaying the date
		struct date
		{
				// Embedded structure work to display the work  
				struct work
				{
					int task1;
					int task2; 
					int task3;
				}works;	
			
			int day;
			int month;
			int year;
		}dob;

	int hour;
	int minutes;
	int seconds;
};

struct EmployDetails
{
	char name[10];
	int id_no = 150136;
	int batch = 1;
}emp;
	 


int main()
{
	// Parent Stucture object declaration
	struct time value;
	
	// Assigning the values to parent structure time....
	value.hour = 4;
	value.minutes = 59;
	value.seconds = 05;
	
	// Assigning the values to embedded structure date
	value.dob.day = 21;
	value.dob.month = 6;
	value.dob.year = 2022;
	
	value.dob.works.task1 = 1;
	value.dob.works.task2 = 2;
	value.dob.works.task3 = 3;
	
	value.dob.works.emp.name = 'A';
	value.dob.works.emp.id_no = 150136;
	value.dob.works.emp.batch = 1;
	
	printf("--------------TIME TABLE---------------\n");	
	printf("Time = %d : %d : %d \n", value.hour, value.minutes, value.seconds);
	printf("----------------------------------------\n");
	printf("Day = %d / %d / %d \n", value.dob.day, value.dob.month, value.dob.year);
	printf("----------------------------------------\n");
	printf("Works = %d  %d  %d \n", value.dob.works.task1, value.dob.works.task2, value.dob.works.task3);
	
	printf("--------------Employee Details----------\n");
	printf("Details = %c  %d  %d \n", value.dob.works.emp.name , value.dob.works.emp.id_no, value.dob.works.emp.batch); 
	
	return 0;
}	
		
