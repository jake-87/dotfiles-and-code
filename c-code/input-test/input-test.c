#include <stdio.h>
int main( void ){
	char code[20];
	fgets(code,sizeof(code),stdin);
	printf("%s\n",code);
	return 0;
}
