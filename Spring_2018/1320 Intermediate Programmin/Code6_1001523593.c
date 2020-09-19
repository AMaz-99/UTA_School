/* Aamir Mazumdar 1001523593 */

#include <math.h>

#include <stdio.h>

#include <string.h>

#include <limits.h>

#include "MyLib.h"

#define MAX 500

/* This is a Comment */

/* prototype */
void PrintBinaryArray(int, int[]);

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
	int menuchoice;
	printf("Welcome to the menu!\n "
	"Select 1 for a Decimal to Binary Conversion\n "
	"Select 2 for Sentence Cleanup\n "
	"Select 3 for the SKUConverter.\n");
	printf("Please make your choice: ");
	scanf("%d", &menuchoice);

	switch (menuchoice) 
	{
		case 1:
			printf("\nYou have selected to do the decimal to binary conversion!\n\n");
			int DecNum;
			int AskAgain = 1;
			int ArrayInt[8];
			int OutputArrayInt[8];
		
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
	
			ConvertDecimalToBinary(DecNum, ArrayInt, OutputArrayInt);
			PrintBinaryArray(DecNum, OutputArrayInt);
			

			break;
		case 2:
			pritnf("\nYou have selected to do the sentence cleanup!\n\n");
			char SentenceArray[500];
			SentenceCleanup(SentenceArray);
			break;
		case 3:

			break; 
		default:
			printf("An incorect choice was entered.\n\n");
	}

	printf("\n");
	return 0;
}



	