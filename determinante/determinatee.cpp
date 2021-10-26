#include "algebra.h"

void visualizar(int matriz[][Can], int orden);
int dermin(int matriz[][Can], int orden);
int inf(int matriz[][Can], int orden, int fila, int columna);
int p1;

//Principal----------------------------------------------------------------------------------
int main()
{
	int matriz[Can][Can];
	int orden;
	limpiar("cls"); system("color b0");

	pos(40, 2); ver << ":::::Determinante de una matriz:::::";
	ver << "\n";
	pos(40, 3); ver << "Ingrese la dimension de la matriz::  ";  ing >> orden;
	while (orden < 0 || orden > Can) {
		pos(40, 5); ver << "\nLa dimension de la matriz no puede ser mayor que " << Can << endl;
		pos(2, 8); ver << "Ingresa nuevamente la dimension de la matriz: ";
		ing >> orden;
		limpiar("cls");
	}
	pos(8, 5); ver << "\nIngrese los elementos de la matriz:\n\n";
	for (int f = 0; f < orden; f++) {
		for (int c = 0; c < orden; c++) {
			ing >> matriz[f][c];
		}
	}
	ver << "-------------------------------------";
	ver << "\n";
	ver << "\nDimension de la matriz ingresada: " << orden << endl;
	ver << "\n-------------------------------------\n";
	ver << "\nMatriz ingresada:\n";
	ver << "\n"; visualizar(matriz, orden);

	ver << "\n-------------------------------------\n";
	ver << "\nEl determinante de la matriz es: " << dermin(matriz, orden) << endl;
	ver << "\n-------------------------------------\n";
	ver << "\n:::::Fin de la Operacion...Gracias por usar el calculo de determinante JJM:::::";
	ver << "\n\n\n"; parar();
	return 0;
}
//Visualizar datos--------------------
void visualizar(int matriz[][Can], int orden)
{// inicio de procedimiento
	
	for (int f = 0; f < orden; f++)
	{// inicio de for de i
		for(int c =0; c< orden; c++)
		{ // inicio de for j
		ver << "\t" << matriz[f][c];
		}// fin de for j
		ver << "\n";
	}// fi de for i
}// fin de procedimiento
//Calculo de determiannte------------------------------------------------------
int dermin(int matriz[][Can], int orden)
{
	int detet = 0.0;
	if (orden == 1) {
		detet = matriz[0][0]; 
	}
	else {
		for (int c = 0; c < orden; c++) {

			detet = detet + matriz[0][c] * inf(matriz, orden, 0, c);
		}
	}
	return detet;
}

int inf(int matriz[][Can], int orden, int fila, int columna)
{
	int raizmatriz[Can][Can];
	int n = orden - 1; int a = 0; int b = 0;
	for (int f = 0; 
		f < orden; f++) {
	for (int c = 0; 
		c < orden; c++) {
	if (f != fila && c != columna) {
				raizmatriz[a][b] = matriz[f][c];
				b++;
		if (b >= n) {
					a++;
					b = 0;
				}
			}
		}
	}return pow(-1.0, fila + columna) * dermin(raizmatriz, n);
}
