#include <iostream>
#include <conio.h>
#include "minesweeper.h"

using namespace std;

void viewInstr() 
{
	SetColor(15, 0);//default color

	gotoxy(27, 3);
	cout << "÷ель игры Ч открыть все клетки игрового пол€, не содержащие мины." << endl;
	gotoxy(27, 4);
	//cout << "ќпределить расположение мин позвол€ют соседние с ними клетки, в которых наход€тс€ числа." << endl;
	//gotoxy(27, 5);
	cout << "„исла означают точное количество мин, в смежных клетках." << endl;
	gotoxy(27, 5);
	cout << "ƒл€ удобства на клетки можно помечать." << endl;
	gotoxy(27, 6);
	cout << "»гра выигрываетс€, после открыти€ всех клеток, не содержащих мин." << endl;
	gotoxy(27, 7);
	cout << "≈сли открываетс€ клетка с миной Ч игрок проигрывает." << endl;

	gotoxy(27, 10);
	SetColor(1, 0);
	cout << "”правление" << endl;
	SetColor(15, 0);//default color

	gotoxy(27, 12);
	cout << "SPACEBAR - открывает клетку." << endl;
	gotoxy(27, 13);
	cout << "ENTER - отмечает клетку." << endl;
	gotoxy(27, 14);
	cout << "—трелочки - перемещают корретку по полю." << endl;
	gotoxy(27, 15);
	cout << "ESC - дл€ выхода во врем€ игры (засчитываетс€ как поражение)." << endl;
	SetColor(15, 0);//default color
	
}