#pragma once
#include "HabitacionDoble.h"
#include "HabitacionMatrimonio.h"
#include "HabitacionSimple.h"
#include "Cliente.h"
#include "Reserva.h"
#include <fstream>

using namespace std;
class Hotel
{
private: 
	//habitaciones
	HabitacionSimple *habSimple;
	int numHabSimples;
	float precioHabitacionSimple;
	HabitacionDoble *habDoble;
	int numHabDobles;
	float precioHabitacionDoble;
	HabitacionMatrimonio  *habMatri;
	int numHabMatri;
	float precioHabitacionMatrimonio;
	float descuentoClientesHabituales;//es sobre 1
	//si ha visitado al menos una vez el hotel, se convierte en habitual
	Cliente *clientes;//aqui solo guardamos los clientes habituales para hacerles descuento
	int numClientes;
	Reserva *reservas;
	int numReservas;
	
public:
	//constructores y destructor
	Hotel();
	Hotel(int habitacionesSimples,int habitacionesDobles, int habitacionesMatrimonio
		,float descuentoClientesHabituales,float precioHabitacionSimple,float precioHabitacionDoble, float precioHabitacionMatrimonio);
	~Hotel();
	
	//metodos complementarios a otros
	int preguntarTipo();
	bool esHabitual(string);
	void anadirCliente(string, string);
	void guardarEstado();
	//mostrar habitaciones 
	void mostrarHabitaciones();
	template<class tipoHab> void obtenerHabitaciones(tipoHab *a,int);
	
	void gestionarPrecio();

	void gestionarDescuentoHabit();

	float calcularPrecio(int,float,string);
	void consultarPrecio();

	void reservarHabitacion();

	void eliminarReserva();

	void calcularGanancias();
	
	void cargarHotel();
	void cerrarHotel();

};

template<class tipoHab>
inline void Hotel::obtenerHabitaciones(tipoHab *a,int cantidad)
{

	for (int i = 0; i < cantidad; i++) {
		if (!a[i].estaOcupada()) {
			a[i].mostrarHabitacion();
		}
		if (i == cantidad - 1) {
			cout << "| ";
		}
	}

}