#pragma once
#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
class Cliente
{
private:

	string nombre;
	string DNI;

public:
	//constructores
	Cliente();
	Cliente(string, string);
	Cliente(const Cliente&);
	
	//getters y setters
	string getDNI() { return DNI; }
	string getNombre() { return nombre; }
	void setDNI(string dni) { DNI = dni; }
	void setNombre(string nombre) { this->nombre=nombre; }

	//sobrecargas
	Cliente operator=(const Cliente&);
	friend ostream& operator<<(ostream& os, const Cliente& cliente);
	friend ofstream& operator<<(ofstream& os, const Cliente& cliente);
};

