/* Aamir Mazumdar 1001523593 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* This is a Comment */

/* prototype */
void ConvertDecimalToBinary(int, int[]);
void PrintBinaryArray(int, int[]);


void ConvertDecimalToBinary(int DecimalNum, int ArrayInt[])
{
	int i; 
	int NewInput = DecimalNum;
	for (i = 0; i < 8; i++)
	{
		ArrayInt[i] = DecimalNum % 2;
		DecimalNum = DecimalNum >> 1;
     /* printf("\n%d\n", DecimalNum); */
	}

	PrintBinaryArray(NewInput, ArrayInt);
	return;
}

void PrintBinaryArray(int NewInput, int IntArray[])
{
	int i;
	printf("\nDecimal %d converts to binary ", NewInput);
	for (i = 7; i >= 0; i--)
	{
		printf("%d", IntArray[i]);
	}
	
	printf("\n\n");
	return;
}

int main(void)
{
	int DecNum;
	int AskAgain = 1;
	int ArrayInt[8];
	
	printf("Decimal to binary convertor\n\n");
	
	while (AskAgain)
	{
		printf("Please enter a decimal number between 0 and 255 ");
		scanf("%d", &DecNum);
	
		if (DecNum >= 0 && DecNum <= 255)
			AskAgain = 0;
		else
		{
			AskAgain = 1;
			printf("\nYou entered a number not between 0 and 255\n\n");
		}
	}
	
	ConvertDecimalToBinary(DecNum, ArrayInt);

	return 0;
}
