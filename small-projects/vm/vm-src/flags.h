#ifndef flagsh
#define flagsh
#include <stdlib.h>
#include <stdint.h>
enum {
	FSIGN = 0, // sign, 1 if neg, 0 if pos
	FZERO, // zero, 1 if zero, otherwise 0
	FPARI, // parity of last 8 bits, 1 if even, 0 if odd
	FCARY, // carry flag
	FLAGMAX
};
#endif
