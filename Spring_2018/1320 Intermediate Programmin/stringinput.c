#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* This is a Comment */
#define BUF_SIZE 512

int inputstring (char *buffer, int n)
{

	int i = 0;
	while ( i <= n-1 && (buffer[i] = getchar() ) != '\n' )
	{
		i++;
	}
	if ( i == n)
	{
		buffer[i-1] = '\0';
		return -1;
	}
	else 
	{
		buffer[i] = '\0';
		return 0;
	}
}
int main(void)
	{
		char inputarray[BUF_SIZE];
		int retval;
		printf("Enter a line of text.\n> " );
		retval = inputstring(inputarray, BUF_SIZE);
		
		if (retval == 0)
			printf("Input completed: %s\n", inputarray);
		else
			printf("Input truncated: %s\n", inputarray);
		
		return 0;
	}
	
	
	