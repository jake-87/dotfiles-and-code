#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "interpolate.h"
int main(int argc, char ** argv) {
	if (argc < 2) {
		printf("Useage: ./vm \"filename\"\n");
		exit(0);
	}
	FILE * fp = fopen(argv[1], "rb");
	if (!fp) {
		printf("Error opening file %s\n",argv[1]);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	rewind(fp);
	unsigned char  * buf = calloc(1, fsize + 1);
	unsigned int  * ibuf = calloc(1, (int) fsize / 2 + 1);
	unsigned int tmp, tmpshift;
	fread(buf, 1, fsize, fp);
	for (int i = 0; i < fsize; i += 2) {
		tmp = (unsigned int) buf[i] << 8;
		tmpshift = (unsigned int) buf[i + 1];
		ibuf[(int) i / 2] = tmp + tmpshift;
	}
	interpolate(ibuf);
	free(buf);
	free(ibuf);
	return 0;
}
