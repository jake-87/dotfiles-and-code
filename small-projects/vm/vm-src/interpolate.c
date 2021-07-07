#include "interpolate.h"
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
void dec(int16_t ** reg, char r, uint16_t ** flags) {
	switch (r) {
		case 'A':
			reg[AX]--;
			set_flags(*reg[AX], flags);
			break;
		case 'B':
			reg[BX]--;
			set_flags(*reg[BX], flags);
			break;
		case 'C':
			reg[CX]--;
			set_flags(*reg[CX], flags);
			break;
		case 'D':
			reg[DX]--;
			set_flags(*reg[DX], flags);
			break;
		case '5':
			reg[R5]--;
			set_flags(*reg[R5], flags);
			break;
		case '6':
			reg[R6]--;
			set_flags(*reg[R6], flags);
			break;
		case '7':
			reg[R7]--;
			set_flags(*reg[R7], flags);
			break;
		case '8':
			reg[R8]--;
			set_flags(*reg[R8], flags);
			break;
	}
}
void inc(int16_t ** reg, char r, uint16_t ** flags) {
	switch (r) {
		case 'A':
			reg[AX]++;
			set_flags(*reg[AX], flags);
			break;
		case 'B':
			reg[BX]++;
			set_flags(*reg[BX], flags);
			break;
		case 'C':
			reg[CX]++;
			set_flags(*reg[CX], flags);
			break;
		case 'D':
			reg[DX]++;
			set_flags(*reg[DX], flags);
			break;
		case '5':
			reg[R5]++;
			set_flags(*reg[R5], flags);
			break;
		case '6':
			reg[R6]++;
			set_flags(*reg[R6], flags);
			break;
		case '7':
			reg[R7]++;
			set_flags(*reg[R7], flags);
			break;
		case '8':
			reg[R8]++;
			set_flags(*reg[R8], flags);
			break;
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
						inc(&reg, 'A', &flags);
						break;
					case 0x0002:
						inc(&reg, 'B', &flags);
						break;
					case 0x0003:
						inc(&reg, 'C', &flags);
						break;
					case 0x0004:
						inc(&reg, 'D', &flags);
						break;
					case 0x0005:
						inc(&reg, '5', &flags);
						break;
					case 0x0006:
						inc(&reg, '6', &flags);
						break;
					case 0x0007:
						inc(&reg, '7', &flags);
						break;
					case 0x0008:
						inc(&reg, '8', &flags);
						break;
				}
				break;
			case 0x0002:
				switch(ibuf[i + 1]) {
					case 0x0001:
						dec(&reg, 'A', &flags);
						break;
					case 0x0002:
						dec(&reg, 'B', &flags);
						break;
					case 0x0003:
						dec(&reg, 'C', &flags);
						break;
					case 0x0004:
						dec(&reg, 'D', &flags);
						break;
					case 0x0005:
						dec(&reg, '5', &flags);
						break;
					case 0x0006:
						dec(&reg, '6', &flags);
						break;
					case 0x0007:
						dec(&reg, '7', &flags);
						break;
					case 0x0008:
						dec(&reg, '8', &flags);
						break;
				}
				break;
		}	
	}
}
