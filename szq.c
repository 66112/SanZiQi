#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void menu()
{
	printf("**********************************************\n");
	printf("**********    1.  ���  VS ����   ************\n");
	printf("**********    2.  ���1 VS ���2  ************\n");
	printf("**********    3.    �˳���Ϸ      ************\n");
	printf("**********************************************\n");
}
void init_board(char board[ROW][COL], int row, int col)  //��ʼ������
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void show_board(char board[ROW][COL], int row, int col)    //��ӡ����
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
		printf("���1��\n");
		printf("����������(x,y):");
		scanf("%d%d", &x, &y);
		if (x>=1&&x<=row&&y>=1&&y<=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("��λ�����ӣ�\n");
		}
		else
			printf("�������\n");
	}
}
void player2_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("���2��\n");
		printf("����������(x,y):");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
				printf("��λ�����ӣ�\n");
		}
		else
			printf("�������\n");
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("������:\n");
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
	    printf("���ʤ��\n");
	if (win == 'O')
		printf("����ʤ��\n");
	if (win == 'Q')
	    printf("ƽ�֣�\n");
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
		printf("���1ʤ��\n");
	if (win == 'O')
		printf("���2ʤ��\n");
	if (win == 'Q')
		printf("ƽ�֣�\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}