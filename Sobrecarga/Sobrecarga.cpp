#include "punto2d.h"

int main()
{
	punto2d p1, p2;
	punto2d p3 = p1 + p2;
	p3.mostrarValores();
	cout << p3<<endl;
	punto2d p4(2);
	return 0;
}