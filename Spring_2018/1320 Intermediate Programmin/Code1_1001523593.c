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
	
	printf("Enter 1 for YES and 0 for NO\n\n");
	
	
	printf("You're walking in the woods "
	       "there's no one around and your phone is dead.\n"
		   "Out of the corner of your eyes you spot him - "
		   "Shia LaBeouf. \n\n");

	
	printf("Your stomach growls as you run to the "
		   "closest McDonald's \nand you realize "
		   "you haven't had lunch. \n\n");
		   
	printf("It's beef Shia wants... but is it really what you want? "
	       "So you take a look at the menu and ask... "
		   "What do I really want?\n\n");
		   
	printf("Do you want a burger? ");
	scanf("%d", &Decision);
	
	if (Decision == YES)
	{
		printf("\n\nGreat! You decided on a burger, but, "
			   "a second problem arises." 
		       "\n\nDo you want fries with that!");
		scanf("%d", &Decision);
		
		if (Decision == YES)
		{
			printf("\n\nYou ordered a Big Mac with Fries. \nEnjoy!!\n\n");
		}
		
		else
		{
			printf("\n\nYou didn't want fries so you "
				   "just ordered a McDouble. \nEnjoy!!\n\n");
		}
	}
	else if (Decision == NO)
	{
		printf("\n\nBeing health considerate, "
		       "you back off from the beef. You look "
		       "at different items and see chicken on the menu. "
			   "\n\nDo you want a chicken sandwich?\n\n");
		scanf("%d", &Decision);
		
		if (Decision == NO)
		{
			printf("\n\nYou heard some nasty things about "
			       "what they do to the chicken here.\n"
			       "You look at their salads instead. Do you want a salad? ");
			scanf("%d", &Decision);
			
			if (Decision == YES)
			{
				printf("\n\nYou decide to munch on a "
				       "Southwest Grilled Chicken Salad. \nEnjoy!!\n\n ");
			}
			else
			{
				
				printf("\n\nYou reject your previous health concerns and " 
				       "chow down on some ice cream!!\n\n");
			}
		}
		else
		{
			
			printf("\n\nYou order a chicken sandwich and eat your food joyfully. Enjoy!!\n\n");
		}
	}
	else
	{
		printf("\n\n%d is not a valid input - "
		       "enter 0 for NO or 1 for YES.\n", Decision);
	}
	
	return 0;
}
