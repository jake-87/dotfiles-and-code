#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef uint16_t byte;
typedef enum 
{
	HALT = 0,
	PUSH,
	POP,
	ADD
} instruction;
typedef struct
{
	instruction Ins;
	byte IP;
} CPU;
typedef struct
{
	byte data[1024];
	byte stack[1024];
}MEMORY;
void resetCPU(CPU * c)
{
	c->IP = 0x200;
}
void readIns(CPU * c)
{
	while (1);
}
