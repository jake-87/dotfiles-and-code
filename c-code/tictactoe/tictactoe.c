#include <stdio.h>
void player1();
void player2();
void printboard();
void init();
int board[3][3];
int main()
{
	init();
	printf("%d\n",board[1][0]);
	printboard();
}
void init()
{
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = counter;
			counter++;
			printf("board is %d, j is %d, i is %d\n",board[i][j],j,i);
		}
	}
}
void printboard()
{
	printf("-----------------------\n");
	for (int j = 0; j < 3; j++)
	{			printf("|  %d   |   %d   |   %d  |\n-----------------------\n",board[0][j],board[1][j],board[2][j]);
	}
}
void player1()
{
}
