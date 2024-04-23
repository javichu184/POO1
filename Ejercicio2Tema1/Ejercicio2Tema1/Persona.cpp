#include "Persona.h"

Persona::Persona()
{
	name = "Pedro";
	age = 18;
}

Persona::Persona(string name,int age)
{
	this->name = name;
	this->age = age;
}
Persona::Persona(const Persona& original) {
	name = original.name;
	age = original.age;
}
void Persona::caminar()const
{
	cout << "estoy caminando";
}
