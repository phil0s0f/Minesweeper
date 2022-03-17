#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <ctime>  
using namespace std;

const int N = 9;
bool fieldHidden[N][N];//мины
int fieldGame[N][N];//что было вскрыто
char field[N][N];//отображаемое
bool spawned = false;
int gameStart = 0; // 0 - игра не начата, 1 игра идет, -1 - проигрыш, 2 -выигрыш
bool gameState = false;// состояние игры
int endr = 0, startr = 0;

void clearField(char symb = '#') {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = symb;
			fieldGame[i][j] = 0;
			fieldHidden[i][j] = 0;
		}
	}
}

void mineSpawn(int xShot, int yShot,int countMine = 10) {
	srand(time(0));
	int x, y;
	for (int i = 0; i < countMine;) {
		do {
			x = rand() % N;
			y = rand() % N;
		} while (x == xShot && y == yShot);
		if (!fieldHidden[x][y]) {
			fieldGame[x][y] = 1;
			fieldHidden[x][y] = 1;
			i++;
		}
	}
	spawned = true;
}

void showField() {

	cout << "   ";
	for (int i = 0; i < N; i++)
		cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << (char)(i + 65) << '|' << " ";
		for (int j = 0; j < N; j++) {
			cout << field[i][j] << ' ';// показать поле default: field
		}
		cout << '|' << (char)(i + 65);
		cout << endl;
	}
	cout << "   ";
	for (int i = 0; i < N; i++)
		cout << i + 1 << " ";
	cout << endl;
}

int openCell(int x, int y) {
	int cnt = 0;
	for (int i = x - 1; i <= x + 1 && i < N; i++) {
		for (int j = y - 1; j <= y + 1 && j < N; j++) {
			if (i >= 0 && j >= 0)
				cnt += fieldHidden[i][j]; //количество мин вокруг
		}
	}
	field[x][y] = cnt + 0x30;// строковое значение цифры
	return cnt;
}

bool checkWin() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (fieldGame[i][j] == 0)
				return true;
		}
	}
	gameStart = 2;
	return false;
}

bool shot(int x, int y) {
	if (fieldHidden[x][y]) {
		gameStart = -1;
		return false;
	}
	openCell(x, y);
	fieldGame[x][y] = -1;
	return checkWin();
}


void gameOver() {
	cout << "You suck" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(fieldHidden[i][j])
				field[i][j] = '*';// показать поле
		}
	}
}
long youWin() {
	cout << "GC, YOU WIN!!!" << endl;
	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end); // считает время
	return end_time;
	//cout << end_time << endl; //в секундах
}
void game() {
	clearField();
	int y;
	char x;
	do {
		system("cls");
		showField();
		cout << "shot please: ";
		cin >> x >> y;
		/*x = _getch();
		y = _getch();
		y = y - 0x30;*/
		x = x - 65;
		y = y - 1;
		if (!spawned) {
			mineSpawn(x, y);

			auto start = std::chrono::system_clock::now();
			std::time_t start_time = std::chrono::system_clock::to_time_t(start); // считает время
			startr = start_time;
			//cout << end_time << endl; //в секундах

			gameStart = 1;
			gameState = true;
		}
		gameState = shot(x, y);
	} while (gameState);//переделать
	system("cls");
	switch (gameStart) {
	case -1:
		gameOver();
		break;

	case 2:
		endr = youWin();
		cout <<"Ваше время:"<< endr - startr<< endl; //время, перевести в минуты
		break;
	}
	showField();
}