#pragma once
#define MAXPILA 5
#include <iostream>
using namespace std;
class Pila
{
private:
	int cima;
	char mat[MAXPILA];

public:
	Pila();
	void push(char);
	char pop()const;
	void mostrar()const;
	bool isEmpty()const;
	bool isFull();



};