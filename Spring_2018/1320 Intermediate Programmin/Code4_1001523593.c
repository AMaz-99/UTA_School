/* Aamir Mazumdar 1001523593 */

#include <stdio.h>

void bubble_sort(int[], int);
void swap(int, int, int, int[]);

void bubble_sort(int data[], int num_elts)
{
	int i,j;
	
	for (i = 0; i < num_elts; i++) 
		for (j = num_elts-1; j > 0; j--) 
			if (data[j] < data[j-1]) 
				swap(data[j], data[j-1], j, data); 
}

void swap(int a, int b, int place, int data[])
{
	int temp;
	
	temp = a;
	data[place] = b;
	data[place - 1] = temp;
}

int main(void)
{
	int index, data[10] = {10,3,4,8,2,5,9,7,1,6};
	
	bubble_sort(data, 10);
	
	for (index = 0; index < 10; index++)
		printf("%d ", data[index]);
		
	printf("\n");
	
	return 0;
}
