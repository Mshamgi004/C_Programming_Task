// C program to calculate your weekly pay //

#include<stdio.h>
#include<stdlib.h>
#include "weekheader.h"




int main()
{	
	int hours;
	double taxes = 0.00;
	double grosspay = 0.00;
	int netpay = 0.00;
	
	
	printf("Enter the number of hours worked:");
	scanf("%d", &hours);
	
	

	// display output
	printf("Your gross pay this week is: %.2f\n", grosspay);
	printf("Your taxes this week is: %.2f\n", taxes);
	printf("Your net pay this week is: %.2f\n", netpay);

	return 0;
}
		
			
		
	
