#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void menu()
{
	printf("**********************************************\n");
	printf("**********    1.  玩家  VS 电脑   ************\n");
	printf("**********    2.  玩家1 VS 玩家2  ************\n");
	printf("**********    3.    退出游戏      ************\n");
	printf("**********************************************\n");
}
void init_board(char board[ROW][COL], int row, int col)  //初始化棋盘
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void show_board(char board[ROW][COL], int row, int col)    //打印棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i< row - 1; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%2c ",board[i][j]);
			if (row - 1 - j)
				printf("|");
		}
      printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (row - 1 - j)
				printf("|");
		}printf("\n");
	}
	for (j = 0; j < col; j++)
	{
		printf("%2c ",board[i][j]);
		if (row - 1 - j)
			printf("|");
	}printf("\n");
}
//void show_board(char board[ROW][COL], int row, int col)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < row -1; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("   ");
//			if (col - j - 1)
//			{
//				printf("|");
//			}
//		}
//		printf("\n");
//
//	}
//}
void player1_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家1走\n");
		printf("请输入坐标(x,y):");
		scanf("%d%d", &x, &y);
		if (x>=1&&x<=row&&y>=1&&y<=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("该位置有子！\n");
		}
		else
			printf("输入错误！\n");
	}
}
void player2_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家2走\n");
		printf("请输入坐标(x,y):");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
				printf("该位置有子！\n");
		}
		else
			printf("输入错误！\n");
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑走:\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
	    y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			return;
		}
	}
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char check_win(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (is_full(board, ROW, COL))
		return 'Q';
	return 0;
}
void game1()
{
	char win = 0;
	char board[ROW][COL];
	init_board(board, ROW, COL);
	show_board(board, ROW, COL);
	do
	{
		player1_move(board, ROW, COL);
		show_board(board, ROW, COL);
		win=check_win(board, ROW, COL);
		if (win != 0)
			break;
		computer_move(board, ROW, COL);
		show_board(board, ROW, COL);
		win = check_win(board, ROW, COL);
	} while (win==0);
	if (win == 'X')
	    printf("玩家胜！\n");
	if (win == 'O')
		printf("电脑胜！\n");
	if (win == 'Q')
	    printf("平局！\n");
}
void game2()
{
	char win = 0;
	char board[ROW][COL];
	init_board(board, ROW, COL);
	show_board(board, ROW, COL);
	do
	{
		player1_move(board, ROW, COL);
		show_board(board, ROW, COL);
		win = check_win(board, ROW, COL);
		if (win != 0)
			break;
		player2_move(board, ROW, COL);
		show_board(board, ROW, COL);
		win = check_win(board, ROW, COL);
	} while (win == 0);
	if (win == 'X')
		printf("玩家1胜！\n");
	if (win == 'O')
		printf("玩家2胜！\n");
	if (win == 'Q')
		printf("平局！\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 3:
			break;
		default:
			printf("输入错误！请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}