#include "Habitacion.h"
#include <iostream>
using namespace std;

int Habitacion::global = 0;

Habitacion::Habitacion()
{
	ocupada = false;
	numHab=global;
	global++;
}
/*
Habitacion::~Habitacion()
{
	global = 0;
	ocupada = false;
	numHab = 0;
}
*/
void Habitacion::mostrarHabitacion()
{
	cout << "Habitacion numero " << numHab<<endl;
}

void Habitacion::restarGlobal(int resta)
{
	global-=resta;
}
