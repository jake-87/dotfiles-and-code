#include "mov.h"
void mov(unsigned int ** ibuf, int ip, ui16 ** flags, reg_d * reg, mem_d * mem, int m) {
	switch (m) {
		case 0:
			if (ckreg(*ibuf[ip + 1])) {
				reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
				reg->type[*ibuf[ip + 1]] = 1;
				setflags(reg->reg[*ibuf[ip + 1]], flags);
			}
			else {
				hacf("Invalid register", 2, ip + 1);
			}
			break;
		case 1:
			if (ckreg(*ibuf[ip + 1])) {
				if (ckreg(*ibuf[ip + 2])) {
					reg->reg[*ibuf[ip + 1]] = reg->reg[*ibuf[ip + 2]];
					reg->type[*ibuf[ip + 1]] = reg->type[*ibuf[ip + 2]];
					setflags(reg->reg[*ibuf[ip + 1]], flags);
				}
				else {
					hacf("Invalid register", 2, ip + 2);
				}
			}
			else {
				hacf("Invalid register", 2, ip + 2);
			}
			break;
		case 2:
			if (ckreg(*ibuf[ip + 1])) {
				if (mem->type[*ibuf[ip + 2]]) {
					switch (mem->type[*ibuf[ip + 2]]) {
						case 1:
							reg->reg[*ibuf[ip + 1]] = mem->d[*ibuf[ip + 2]].i;
							reg->type[*ibuf[ip + 1]] = 1;
							setflags(reg->reg[*ibuf[ip + 1]], flags);
							break;
						case 2:
							reg->reg[*ibuf[ip + 1]] = mem->d[*ibuf[ip + 2]].u;
							reg->type[*ibuf[ip + 1]] = 2;
							setflags(reg->reg[*ibuf[ip + 1]], flags);
							break;
						case 3:
							reg->reg[*ibuf[ip + 1]] = mem->d[*ibuf[ip + 2]].f;
							reg->type[*ibuf[ip + 1]] = 3;
							setflags(reg->reg[*ibuf[ip + 1]], flags);
							break;
						case 4:
							reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
							reg->type[*ibuf[ip + 1]] = 4;
							setflags(reg->reg[*ibuf[ip + 1]], flags);
							break;
						case 5:
							reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
							reg->type[*ibuf[ip + 1]] = 5;
							setflags(mem->d[reg->reg[*ibuf[ip + 1]]].i, flags);
							break;
						case 6:
							reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
							reg->type[*ibuf[ip + 1]] = 6;
							setflags(mem->d[reg->reg[*ibuf[ip + 1]]].u, flags);
							break;
						case 7:
							reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
							reg->type[*ibuf[ip + 1]] = 7;
							setflags(mem->d[reg->reg[*ibuf[ip + 1]]].f, flags);
							break;
						case 8:
							reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
							reg->type[*ibuf[ip + 1]] = 8;
							setflags(mem->d[reg->reg[*ibuf[ip + 1]]].c, flags);
							break;
						default:
							hacf("Invalid operand", 4, ip + 2);
					}
				}
				else {
					hacf("Memory not initialised", 5, ip + 2);
				}
			}
			else {
				hacf("Invalid register", 2, ip + 1);
			}
			break;
		case 3:
			if (ckreg(*ibuf[ip + 1])) {
				if (mem->type[*ibuf[ip + 2]]) {
					reg->reg[*ibuf[ip + 1]] = *ibuf[ip + 2];
					reg->type[*ibuf[ip + 1]] = mem->type[*ibuf[ip + 2]];
					setflags(mem->dcpy[reg->reg[*ibuf[ip + 1]]], flags);
				}
			}
	}
}
