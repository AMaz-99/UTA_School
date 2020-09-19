#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* This is a Comment */


#define MAX_INPUT 100

int main(void)
	{
	/*char *StringPtr = "Today is string day\n\0";
	printf(StringPtr);
	printf("The first character of the string is %c\n", *StringPtr);
	printf("The second character of the string is %c\n", *(StringPtr+1));
	printf("The third character of the string is %c\n", *(StringPtr+2));*/
	
	/* string toolbox Demo */



	char InputArray[MAX_INPUT],InputArray1[MAX_INPUT], InputArray2[MAX_INPUT];
	char *InputPtr1, *InputPtr2;
	char *String, *String1, *String2;
	char *Char_Set;
	char *Field;
	char *FirstOccur;
	char *Numbers = "0123456789";
	char *Alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *Delimiters = ",|";
	char Ch;
	char Buffer[MAX_INPUT];
	int MenuChoice;
	int n, i, Count;
		
	system("clear");
	
	printf("\nString Tool Box\n\n");
	printf(" 0. Exit\n");
	printf(" 1. strlen()  example\n");
	printf(" 2. strcpy()  example\n");
	printf(" 3. strcat()  example\n");
	printf(" 4. strcmp()  example\n");
	printf(" 5. strncmp() example\n");
	printf(" 6. strchr()  example\n");	
	printf(" 7. strstr()  example\n");
	printf(" 8. strpbrk() example\n");
	printf(" 9. strspn()  example\n");
	printf("10. strcspn() example\n");
	printf("11. strtok()  example\n");
	
	printf("\nEnter choice ");
	
	scanf("%d", &MenuChoice);
	getchar();  /* throw away <ENTER> key */
	
	if (MenuChoice)
	{	
		if (MenuChoice == 1)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray, MAX_INPUT, stdin);

			printf("\nYou entered\n\n%s\n", String);		
			printf("\nThe length of your string is %d\n",
			       strlen(String));
		}
		else if (MenuChoice == 2)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray, MAX_INPUT, stdin);
			
			strcpy(Buffer, String);
			
			printf("\nBuffer is %s\n", Buffer);
	
		}
		else if (MenuChoice == 3)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String1 = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String2 = fgets(InputArray2, MAX_INPUT, stdin);
			
			printf("\nString1 = %s\n", String1);
			printf("String2 = %s\n", String2);
			
			String1[strlen(String1)-1] = ' ';
			
			strcat(String1, String2);
			
			printf("String1 = %s\n", String1);
			printf("String2 = %s\n", String2);			
		}
		else if (MenuChoice == 4)
		{  
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String1 = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String2 = fgets(InputArray2, MAX_INPUT, stdin);			
			printf("\n\n");

			if (strcmp(String1, String2) == 0)
				printf("Strings are identical\n");
			else if (strcmp(String1, String2) > 0)
				printf("%sis alphabetically after\n%s\n", String1, String2);
			else if (strcmp(String1, String2) < 0)
				printf("%sis alphabetically before\n%s\n", String1, String2);
			else
				printf("strcmp failed\n");
		
		}
		else if (MenuChoice == 5)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String1 = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String2 = fgets(InputArray2, MAX_INPUT, stdin);			
			printf("\n\n");
			printf("Enter how many letters to compare ");
			scanf("%d", &n);
			
			if (strncmp(String1, String2, n) == 0)
				printf("Strings are identical\n");
			else if (strncmp(String1, String2, n) > 0)
				printf("%sis alphabetically after\n%s\n", String1, String2);
			else if (strncmp(String1, String2, n) < 0)
				printf("%sis alphabetically before\n%s\n", String1, String2);
			else
				printf("strncmp failed\n");
		
		}
		else if (MenuChoice == 6)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter a character\n\n");
			scanf(" %c", &Ch);			
			printf("\n\n");
		
			FirstOccur = strchr(String, Ch);
			while (FirstOccur != NULL)
			{
				*FirstOccur = '-';
				FirstOccur = strchr(String, Ch);
			}
			printf("New version of String\n\n%s", String);
		}		
		else if (MenuChoice == 7)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String1 = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String2 = fgets(InputArray2, MAX_INPUT, stdin);
			String2[strlen(String2)-1] = '\0';
			
			printf("\n\n");
		
			if (strstr(String1, String2) != NULL)
				printf("%s\ncontains\n\n%s\n\n", String1, String2);
			else
				printf("%s\ndoes not contain\n\n%s\n\n", String1, String2);
		}
		else if (MenuChoice == 8)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray1, MAX_INPUT, stdin);
			printf("\nEnter characters to replace with _\n\n");
			Char_Set = fgets(InputArray2, MAX_INPUT, stdin);
			printf("\n\n");
		
			FirstOccur = strpbrk(String, Char_Set);
			while (FirstOccur != NULL)
			{
				*FirstOccur = '_';
				FirstOccur = strpbrk(String, Char_Set);
			}
			printf("Replacing all instances of\n\n\t%s\nwith _\n\n\n%s\n", 
			       Char_Set, String);			
			
		}
		else if (MenuChoice == 9)
		{
			printf("\nEnter a house address (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray1, MAX_INPUT, stdin);

			printf("\n\nThe house number is ");
			for (i = 0; i < strspn(String, Numbers); i++)
			{ 
				printf("%c", *(String+i));
			}
			printf("\n\n");
		}
		else if (MenuChoice == 10)
		{
			printf("\nEnter a house address (max of %d)\n\n", MAX_INPUT);
			String = fgets(InputArray1, MAX_INPUT, stdin);
			
			printf("\n\nThe street name is");
			for (i = strcspn(String, Alphabet); i < strlen(String); i++)
			{ 
				printf("%c", *(String+i));
			}
			printf("\n\n");
		}
		else if (MenuChoice == 11)
		{
			printf("\nEnter a line of text (max of %d)\n\n", MAX_INPUT);
			fgets(Buffer, MAX_INPUT, stdin);
			Buffer[MAX_INPUT - 1] = '\0';

			printf("\n");			

			Field = strtok(Buffer, Delimiters);

			while (Field != NULL)
			{
				printf("Field = %s\n", Field);
				Field = strtok(NULL, Delimiters);
			}
		}
		else
		{
			printf("\n\nThat option is not on the menu\n\n");
		}
	}
	
	return 0;

	}
	
