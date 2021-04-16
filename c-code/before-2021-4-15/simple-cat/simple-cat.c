#include <stdio.h>
main( int r, char ** a)
{
	int i=1,c;
	FILE *f;
	for (; i < r; i++)
	{
		if ((f = fopen(a[i],"r")) == 0)
		{
			printf("Error opening file %s\n",a[i]);
			exit(1);
		} 
		while ((c = getc(f)) != -1)
		putchar(c);
	}
}
