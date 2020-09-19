#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "MyLib.h"
#define MAX 500

/* This is a Comment */

void ConvertDecimalToBinary(int DecimalNum, int ArrayInt[], int OutputArrayInt[])
{
	int i; 
	int NewInput = DecimalNum;
	for (i = 0; i < 8; i++)
	{
		ArrayInt[i] = DecimalNum % 2;
		DecimalNum = DecimalNum >> 1;
	}
	int j;
	for (j = 0; j < 8; j++)
	{
		OutputArrayInt[j] = ArrayInt[j];
	}

	printf("\n");
	return;
}


void SentenceCleanup(char StringArray[])
{	
	char mess[MAX];
	char *sentence, *pointer;
	printf("Enter at least two sentences seperated by one of these 3 delimeters - ?!. - (max of 500 characters total): ");
	fgets (mess, MAX, stdio);
	mess [(strlen(mess) -1)] = '\0';
	*pointer = mess;

	sentence = strtok(pointer, "?!.")
	while ((sentence != NULL) {
		printf("sentence: %s\n", sentence );
		sentence = strtok(NULL, "?!.");

	}

	printf("\n\n");
	return;
	printf("\n");
}

void SKUConverter(char CleanArray[])
{

	printf("\n\n");
	return;
	printf("\n");
}