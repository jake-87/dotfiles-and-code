#include <stdio.h>

int main()
{
	char stringf="s";
	int counter = 0;
	int i = 0;
	char chari;
	while (i<256)
	{
		counter = i;
		chari = (char) i;
		printf("counter is %d, ascii is %c\n",counter,i);
		if (chari == stringf)
		{
			printf("stringf = %c",chari);
		}
		i++;
	}
	return 0;
}
