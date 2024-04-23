#include "Pila.h"

Pila::Pila()
{
	cima = -1;
}
bool Pila::isEmpty()const {
	return cima == -1;

}
bool Pila::isFull() {
	return cima == MAXPILA - 1;

}
void Pila::push(char caracter) {
	if (isFull()) {
		cout << "Pila llena" << endl;
	}
	else {
		cima++;
		mat[cima] = caracter;

	}
	void Pila::pop()const {
		char caracter = '\0';

	}
}