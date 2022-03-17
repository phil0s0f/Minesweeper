#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int main() {
    /*SetColor(14, 0);
    cout << "test ";
    SetColor(9, 0);// blue (голубенький)
    cout << "test2\n";
    SetColor(7, 0);//default color
    cout << "test ";
    SetColor(6, 0);//golden
    cout << "test2\n";
    SetColor(5, 0);//dark pink
    cout << "test ";
    SetColor(4, 0);//red
    cout << "red\n";
    SetColor(3, 0);
    cout << "test ";
    SetColor(2, 0);//green
    cout << "green\n";
    SetColor(1, 0);//dark blue
    cout << "test ";
    SetColor(0, 0); // black
    cout << "test2\n";
    SetColor(13, 0);
    cout << "test ";
    SetColor(12, 0);//pink
    cout << "pink\n";
    SetColor(11, 0);
    cout << "test ";
    SetColor(10, 0);
    cout << "test2\n";
    SetColor(8, 0);//grey
    cout << "test ";
    SetColor(15, 0);
    cout << "test2\n";//white
    SetColor(17, 0);//grey
    cout << "test ";
    SetColor(16, 0);
    cout << "test2\n";//white
    SetColor(18, 0);//grey
    cout << "test ";
    SetColor(19, 0);
    cout << "test2\n";//white
    SetColor(20, 0);//grey
    cout << "test ";
    SetColor(21, 0);
    cout << "test2\n";//white
    SetColor(22, 0);//grey
    cout << "test ";
    SetColor(103, 0);
    cout << "test2\n";//white
    SetColor(128, 0);    cout << "test2\n";//white
    */
    //char a;
   // a = _getch();
    return 0;
}