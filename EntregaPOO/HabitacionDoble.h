#pragma once
#include "Habitacion.h"
class HabitacionDoble
	:public Habitacion
{
public:
	//constructor
	HabitacionDoble() :Habitacion(){};

	//metodo usando el polimorfismo
	void mostrarHabitacion();
};

