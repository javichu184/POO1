#pragma once
#include <iostream>
#include <string>
using namespace std;

class punto2d
{
private:
	float x;
	
	float y;
	friend punto2d operator+(const punto2d& p1, const punto2d& p2);
	friend ostream& operator<< (ostream& os, punto2d& c);
public:
//	punto2d operator+(punto2d);
	punto2d(float x=0, float y=1) {
		this->x = x;
		this->y = y;
	}
//	punto2d() {
//		this->x = 6;
//		this->y = 5;
//	}


	void mostrarValores()const {
		cout << "(" << x << "," << y << ")";

	}
};
