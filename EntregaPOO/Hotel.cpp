#include "Hotel.h"

Hotel::Hotel()
{
	numHabSimples = 0;
	numHabDobles = 0;
	numHabMatri = 0;
	descuentoClientesHabituales = 0.0;
	precioHabitacionSimple = 0;
	precioHabitacionDoble = 0;
	precioHabitacionMatrimonio = 0;
	numClientes = 0;
	numReservas = 0;
	clientes = nullptr;
	habSimple = nullptr;
	habDoble = nullptr;
	habMatri = nullptr;
	reservas = nullptr;
}

Hotel::Hotel(int habitacionesSimples, int habitacionesDobles,
	int habitacionesMatrimonio, float descuentoClientesHabituales,float precioHabitacionSimple,
	float precioHabitacionDoble,float precioHabitacionMatrimonio)
{
	this->precioHabitacionSimple = precioHabitacionSimple;
	this->precioHabitacionDoble = precioHabitacionDoble;
	this->precioHabitacionMatrimonio = precioHabitacionMatrimonio;
	clientes = nullptr;
	reservas = nullptr;
	numClientes = 0;
	numReservas = 0;
	this->descuentoClientesHabituales=descuentoClientesHabituales;

	//Inicializamos las habs simples
	numHabSimples = habitacionesSimples;
	habSimple = new HabitacionSimple[numHabSimples];

	//ya que al crear la array se llama al constructor también, y por lo tanto contariamos las habitaciones 2 veces

	habSimple->restarGlobal(numHabSimples);
	for (int i = 0; i < numHabSimples; i++) {
		habSimple[i] = HabitacionSimple();
	}
	//Inicializamos las habs dobles
	numHabDobles = habitacionesDobles;
	habDoble = new HabitacionDoble[numHabDobles];

	habDoble->restarGlobal(numHabDobles);

	for (int i = 0; i < numHabDobles; i++) {
		habDoble[i] = HabitacionDoble();
	}

	//Inicializamos las habs de matrimonio
	numHabMatri = habitacionesMatrimonio;
	habMatri = new HabitacionMatrimonio[numHabMatri];

	habMatri->restarGlobal(numHabMatri);

	for (int i = 0; i < numHabMatri; i++) {
		habMatri[i] = HabitacionMatrimonio();
	}
}

Hotel::~Hotel()
{
	delete[]habSimple;
	delete[]habDoble;
	delete[]habMatri;
	reservas = nullptr;
	clientes = nullptr;
}

void Hotel::mostrarHabitaciones()
{
	switch (preguntarTipo()) {

	case 1:obtenerHabitaciones(habSimple, numHabSimples);
		break;
	case 2:obtenerHabitaciones(habDoble,numHabDobles);
		break;
	case 3:obtenerHabitaciones(habMatri,numHabMatri);
	break;
	default:
	throw out_of_range("| Opcion no valida, no se ha cambiado el precio");

	}
}

int Hotel::preguntarTipo()
{
	int tipo;
	cout << "| Elige un tipo de habitaciones " << endl;
	cout << "| 1.Habitaciones Simples" << endl;
	cout << "| 2.Habitaciones Dobles" << endl;
	cout << "| 3.Habitaciones de Matrimonio" << endl;
	cout << "| ";
	cin >> tipo;
	return tipo;
}


bool Hotel::esHabitual(string DNI)
{
//ACLARACION
//en este problema no hace falta crear clases derivadas de 'Cliente'
//si quisieramos añadir nuevos tipo de Clientes solo se hace otro puntero en Hotel.h a 'Cliente' y los comparamos si estan ahí.(Como en este método)
	bool habitual=false;
	for (int i = 0;i<numClientes;i++) {
		if (clientes[i].getDNI()==DNI ) {
			habitual = true;
			break;
		}
	}
	return habitual;
}


void Hotel::gestionarPrecio()
{
	 char opcionPrecio;

	switch (preguntarTipo()) {

	case 1:
		
		cout<<"| El precio de la habitacion simple es " << precioHabitacionSimple << " euros. Desea cambiarlo? y/n  " << endl << "| ";
		cin >> opcionPrecio;

		if (opcionPrecio == 'y' || opcionPrecio == 'Y') {
			cout << endl << "| Introduce el nuevo precio: "<<endl<<"| ";
			cin >> precioHabitacionSimple;
			cout << endl << "| El nuevo precio se ha introducido correctamente!" << endl <<"| ";
		}
		else if (opcionPrecio == 'n' || opcionPrecio == 'N') {

		}
		else {
			throw out_of_range("| Opcion no valida, no se ha cambiado el precio");
		}

		break;
	case 2:

		cout << "| El precio de la habitacion doble es " << precioHabitacionDoble << " euros. Desea cambiarlo? y/n  " << endl << "| ";
		cin >> opcionPrecio;

		if (opcionPrecio == 'y' || opcionPrecio == 'Y') {
			cout << endl << "| Introduce el nuevo precio: ";
			cout << "| ";
			cin >> precioHabitacionDoble;
			cout << endl << "| El nuevo precio se ha introducido correctamente!" << endl;
			cout << "| ";
		}
		else if (opcionPrecio == 'n' || opcionPrecio == 'N') {

		}
		else {
			throw out_of_range("| Opcion no valida, no se ha cambiado el precio");
		}
		break;
	case 3:
		cout << "| El precio de la habitacion de matrimonio es " << precioHabitacionMatrimonio << " euros. Desea cambiarlo? y/n  " << endl << "| ";
		cin >> opcionPrecio;

		if (opcionPrecio == 'y' || opcionPrecio == 'Y') {
			cout << endl << "| Introduce el nuevo precio: ";
			cout << "| ";
			cin >> precioHabitacionMatrimonio;
		
			cout << endl << "| El nuevo precio se ha introducido correctamente!" << endl;
		}
		else if (opcionPrecio == 'n' || opcionPrecio == 'N') {

		}
		else {
			throw out_of_range("Opcion no valida, no se ha cambiado el precio");
		}
		break;
	default:
		throw out_of_range("Opcion no valida, elige un numero del 1 al 3");
	}
}

void Hotel::gestionarDescuentoHabit()
{
	char opcion;
	float aux = 0;
	cout <<"| El descuento actualmente es de un "<<descuentoClientesHabituales*100<<"%. Desea cambiarlo? y/n "<<endl<<"| ";
	cin >> opcion;
	
	if (opcion == 'y' || opcion == 'Y') {
		cout << endl<<"| Introduce el nuevo descuento (sobre 100)"<<endl;
		cout << "| ";
		cin >> aux;
		descuentoClientesHabituales=aux/100;
		cout << endl << "| El descuento se ha introducido correctamente!"<<endl;
	}
	else if(opcion=='n'||opcion=='N') {
		
	}
	else {
		throw out_of_range("Opcion no valida, no se ha cambiado el descuento");
	}
}

float Hotel::calcularPrecio(int noches,float precioNoche,string DNI)
{
	float precioFinal;

	precioFinal = esHabitual(DNI) ? precioNoche * noches - precioNoche * noches * descuentoClientesHabituales : precioNoche * noches;

	return precioFinal;
}

void Hotel::consultarPrecio()
{
	int noches, tipo = 0;
	float precioNoche = 0.0;
	float precioFinal=0.0;
	char DNI[20];
	
	cout << "| Introduce el DNI del cliente: "<<endl;
	cout << "| ";
	cin >> DNI;
	cout << "| ¿Cuantas noches se va a hospedar?"<<endl;
	cout << "| ";
		cin >> noches;

		switch (tipo=preguntarTipo()) {
		case 1:precioNoche = precioHabitacionSimple;
			break;
		case 2: precioNoche = precioHabitacionDoble;
			break;
		case 3: precioNoche = precioHabitacionMatrimonio;
			break;
			throw out_of_range("| Opcion no valida, elige un numero del 1 al 3");
		}
		precioFinal = calcularPrecio(noches, precioNoche, DNI);
		cout << "| El precio para esta persona es de: " << precioFinal << " euros";
}

void Hotel::anadirCliente(string nombre,string DNI)
{
	Cliente nuevo=Cliente(nombre, DNI);
	if (numClientes == 0) {
		clientes = new Cliente(nombre,DNI);
		numClientes++;
	}
	else {
		numClientes++;
		Cliente *aux =new Cliente[numClientes];
		for (int i = 0; i < numClientes-1; i++) {
			aux[i] = clientes[i];
		}
		aux[numClientes - 1] = nuevo;
		clientes = aux;
	}
}

void Hotel::reservarHabitacion()
{
	int noches, tipo,numHabitacion=-1;
	float precioNoche = 0.0;
	float precioFinal = 0.0;
	string DNI;
	string nombre;
	int fecha;
	bool esHabitualB = true;
	cout << "| Introduce el DNI del cliente: "<<endl;
	cout << "| ";
	cin >> DNI;
	
	if (!esHabitual(DNI)) {
		cout << "| Este cliente no está en el sistema, puedes escribir su nombre?: "<<endl;
		cout << "| ";
		cin >> nombre;
	}
	cout << "| ¿Que mes (en numero) comienza la estancia?"<<endl;
	cout << "| ";
	cin >> fecha;
	cout << "| ¿Cuantas noches se va a hospedar?" << endl;
	cout << "| ";
	cin >> noches;


	switch(tipo=preguntarTipo()){
	case 1:precioNoche = precioHabitacionSimple;
		break;
	case 2: precioNoche = precioHabitacionDoble;
		break;
	case 3: precioNoche = precioHabitacionMatrimonio;
		break;
	default:
		throw out_of_range("Opcion no valida, elige un numero del 1 al 3");
	}
	precioFinal = calcularPrecio(noches, precioNoche, DNI);

		cout << "| El precio a pagar será de: " << precioFinal << " euros";
		if (!esHabitual(DNI)) {
			anadirCliente(nombre, DNI);
			esHabitualB = false;
		}

	switch (tipo){
	case 1: for (int i = 0; (i < numHabSimples); i++) {
	
		if (habSimple[i].estaOcupada() == false) {
			habSimple[i].setOcupada(true);
			numHabitacion = habSimple[i].getNumHab();
			break;
		}
	}
	break;
	case 2: for (int i = 0; i < numHabDobles; i++) {
		if (habDoble[i].estaOcupada() == false) {
			habDoble[i].setOcupada(true);
			numHabitacion = habDoble[i].getNumHab();
			break;
		}
	}
		  break;
	case 3: for (int i = 0; i < numHabMatri; i++) {
		if (habMatri[i].estaOcupada() == false) {
			habMatri[i].setOcupada(true);
			numHabitacion = habMatri[i].getNumHab();
			break;
		}
	}
		  break;
	default:
		  throw out_of_range("Ha habido un problema interno");
	}
	if (numHabitacion == -1) {
		throw out_of_range("Ha habido un problema interno");
	}
	Cliente auxReserva = Cliente(nombre,DNI);
	if (numReservas == 0) {
		numReservas++;

		reservas = new Reserva(auxReserva, numHabitacion, noches, static_cast<mes>(fecha));
	}
	else {
		numReservas++;
		Reserva* aux = new Reserva[numReservas];
	
		for (int i = 0; i < numReservas-1; i++) {
			aux[i] = reservas[i];
		}
		aux[numReservas - 1] = Reserva(auxReserva, numHabitacion, noches, static_cast<mes>(fecha));
		reservas = aux;
	
	}
}

void Hotel::eliminarReserva()
{
	int numHabitacion;
	bool existe=false;
	cout << "| Introduce el numero de habitacion de la reserva a eliminar"<<endl<<"| ";
	cin >> numHabitacion;

	for (int i = 0; i < numReservas; i++) {
		if (reservas[i].getHabReservada() == numHabitacion) {
			existe = true;
		}
	}
	if (existe) {
		int j = 0;
		Reserva* aux = new Reserva[numReservas-1];
		for (int i = 0; i < numReservas; i++) {
			if (reservas[i].getHabReservada() != numHabitacion) {
				aux[j] = reservas[i];
				j++;
			}
			else {
				//buscar de que tipo es
				//ya que estan en orden las habitaciones de cada tipo
				if (numHabitacion < numHabSimples) {
					habSimple[numHabitacion].setOcupada(false);
				}
				else if (numHabitacion >= numHabSimples && numHabitacion < numHabDobles + numHabSimples) {
					habDoble[numHabitacion - numHabSimples].setOcupada(false);
				}
				else if (numHabitacion >= numHabDobles + numHabSimples) {
					habMatri[numHabitacion - numHabSimples - numHabDobles].setOcupada(false);
				}
				cout << "| La reserva se ha eliminado con exito!" << endl;
				}	
			}
		numReservas--;
		reservas = aux;
		}
		else{
			throw invalid_argument("No se ha encontrado ninguna reserva con esos datos");
		}
	}

void Hotel::calcularGanancias()
{
	int numMES;
	float totalGanancias = 0.0;
	float precioTipo = 0.0;
	cout << "| Introduce el mes (numero) a calcular:";
	cin >> numMES;
	for (int i = 0; i < numReservas; i++) {
		if (static_cast<int>(reservas[i].getFecha()) == numMES) {

			for (int ii = 0; ii < numHabSimples; ii++) {
				if (reservas[ii].getHabReservada() == habSimple[ii].getNumHab()) {
					precioTipo=precioHabitacionSimple;
				}
				for (int iii = 0; iii < numHabDobles; iii++) {
					if (reservas[iii].getHabReservada() == habSimple[iii].getNumHab()) {
						precioTipo = precioHabitacionDoble;
					}
				}
				for (int iv = 0; iv < numHabMatri; iv++) {
					if (reservas[iv].getHabReservada() == habSimple[iv].getNumHab()) {
						precioTipo=precioHabitacionMatrimonio;
					}

					totalGanancias += calcularPrecio(reservas[i].getNumDiasOcupado(),
						precioTipo,
						reservas[i].getCliente().getDNI());

				};
			}
		}
	}
	cout << "| El dinero esperado para ese mes es de: "<<totalGanancias<< " euros";
	}

void Hotel::cargarHotel()
{

	ifstream archivoEntrada("guardado.txt");
	if (!archivoEntrada) {
		cerr << "| No se pudo abrir el archivo.";
	}
	else {

		int aux;
		string nombre, DNI;
		archivoEntrada >> numHabSimples >> ws >> numHabDobles >> ws >> numHabMatri >> ws
			>> precioHabitacionSimple >> ws >> precioHabitacionDoble >> ws >> precioHabitacionMatrimonio >> ws
			>> descuentoClientesHabituales >> ws;

		archivoEntrada >> aux >> ws; habSimple->setGlobal(aux);
		archivoEntrada >> numClientes >> ws >> numReservas >> ws;

		habSimple = new HabitacionSimple[numHabSimples];
		for (int i = 0; i < numHabSimples; i++) {

			archivoEntrada >> aux >> ws; habSimple[i].setOcupada(aux == 1 ? true : false);

			archivoEntrada >> aux >> ws; habSimple[i].setNumHab(aux);
		}
		habDoble = new HabitacionDoble[numHabDobles];
		for (int i = 0; i < numHabDobles; i++) {
			archivoEntrada >> aux >> ws; habDoble[i].setOcupada(aux == 1 ? true : false);

			archivoEntrada >> aux >> ws; habDoble[i].setNumHab(aux);
		}
		habMatri = new HabitacionMatrimonio[numHabMatri];
		for (int i = 0; i < numHabMatri; i++) {
			archivoEntrada >> aux >> ws; habMatri[i].setOcupada(aux == 1 ? true : false);

			archivoEntrada >> aux >> ws; habMatri[i].setNumHab(aux);

			clientes = new Cliente[numClientes];
			for (int i = 0; i < numClientes; i++) {
				archivoEntrada >> nombre >> ws >> DNI >> ws;
				clientes[i].setNombre(nombre); clientes[i].setDNI(DNI);
			}
			reservas = new Reserva[numReservas];
			for (int i = 0; i < numReservas; i++) {
				archivoEntrada >> aux >> ws; reservas[i].setFecha(aux);
				archivoEntrada >> aux >> ws; reservas[i].setHabReservada(aux);
				archivoEntrada >> nombre >> ws >> DNI >> ws; reservas[i].setHuesped(nombre, DNI);
				archivoEntrada >> aux >> ws; reservas[i].setNumDiasOcupado(aux);
				
			}
			archivoEntrada.close(); 
		}
	}
}

	void Hotel::cerrarHotel()
	{
		char opcion;
		cout << "| ¿Desea guardar los datos? y/n"<<endl<<"| ";
		cin >> opcion;

		if (opcion == 'y' || opcion == 'Y') {
			guardarEstado();
		}
	}

	void Hotel::guardarEstado()
	{
		ofstream archivoSalida("guardado.txt");

		if (archivoSalida.is_open()) {
			archivoSalida << numHabSimples << endl << numHabDobles << endl << numHabMatri << endl;
			archivoSalida << precioHabitacionSimple << endl << precioHabitacionDoble << endl << precioHabitacionMatrimonio << endl;
			archivoSalida << descuentoClientesHabituales << endl;

			archivoSalida << habSimple->getGlobal() << endl;
			archivoSalida << numClientes<<endl;
			archivoSalida << numReservas<<endl;
			for (int i = 0; i < numHabSimples; i++) {
				archivoSalida << habSimple[i].estaOcupada() << endl;
				archivoSalida << habSimple[i].getNumHab() << endl;
			}

			for (int i = 0; i < numHabDobles; i++) {
				archivoSalida << habDoble[i].estaOcupada() << endl;
				archivoSalida << habDoble[i].getNumHab() << endl;
			}
			for (int i = 0; i < numHabMatri; i++) {
				archivoSalida << habMatri[i].estaOcupada() << endl;
				archivoSalida << habMatri[i].getNumHab() << endl;
			}
			for (int i = 0; i < numClientes; i++) {
				archivoSalida << clientes[i];
			}
			for (int i = 0; i < numReservas; i++) {
				archivoSalida << reservas[i];
			}
		}
		else {
			cout << "| No se pudo abrir el archivo." << endl;
		}
		archivoSalida.close();
	}