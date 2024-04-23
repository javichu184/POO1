#pragma once

#include <iostream>
using namespace std;
class Persona
{
private:
	string name;
	int age;
public:
	Persona();
	Persona(string, int);
	Persona(const Persona&);
		void caminar()const;
		;
	};

