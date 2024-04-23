#pragma once
#include <iostream>
using namespace std;
class Habitacion
{

protected: 
	static int global;
	int numHab;
	bool ocupada;
public:
	//constructor
	Habitacion();

	//getters
	int getNumHab() { return numHab; }
	int getGlobal() { return global; };
	void setGlobal(int a) { global = a; };
	bool estaOcupada() const { return ocupada; };
	void setOcupada(bool a) { ocupada = a; };
	void setNumHab(int numero) { numHab = numero; }

	//metodos
	virtual void mostrarHabitacion();
	void restarGlobal(int);
	
};

