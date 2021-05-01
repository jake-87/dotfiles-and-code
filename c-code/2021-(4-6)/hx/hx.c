#include <stdio.h>
#include "hx.h"
#include <stdlib.h>
#define SECTOR 8
#define SECTIONS 2
void printchar(unsigned char src)
{
	switch(src)
	{
		case '\n':
			printf(".");
			break;
		case '\r':
			printf(".");
			break;
		case '\t':
			printf(".");
			break;
		default:
			printf("%c",(unsigned char) src);
	}
}
int main (int argc, char ** argv)
{
	if (argc  < 2)
	{
		puts("Not enough args.\n");
		puts("Useage: hx FILENAME");
		exit(1);
	}
	FILE * fp = fopen(argv[1],"r");
	if (!fp)
	{
		fprintf(stderr,"File %s not found.\n",argv[1]);
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp) + 1;
	rewind(fp);
	unsigned char * buf = malloc(sizeof(unsigned char) * sz + 1);
	fread(buf,2,sz,fp);
	int r = 0;
	int i = 1;
	for (i = 1; i < sz; i++)
	{
		printf("%04x ",buf[i - 1]);
		if (i % SECTOR == 0)
		{
			for ( int e = 0; e < SECTOR; e++ )
			{
				printchar(buf[r]);
				r++;
			}
			printf("\n");
		}
		else if (i % (SECTIONS) == 0)
		{
			printf("   ");
		}
	}
	printf("\n");
	return 0;
}
