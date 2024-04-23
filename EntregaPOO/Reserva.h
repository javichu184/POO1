#pragma once
#include "Cliente.h"
#include <iostream>
#include <fstream> 
enum mes { Enero=1, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre };
using namespace std;
class Reserva
{
private:
	Cliente huesped;
	int habReservada;
	int numDiasOcupado;
	mes fecha;

public:
	//constructores
	Reserva();
	Reserva(Cliente,int,int, mes);
	Reserva(const Reserva&);

	//getters y setters
	int getHabReservada() { return habReservada; };
	int getNumDiasOcupado() { return numDiasOcupado; };
	mes getFecha() { return fecha; }
	Cliente getCliente() { return huesped; }
	void setHuesped(string nombre, string DNI) {huesped = Cliente(nombre, DNI);}
	void setHabReservada(int nuevaHabReservada) {habReservada = nuevaHabReservada;}
	void setNumDiasOcupado(int nuevosDias) {numDiasOcupado = nuevosDias;}
	void setFecha(int nuevaFecha) {fecha = static_cast<mes>(nuevaFecha);}

	//sobrecargas
	friend ofstream& operator<<(ofstream& os, const Reserva& reserva);
	Reserva operator=(const Reserva&);
};