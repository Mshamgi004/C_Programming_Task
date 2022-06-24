// C program to use function in Structures

#include<stdio.h>

struct family
{	
	char name[50];
	int age;
	int member;
};	

int siblings(struct family member1, struct family member2)
{
	if(strcmp(member1.name, member2.name))
	{
		printf("They are same");
	}
	else
	{
		printf("They are not same");
	}
}

int main()
{
	struct family member1 = {"Magic"};
	struct family member2 = {"Magic"};
	
	
	
	printf("The result = \n", siblings(member1,member2) );
	
	return 0;
}	
				
