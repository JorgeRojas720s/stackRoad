#include <iostream>
#include "Stack.h"

using namespace std;

void showMatrix(int matrix[7][7]) {

	for (int i = 0; i < 7; i++)
	{
		cout << i << "-> [";
		for (int k = 0; k < 7; k++)
		{

			cout << matrix[i][k] << ",";
		}
		cout << "]" << endl;
	}
}

int main() {

	int matrix[7][7] = {
		{1,1,0,0,0,0,1},
		{0,1,0,0,0,1,0},
		{1,1,1,1,1,1,0},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,1,0},
		{1,0,1,0,0,0,1}
	};

	showMatrix(matrix);

	int startX = 6;
	int startY = 0;
	int endX = 1;
	int endY = 5;

	Stack* stack1 = new Stack();
	Stack* stack2 = new Stack();


	std::cout << "\n" << "-----------------------";
	std::cout << "\n" << "**Camino normal**" << "\n\n";
	stack1->road(matrix, startX, startY, endX, endY);

	std::cout << "\n" << "-----------------------";
	std::cout << "\n" << "**Camino recursivo**" << "\n\n";
	stack2->recursiveRoad(matrix, startX, startY, endX, endY);
	std::cout << "\n" << "-----------------------";

	return 0;
}







//void normalRoad(int matrix[7][7], int startX, int startY, int endX, int  endY) {
//
//	Stack* stack1 = new Stack();
//	std::cout << "\n" << "-----------------------";
//	std::cout << "\n" << "**Camino normal**" << "\n\n";
//	stack1->road(matrix, startX, startY, endX, endY);
//	std::cout << "\n" << "-----------------------";
//
//
//}
//
//void recursiveRoad(int matrix[7][7], int startX, int startY, int endX, int  endY) {
//
//	Stack* stack2 = new Stack();
//	std::cout << "\n" << "-----------------------";
//	std::cout << "\n" << "**Camino recursivo**" << "\n\n";
//	stack2->recursiveRoad(matrix, startX, startY, endX, endY);
//	std::cout << "\n" << "-----------------------";
//}
//
//bool validate(int matrix[7][7], int startX, int startY, int endX, int  endY) {
//
//	if (matrix[startX][startY] != 1 || matrix[endX][endY] != 1) {
//		cout << endl << "*Ubicacion no disponible" << endl;
//		return false;
//	}
//	return true;
//}
//
//void menu(int matrix[7][7]) {
//
//	int startX, startY, endX, endY;
//	cout << endl << "Ingrese las coordenadas de inicio: " << endl;
//	cout << "Fila: "; cin >> startX;
//	cout << "Columna: "; cin >> startY;
//	cout << endl << "Ingrese las coordenadas de fin: " << endl;
//	cout << "Fila: "; cin >> endX;
//	cout << "Columna: "; cin >> endY;
//
//	if (validate(matrix, startX, startY, endX, endY)) {
//
//		int option = 0;
//		cout << endl << "(1) Camino normal";
//		cout << endl << "(2) Camino recursivo";
//		cout << endl << "-> ";
//		cin >> option;
//
//		switch (option) {
//		case 1: normalRoad(matrix, startX, startY, endX, endY);
//			break;
//		case 2: recursiveRoad(matrix, startX, startY, endX, endY);
//			break;
//		default: cout << "Opción no valida";
//		}
//	}
//}