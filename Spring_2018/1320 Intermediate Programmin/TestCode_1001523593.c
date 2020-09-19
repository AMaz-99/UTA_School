/* Aamir Mazumdar 1001523593 */

#include <math.h>
#include <stdio.h>
#include <string.h>

/* This is a Comment */

#define YES 1
#define NO  0 

int main (void)
{
	int Decision;
	
	system("clear");
	
	printf("You are making weekend plans and find out that "
	       "your friends might visit.\n\nYou need to figure out "
		   "your options for the weekend.\n\n");
	printf("Enter 1 for YES and 0 for NO\n\n");
	
	printf("Your friends love to go to the movies, so if "
		   "they visit, you will all go to the movies.\n\n");
		   
	printf("But, if they don't visit, what will you do with "
	       "your weekend?\n\n");
		   
	printf("Did your friends visit? ");
	scanf("%d", &Decision);
	
	if (Decision == YES)
	{
		printf("\n\nWeekend plans - have fun at the movies " 
		       "with your friends!\n\n");
	}
	else if (Decision == NO)
	{
		printf("\n\nYour friends weren't able to visit so you need "
		       "to make alternate plans.\n\nIs the weather nice? ");
		scanf("%d", &Decision);
		
		if (Decision == NO)
		{
			printf("\n\nOh, so the weather is bad.  Do you have "
			       "enough money to go shopping? ");
			scanf("%d", &Decision);
			
			if (Decision == YES)
			{
				printf("\n\nWeekend plans - go shopping - "
				       "don't spend too much!!\n\n");
			}
			else
			{
				/* Not enough money to go shopping */
				printf("\n\nWeekend plans - stay home and " 
				       "play video games!!\n\n");
			}
		}
		else
		{
			/* The weather is nice. */
			printf("\n\nWeekend plans - ride bike in the park!\n\n");
		}
	}
	else
	{
		printf("\n\n%d is not a valid input - "
		       "enter 0 for NO or 1 for YES.\n", Decision);
	}
	
	return 0;
}
