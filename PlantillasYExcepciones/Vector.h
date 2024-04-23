#pragma once
#include "excepcionPersonalizadaa.h"

template <class T,int LONGITUD>class Vector
{
private:
	T vector[LONGITUD];
	int longitud;
public:
	Vector();
	Vector(const Vector&);
	~Vector();
	T& operator[](int i);
	bool operator>(const Vector& otro) const;
};

template<class T, int LONGITUD>
inline Vector<T, LONGITUD>::Vector()
{
	longitud = LONGITUD;
	for (int i = 0; i < longitud; i++) {

		vector[i] = 0;

	}
}

template<class T, int LONGITUD>
inline Vector<T, LONGITUD>::~Vector()
{
	longitud = 0;
}
template<class T, int LONGITUD>
inline T& Vector<T, LONGITUD>::operator[](int i)
{

	if (i<0 || i>=longitud) {
		throw excepcionPersonalizadaa();
	}
	else {
		return vector[i];
	}
}

template<class T, int LONGITUD>
inline bool Vector<T, LONGITUD>::operator>(const Vector& otro) const
{
	return longitud>otro.longitud;
}

template<class T, int LONGITUD>
inline Vector<T, LONGITUD>::Vector(const Vector& v)
{
	longitud=v.longitud;
	for (int i = 0;i<longitud;i++) {
		vector[i] = v.vector[i];
	}
}