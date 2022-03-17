#define _CRT_SECURE_NO_WARNINGS
#include "records.h"
#include "minesweeper.h"
#include "controls.h"
#include <iostream>
#include <Windows.h>
using namespace std;

record* head;

void freeList(record* temp) {
	while (temp) {
		record* tempFree = temp;
		temp = temp->next;
		delete[] tempFree;
	}
}
void sort() {
	record* q = NULL, * temp = head, * now, * next;
	if (temp == NULL)
		return;
	while (temp->next != NULL) {
		now = temp;
		next = temp->next;
		if (now->time > next->time) {
			now->next = next->next;
			next->next = now;
			if (q != NULL) {
				q->next = next;
			}
			else
				head = next;
			q = next;
			temp = now;
		}
		else {
			q = temp;
			temp = temp->next;
		}
	}
}
void showRecord()
{
	int numb = 1;

	record* temp = new struct record[sizeof(record)];
	temp = head;
	while (temp)
	{
		numb++;
		temp = temp->next;

	}

	for (int i = 0; i < 70; i++)//62
	{
		gotoxy(24 + i, 1);//-9
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 10 + numb; i++)
	{
		gotoxy(24, 2 + i);
		SetBackColor();
		cout << " ";
	}
	SetColor(15, 0);//default color

	numb = 1;

	SetColor(15, 0);//default color

	
	gotoxy(27, 2);
	cout << "№";
	gotoxy(30, 2);
	cout << "Имя";
	gotoxy(51, 2);
	cout << "Время";

	temp = head;

	while (temp)
	{
		gotoxy(27, 3 + numb);
		cout << numb << ".";
		gotoxy(30, 3 + numb);
		cout << temp->name;
		gotoxy(51, 3 + numb);
		cout << temp->time << " сек.";
		cout << endl;
		numb++;
		temp = temp->next;

	}
	gotoxy(27, 4 + numb);
	cout << "SPACE - записать в файл." << endl;
	gotoxy(27, 5 + numb);
	SetColor(8, 0);//grey
	cout << "Для выхода в меню нажмите любую клавишу..." << endl;
	SetColor(15, 0);//default color

	for (int i = 0; i < 10 + numb; i++)
	{

		gotoxy(93, 2 + i);
		SetBackColor();
		cout << " ";
	}

	for (int i = 0; i < 70; i++)
	{

		gotoxy(24 + i, 12+ numb);
		SetBackColor();
		cout << " ";
	}
	SetColor(15, 0);//default color
	freeList(temp);
}

void addRecord(char name[40], int time)
{
	if (head) 
	{
		record* temp = new struct record[sizeof(record)];
		temp->next = head;
		head = temp;
		head->time = time;
		for (int i = 0; i < 40; i++)
		{
			head->name[i] = name[i];
		}
		sort();
	}
	else 
	{
		head = new struct record[sizeof(record)];
		head->time = time;
		for (int i = 0; i < 40; i++)
		{
			head->name[i] = name[i];
		}
		
		head->next = NULL;
	}
}

bool testFile(FILE* tester) 
{
	if (tester == NULL) 
	{
		//printf("Ошибка при открытии файла.\n");
		return false;
	}
	return true;
}
void writer() 
{
	FILE* f;
	record* temp = new struct record[sizeof(record)];
	temp = head;
	if (testFile(f = fopen("record.txt", "w")))
	{
		while (temp)
		{
			fprintf(f, "%s ", temp->name);
			fprintf(f, "%i\n", temp->time);
			temp = temp->next;
		}
		fclose(f);
	}
}
void reader() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* f;
	if (testFile(f = fopen("record.txt", "r")))
	{
		while (!feof(f)) { // пока не конец  файла
			if (head)
			{
				record* temp = new struct record[sizeof(record)];
				temp->next = head;
				head = temp;
				fscanf(f, "%s", temp->name);//ФИО
				fscanf(f, "%i\n", &(temp->time));

			}
			else
			{
				head = new struct record[sizeof(record)];
				fscanf(f, "%s", head->name);//ФИО
				fscanf(f, "%i\n", &(head->time));

				head->next = NULL;
			}
			//N++;
		}
		fclose(f);
		sort();
	}
}