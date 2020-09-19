/* Aamir Mazumdar 1001523593 */

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <limits.h>


/* This is a Comment */

void ConvertDecimalToBinary (int input);

void ConvertDecimalToBinary (int input)
{
	int a, b, c, d, e, f, g, h;
	
	a = input / 2;
	b = a / 2;
	c = b / 2;
	d = c / 2;
	e = d / 2;
	f = e / 2;
	g = f / 2;
	printf("\nDecimal %d converts to binary %d%d%d%d%d%d%d%d\n\n", input, g % 2, f % 2, e % 2, d % 2, c % 2, b % 2, a % 2, input % 2);
}


int main (void)
	{
		int user;
		int decision;
		while (1)
		{
			printf("Please enter a decimal number between 0 and 255: \n\n");
			scanf("%d", &user);
			if ((user >= 0) && (user <= 255))
				ConvertDecimalToBinary(user);
			else
			{
				printf("\nYou entered a number not between 0 and 255.\n\n");
			}				
			printf("If you want to exit the loop, press 0: ");
			scanf("%d", &decision);
			if (decision == 0)
				break;
		}
		return 0;
	}
	
	
	