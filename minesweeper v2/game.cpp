#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>  
#include <Windows.h>
#include "controls.h"
#include "minesweeper.h"
#include "records.h"
using namespace std;

int  MINES = 10;
const int N = 9;
bool fieldHidden[N][N];//����
int fieldGame[N][N];//��� ���� �������
bool antiShootField[N][N];//����������
char field[N][N];//������������
bool spawned = false;
int gameStart = 0; // 0 - ���� �� ������, 1 ���� ����, -1 - ��������, 2 -�������
bool gameState = true;// ��������� ����
int endr = 0, startr = 0;

void clearField(char symb = '#') 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			field[i][j] = symb;
			fieldGame[i][j] = 0;
			fieldHidden[i][j] = 0;
			antiShootField[i][j] = 0;
		}
	}
}

int openCell(int x, int y) 
{
	int cnt = 0;
	for (int i = x - 1; i <= x + 1 && i < N; i++)
	{
		for (int j = y - 1; j <= y + 1 && j < N; j++)
		{
			if (i >= 0 && j >= 0)
				cnt += fieldHidden[i][j]; //���������� ��� ������
		}
	}

	field[x][y] = cnt + 0x30;// ��������� �������� �����

	return cnt;
}

void mineSpawn(int xShot, int yShot, int countMine = 10) 
{
	srand(time(0));
	int x, y;
	for (int i = 0; i < countMine;) 
	{
		do 
		{
			x = rand() % N;
			y = rand() % N;
		} while (x == xShot && y == yShot);
		if (!fieldHidden[x][y]) 
		{
			fieldGame[x][y] = 1;
			fieldHidden[x][y] = 1;
			i++;
		}
	}
	spawned = true;
}

void showField(int x, int y) 
{
	gotoxy(47, 2);//
	cout << "   ";
	SetColor(4, 0);//default color

	gotoxy(47, 2);//
	cout << MINES;
	SetColor(15, 0);//default color
	cout << endl;
	for (int i = 0; i < 19; i++)//62
	{
		gotoxy(47 + i, 3);//-9
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 11; i++)
	{
		gotoxy(47, 3 + i);
		SetBackColor();
		cout << " ";
	}

	SetColor(15, 0);//default color
	for (int i = 0; i < N; i++) 
	{
		gotoxy(48, 4 + i);
		for (int j = 0; j < N; j++) 
		{
			if (i == x && j == y) 
			{
				SetColor(128, 0);//���������
				cout << field[i][j]; // �������� ���� default: field
				SetColor(15, 0);//default color
				cout << ' ';
			}
			else 
			{
				if (field[i][j] == '?')
					SetColor(6, 0);
				if (field[i][j] == '0')
					SetColor(0, 0);
				if (field[i][j] == '1')
					SetColor(9, 0);// blue (�����������)
				if (field[i][j] == '2')
					SetColor(2, 0);//green
				if (field[i][j] == '3')
					SetColor(4, 0);//red
				if (field[i][j] == '4')
					SetColor(1, 0);//dark blue
				if (field[i][j] == '5')
					SetColor(5, 0);//dark pink
				if(field[i][j] == '*')
					SetColor(12, 0);//pink
				cout << field[i][j] << ' ';// �������� ���� default: field
				SetColor(15, 0);//default color
			}
		}
		cout << endl;
	}
	SetColor(15, 0);

	for (int i = 0; i < 11; i++)
	{
		gotoxy(66, 3 + i);
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 19; i++)
	{

		gotoxy(47 + i, 13);
		SetBackColor();
		cout << " ";
	}
	SetColor(15, 0);
}



bool checkWin() 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (fieldGame[i][j] == 0)
				return true;//����� ��� �� �������
		}
	}
	gameStart = 2;
	return false;
}

bool antiShoot(int x, int y) 
{
	if (!antiShootField[x][y]) 
	{
		if (fieldGame[x][y] == 0 || fieldGame[x][y] == 1) 
		{
			antiShootField[x][y] = 1;
			field[x][y] = '?';
			MINES--;
			return true;
		}
	}
	else 
	{
		antiShootField[x][y] = 0;
		MINES++;
		field[x][y] = '#';
		return true;
	}
}

bool shot(int x, int y) 
{ // ���������� �� ���������
	if (!antiShootField[x][y]) 
	{
		if (fieldHidden[x][y]) 
		{
			gameStart = -1;
			return false;
		}
		openCell(x, y);
		fieldGame[x][y] = -1;
	}
	return checkWin();
}
bool checkBorder(int x, int y) 
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	return false;
}

void gameOver() 
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (fieldHidden[i][j])
				field[i][j] = '*';// �������� ����
		}
	}

	SetColor(5, 0);
	gotoxy(52, N + 5);
	cout << "YOU LOSE!";

	SetColor(15, 0);//default color
}
long youWin() 
{
	SetColor(6, 0);
	gotoxy(50, N + 4);
	cout << "GC, YOU WIN!!!" << endl;

	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end); // ������� �����
	return end_time;
	//cout << end_time << endl; //� ��������
}


void game() 
{
	system("cls");
	clearField();
	int y;
	int x;
	char name[40] = " ";
	int key;
	x = 0;
	y = 0;
	do 
	{
		gameState = true;

		gotoxy(47, 4);
		showField(x, y);
		key = _getch();
		switch (key) {
		case KEY_UP:
			if (checkBorder(x - 1, y)) 
			{
				x--;
			}
			break;
		case KEY_DOWN:
			if (checkBorder(x + 1, y)) 
			{
				x++;
			}
			break;
		case KEY_RIGHT:
			if (checkBorder(x, y + 1)) 
			{
				y++;
			}
			break;
		case KEY_LEFT:
			if (checkBorder(x, y - 1)) 
			{
				y--;
			}
			break;
		case KEY_SPACE:
			if (!spawned) 
			{
				mineSpawn(x, y);
				
				auto start = std::chrono::system_clock::now();
				std::time_t start_time = std::chrono::system_clock::to_time_t(start); // ������� �����
				startr = start_time;
				//cout << end_time << endl; //� ��������

				gameStart = 1;
			}
			gameState = shot(x, y);
			break;
		case KEY_ENTER:
			antiShoot(x, y);
			break;
		case KEY_ESC:
			gameState = false;
			gameStart = -1;
			break;
		default:
			break;
		}
		
	} while (gameState);//����������
	system("cls");
	switch (gameStart) 
	{
	case -1:
		gameOver();
		break;
	case 2:
		endr = youWin();
		gotoxy(48, N + 6);
		cout << "���� �����: " << endr - startr << " ���." <<endl; //�����, ��������� � ������
		SetColor(15, 0);//default color
		gotoxy(45, N + 7);
		cout << "������� ���� ���: ";
		cin.getline(name, 40);
		gotoxy(45, N + 5);
		cout << "����������� " << name << "!!!";
		addRecord(name, endr - startr);
		break;
	}
	showField(x, y);
	spawned = false;
	gotoxy(36, N + 7);
	cout << "������� ����� ������� ��� �������� � ����..." << endl;
	_getch();
	system("cls");
}