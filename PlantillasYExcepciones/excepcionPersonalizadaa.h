#pragma once
#include <iostream>
using namespace std;
class excepcionPersonalizadaa :
    public out_of_range
{
public:
    excepcionPersonalizadaa() :out_of_range("Pos ha habido un error") {};
};

