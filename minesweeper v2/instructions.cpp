#include <iostream>
#include <conio.h>
#include "minesweeper.h"

using namespace std;

void viewInstr() 
{
	SetColor(15, 0);//default color

	gotoxy(27, 3);
	cout << "���� ���� � ������� ��� ������ �������� ����, �� ���������� ����." << endl;
	gotoxy(27, 4);
	//cout << "���������� ������������ ��� ��������� �������� � ���� ������, � ������� ��������� �����." << endl;
	//gotoxy(27, 5);
	cout << "����� �������� ������ ���������� ���, � ������� �������." << endl;
	gotoxy(27, 5);
	cout << "��� �������� �� ������ ����� ��������." << endl;
	gotoxy(27, 6);
	cout << "���� ������������, ����� �������� ���� ������, �� ���������� ���." << endl;
	gotoxy(27, 7);
	cout << "���� ����������� ������ � ����� � ����� �����������." << endl;

	gotoxy(27, 10);
	SetColor(1, 0);
	cout << "����������" << endl;
	SetColor(15, 0);//default color

	gotoxy(27, 12);
	cout << "SPACEBAR - ��������� ������." << endl;
	gotoxy(27, 13);
	cout << "ENTER - �������� ������." << endl;
	gotoxy(27, 14);
	cout << "��������� - ���������� �������� �� ����." << endl;
	gotoxy(27, 15);
	cout << "ESC - ��� ������ �� ����� ���� (������������� ��� ���������)." << endl;
	SetColor(15, 0);//default color
	
}