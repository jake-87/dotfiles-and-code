#include "interpolate.h"
void hacf(char * message, int i, int ii) {
	printf("ERROR : %s, code %d, location %d\n",message,i,ii);
	exit(1);
}
void set_flags(int16_t num, uint16_t ** flags) {
	unsigned int c; // c accumulates the total bits set in v
	int8_t numback = num & 0xFF;
	for (c = 0; numback; numback >>= 1)
	{
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
	else if (num > 0){
		*flags[FSIGN] = 0;
	}
	if (num - 1 > num || num + 1 < num) {
		*flags[FCARY] = 1;
	}
	else {
		*flags[FCARY] = 0;
	}
}
void dec(int16_t ** reg, int16_t i, uint16_t ** flags) {
	if (i > 0 && i < 9) {
		reg[i]--;
		set_flags(*reg[i], flags);
	}
	else {
		hacf("invalid register", 1, i);
	}
}
void inc(int16_t ** reg, int16_t i, uint16_t ** flags) {
	if (i > 0 && i < 9) {
		reg[i]++;
		set_flags(*reg[i], flags);
	}
	else {
		hacf("invalid register", 1, i);
	}
}
void add(int i, unsigned int * ibuf, uint16_t ** flags, int16_t ** reg, int m) {
	switch (m) {
		case 0:
			if (ibuf[i + 1] < 9 && ibuf[i + 1] > 0) {
				* reg[ibuf[i + 1]] += ibuf[i + 2];
				set_flags(*reg[ibuf[i + 1]], flags);
			}
			else {
				hacf("invalid register", 1, i);
			}
			break;
		case 1:
			if ((ibuf[i + 1] < 9 && ibuf[i + 1] > 0) && (ibuf[i + 2] < 9 && ibuf[i + 2] > 0)) {
				* reg[ibuf[i + 1]] += ibuf[i + 2];
			}
		default:
			hacf("invalid operand", 2, i);
	}	
}
void interpolate(unsigned int * ibuf, int size) {
	int16_t * reg = (int16_t *) calloc(1, sizeof(int16_t) * REGMAX);
	uint16_t * flags = (uint16_t *) calloc(1, sizeof(uint16_t) * REGMAX);
	int16_t ** mem = (int16_t **) calloc(1, sizeof(int16_t *) * 4096);
	mem[0] = (int16_t *) malloc(sizeof(int));
	for (int i = 0; i <= size; i++) {
		switch(ibuf[i]) {
			case 0x0000:
				break;
			case 0x0001:
				switch(ibuf[i + 1]) {
					case 0x0001:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0002:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0003:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0004:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0005:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0006:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0007:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0008:
						inc(&reg, ibuf[i + 1], &flags);
						break;
					default:
						hacf("illegal instruction", 0, i);
				}
				break;
			case 0x0002:
				switch(ibuf[i + 1]) {
					case 0x0001:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0002:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0003:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0004:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0005:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0006:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0007:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					case 0x0008:
						dec(&reg, ibuf[i + 1], &flags);
						break;
					default:
						hacf("illegal instruction", 0, i);
				}
				break;
			case 0x0003:
				switch(ibuf[i + 2]) {
					case 0x0000:
						add(i, ibuf, &flags, &reg, 0);
						break;
					case 0x0001:
						add(i, ibuf, &flags, &reg, 1);
						break;
					default:	
						hacf("illegal instruction", 0, i);

				}
			default:
				hacf("illegal instruction", 0, i);
		}	
	}
}
