#include <stdio.h>
//#define MAX 20
int main()
{
	int MAX;
	printf("What is MAX?");
	scanf("%d",&MAX);
	int data[MAX];
	int i;
	int counter = 0;
	int sorted = 0;
	int tmp;
	int arrayAccess = 0;
	printf("Enter %d numbers, one at a time:\n",MAX);
	for (i = 0; i < MAX; i++)
	{
		scanf("%d",&data[i]);
	}
	printf("Your list is : ");
	for (i = 0; i < MAX; i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
	do
	{
		counter++;
		sorted = 0;
		for (i = 0; i < (MAX - 1); i++)
		{
			if (data[i] > data[i + 1])
			{
				arrayAccess = arrayAccess + 6;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
		for (i = MAX - 1; i > 1; i--)
		{
			if (data[i] < data[i - 1])
			{
				arrayAccess = arrayAccess + 6;
				tmp = data[i];
				data[i] = data[i - 1];
				data[i - 1] = tmp;
			}
		}
		for (i = 0; i < MAX - 1; i++)
		{
			if (i == MAX) {break;}
			if ( data[i] > data[i + 1])
			{
				sorted = 1;
				arrayAccess = arrayAccess + 2;
			}
			else 
			{
			} 
		}
	} 
	while ( sorted != 0 );
	printf("Sorted list is : ");
	for (i = 0; i < MAX; i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
	printf("This took %d iteration(s) and %d array accesses.\n",counter,arrayAccess);
}