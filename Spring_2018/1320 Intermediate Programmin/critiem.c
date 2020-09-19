#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* This is a Comment */


int main(void)
	{
	  char Array1[100] = "Bob Smith,Jr|100 Byte Lane|Binary|TX|01010";

      char Array2[100] = "|,";

      char *Token;

      Token = strtok(Array1, Array2);

 

      while (Token != NULL)

      {

           printf("%s\n", Token);

           Token = strtok(NULL, Array2);

      }
	  printf("\n");
	  char Array3[100] = "hello";

      char Array4[100] = "world";

 

      printf("%d", strlen(Array3) + strlen(Array4));
	  
	  char Array[100] = "The quick brown fox";

      *(Array + strlen("quick brown")-2) = '\0';

      printf("%s\n", Array);
	  char Array5[100] = "parameter";

      char Array6[100] = "meter";

     
		printf("\n%s", strstr(Array5, Array6));
      *(strstr(Array5, Array6)-1) = 'i';

      *(strstr(Array5, Array6)-3) = 'e';

     

      printf("\n%s", Array5);
	  char *StringPtr = "The quick brown fox jumps over the lazy dog.\n";

      printf("%c\n", *(StringPtr + (strlen(StringPtr)-8)));
	}
	
	