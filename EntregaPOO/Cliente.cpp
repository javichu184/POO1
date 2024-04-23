#include "Cliente.h"
#include "Reserva.h"
#pragma warning(disable : 4996)
Cliente::Cliente()
{
	nombre = "";
	DNI =  "";
}

Cliente::Cliente(string nombre,string DNI)
{
	this->nombre=nombre;
	this->DNI = DNI;

}

Cliente::Cliente(const Cliente& antiguo)
{
	

	this->nombre = antiguo.nombre;
	this->DNI = antiguo.DNI;
}

Cliente Cliente::operator=(const Cliente& antiguo)
{
	this->nombre= antiguo.nombre;
	this->DNI= antiguo.DNI;
	return *this;
}

ostream& operator<<(ostream& os, const Cliente& cliente)
{
	os << cliente.nombre << endl<< cliente.DNI<<endl;
	return os;
}

ofstream& operator<<(ofstream& os, const Cliente& cliente)
{
	os << cliente.nombre << endl << cliente.DNI << endl;
	return os;
}

