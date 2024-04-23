#include "Reserva.h"

Reserva::Reserva()
{
	habReservada = 0;
	numDiasOcupado = 0;
	fecha = Enero;
	huesped = Cliente();
}

Reserva::Reserva(Cliente localCliente, int localNumHab, int localnumDiasOcupada, mes fechaReserva)
{
	huesped = localCliente;
	habReservada = localNumHab;
	numDiasOcupado = localnumDiasOcupada;
	fecha=fechaReserva;
}

Reserva::Reserva(const Reserva&antiguo)
{
	huesped = Cliente(antiguo.huesped);
	habReservada = antiguo.habReservada;
	numDiasOcupado = antiguo.numDiasOcupado;
	fecha = antiguo.fecha;
}

Reserva Reserva::operator=(const Reserva&antiguo)
{
	huesped = antiguo.huesped;
	habReservada = antiguo.habReservada;
	
	numDiasOcupado = antiguo.numDiasOcupado;
	fecha = antiguo.fecha;
	return *this;
}

ofstream& operator<<(ofstream& os, const Reserva& reserva)
{
	 os << reserva.fecha <<endl<< reserva.habReservada <<endl << reserva.huesped <<endl<< reserva.numDiasOcupado<<endl;
	 return os;
} 

