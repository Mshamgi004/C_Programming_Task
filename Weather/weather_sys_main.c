// To create a weather system using 2D Array concept //

#include<stdio.h>
#include<stdlib.h>
#include "weather.h"


int main()
{
	 // initialize rainfall data for 2011 - 2015
	 
	 float rain[YEARS][MONTHS] = 
	 {
	 	{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
         };
         
         int year, month;
         float subtotal, total;
         
         printf("YEAR\t\tRAINFALL(inches)\n");
         
         // Iterating through year to print the subtotal 
         for(year = 0, total = 0; year < YEARS; year++)
         {
         	for(month = 0,subtotal = 0; month < MONTHS; month++)
         	{
         		subtotal += rain[year][month];
         	}
         	printf("%5d \t\t%15.lf\n", 2010 + year, subtotal);
         	total += subtotal;
         }
         printf("\nThe yearly average is %.1f inches.\n\n",total/YEARS);
         
         printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

    // Iterating through month to find the average rainfall
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtotal = 0; year < YEARS; year++)
            subtotal += rain[year][month];

        printf("%4.1f ", subtotal/YEARS);
    }

    printf("\n");

    return 0;
}		
	        
	 	
