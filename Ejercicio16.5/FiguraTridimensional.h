#pragma once
#include "esfera.h"
#include "cubo.h"
#include "tetaedro.h"

class FiguraTridimensional
{
private:
	esfera esf;
	cubo cub;
	tetaedro tetaedr;
public:
	float getVolumen();

};
