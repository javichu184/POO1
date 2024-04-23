#pragma once
class Cadena
{
private:
	char* cadena;
	int longitud;

public:
	Cadena();
	Cadena(const char*);
	Cadena(char);
	void cambiaCaracter(int,char);

};

