#include "interpolate.h"
#include "instructions/all.h"
void hacf(char * msg, int code, int ii) {
	printf("KSMVM ERROR: Code %d : %s at position %d\n",code,msg,ii);
	exit(code); // Halt And Catch Fire, with some debug info
}
int ckreg(i16 i) { // check if register is in range
	if (i > 0 && i < 9) {
		return 1;
	}
	else {
		return 0;
	}
}
void setflags(i16 num, ui16 ** flags) { // set flag values to correct values
	unsigned int c;
	int8_t numback = num & 0xFF;
	for (c = 0; numback; numback >>= 1) {
		c += numback & 1;
	}
	if (c % 2 == 0) {
		*flags[FPARI] = 1;
	}
	else {
		*flags[FPARI] = 0;
	}
	if (num == 0) {
		*flags[FZERO] = 1;
	}
	else {
		*flags[FZERO] = 0;	
	}
	if (num < 0) {
		*flags[FSIGN] = 1;
	}
	else if (num > 0) {
		*flags[FSIGN] = 0;
	}
	if (num - 1 > num || num + 1 < num) {
		*flags[FCARY] = 1;
	}
	else {
		*flags[FCARY] = 0;
	}
}
void interpolate(unsigned int * ibuf, int size) {
	ui16 * flags = calloc(1, sizeof(ui16) * FLAGMAX);
	mem_d mem;
	mem.type = calloc(1, sizeof(i16) * 4096);
	mem.d = calloc(1, sizeof(union memdata) * 4096);
	mem.dcpy = calloc(1, sizeof(union memdata) * 4096);
	reg_d reg;
	reg.reg = calloc(1, sizeof(i16) * 9);
	reg.type = calloc(1, sizeof(i16) * 9);
	for (int ip = 0; ip <= size; ip++) {
		switch(ibuf[ip]) {
			case 0x0001:
				inc(ibuf, ip, &flags, &reg, &mem, ibuf[ip + 2], 1, &regtype);
				ip += 3; // 3 because it will then naturally increment the last 1
				break;
			case 0x0002:
				inc(ibuf, ip, &flags, &reg, &mem, ibuf[ip + 2], -1, &regtype);
				ip += 3;
				break;
			case 0x0003:
				add(ibuf, ip, &flags, &reg, &mem, ibuf[ip + 3], 1, &regtype);
				ip += 3;
				break;
			case 0x0004:
				add(ibuf, ip, &flags, &reg, &mem, ibuf[ip + 3], -1, &regtype);
				ip += 3;
				break;
			case 0x0005:
				mov(ibuf, ip, &flags, &reg, &mem, ibuf[ip + 3], &regtype);
			default:
				hacf("Invalid operation", 1, ip);
		}
	}
	free(mem.type);
	free(mem.d);
	free(reg.reg);
	free(reg.type);
	free(flags);
}
