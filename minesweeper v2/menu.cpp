#include "minesweeper.h"
#include "records.h"
#include "controls.h"
#include <iostream>
#include <conio.h>
using namespace std;

void viewUp() 
{
	for (int i = 0; i < 70; i++)//62
	{
		gotoxy(24 + i, 1);//-9
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 15; i++)
	{
		gotoxy(24, 2 + i);
		SetBackColor();
		cout << " ";
	}
	SetColor(15, 0);//default color

}
void viewDown() 
{
	for (int i = 0; i < 15; i++)
	{

		gotoxy(93, 2 + i);
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 70; i++)
	{

		gotoxy(24 + i, 17);
		SetBackColor();
		cout << " ";
	}
	SetColor(15, 0);//default color

}
void view() 
{
	viewUp();

	SetColor(5, 0);
	gotoxy(48, 4);
	cout << "MINESWEEPER";

	SetColor(7, 0);
	gotoxy(46, 7);
	SetColor(3, 0);
	cout << "1. ÍÀ×ÀËÎ ÈÃÐÛ";

	gotoxy(46, 9);
	cout << "2. ÐÅÊÎÐÄÛ";

	gotoxy(46, 11);
	cout << "3. ÊÀÊ ÈÃÐÀÒÜ?";

	gotoxy(46, 13);
	cout << "4. ÂÛÕÎÄ";
	
	viewDown();
	SetColor(15, 0);//default color
}
int menu() 
{
	int key = 0;
	reader();
	sort();

	while (true) {
		view();
		key = _getch();
		key = key - 0x30;
			switch (key) 
			{
			case 1:
				game();
				break;
			case 2:
				system("cls");
				//viewUp();
				showRecord();
				//viewDown();
				//gotoxy(27, 16);
				key = _getch();
				switch (key)
				{
				case KEY_SPACE:
					writer();
					gotoxy(27, 15);
					break;
				default:
					break;
				}
				_getch();
				system("cls");
				break;
			case 3:
				system("cls");
				viewUp();
				viewInstr();
				viewDown();
				gotoxy(27, 16);
				SetColor(8, 0);//grey
				cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ ïåðåõîäà â ãëàâíîå ìåíþ..." << endl;
				SetColor(15, 0);//default color
				_getch();
				system("cls");
				break;
			case 4:
				return 1;
			default:
				//cout << "ÍÅÏÐÀÂÈËÜÍÎ" << endl;
				break;
			}
	}
	return 0;
}