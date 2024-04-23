#pragma once
#include <iostream>
using namespace std;
class FueraRangoMenu :
    public out_of_range
{
public:
    FueraRangoMenu() :out_of_range("| Elige una opcion correcta(1-8)") {};

};

