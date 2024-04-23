#include <iostream>
#include "Vector.h"
#include "excepcionPersonalizadaa.h"
using namespace std;
int main()
{
	Vector<float, 5> mivectorFloats;
	float dato = 0.0;
	try {
		dato = mivectorFloats[-1];
	}
	catch (excepcionPersonalizadaa& e) {
		cout << "Error personalizao: " << e.what();
	}
	catch (...) {
		cout << "He pillado el error antes";
	}
	
	}
