#pragma once
#include <iostream>
using namespace std;
class excepcionPersonalizada :
    public out_of_range
{
public:
    excepcionPersonalizada() :out_of_range("Pos ha habido un error") {};


};

