#ifndef _ALGEBRA_H
#define _ ALGEBRA_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#define guardar scanf
#define impr printf
#define pause()  getchar
#define pos gotoxy
#define Can 10
#define ver cout /// definimos codigo 
#define limpiar() system ("cls") // definimos codigo 
#define parar() system ("pause")// definimos codigo 
#define ing cin

using namespace std;
void pos(int x, int y)
{
    COORD coord;
    coord.X = (SHORT)x - 1;
    coord.Y = (SHORT)y - 1;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif

