// 1 сложность 9х9 10 мин
// 2 сложность 16х16 40 мин
// 3 сложность 16х30 99 мин
//#include <iostream>
#include "minesweeper.h"
#include <Windows.h>
using namespace std;
/*
void displayField() {
	//int fieldTemp[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			//fieldTemp[i][j] = 0;
			cout << '#';
		cout << endl;
	}
	//return fieldTemp;
}
// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}*/

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//srand(time(0));
	/*int field[9][9];
	int mines[9][9];
	int mineCount = 10;
	int mineSpawn;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			field[i][j] = 0;
			mines[i][j] = 0;
		}
	}
	displayField();
	//while (mineCount != 0) {
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				mineSpawn = 0 + (rand() % 100 + 1);
				if (mineSpawn < 15 && mineCount > 0) {
					mines[i][j] = 1;
					mineCount--;
				}
			}
		}
		
	//}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << mines[i][j];
		}
		cout << endl;
	}
	*/
	game();
	return 0;
}
