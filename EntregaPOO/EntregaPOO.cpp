#include <iostream>
#include "Hotel.h"
#include "FueraRangoMenu.h"
#include <chrono>
#include <thread>
using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");

    Hotel* miHotel = new Hotel(7, 4, 5, 0.33,50,65,75);
    //miHotel->cargarHotel();
    int opcion = 0;
    while (opcion != 8) {
        int t =opcion==0?100:1;
        cout << "//****************************************************************************\\\\" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||             #     #  #######  #######  #######  #                          ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||             #     #  #     #     #     #        #                          ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||             #######  #     #     #     ####     #                          ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||             #     #  #     #     #     #        #                          ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||             #     #  #######     #     #######  #######                    ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||\033[1m****************************************************************************\033[0m||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||\033[1m****************************************************************************\033[0m||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m1.\033[0m Obtener un listado de las habitaciones disponible de acuerdo a su tipo.||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m2.\033[0m Consultar y modificar el precio de una habitacion de acuerdo a su tipo.||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m3.\033[0m Consultar y modificar el descuento ofrecido a los clientes habituales. ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m4.\033[0m Consultar el precio total para un cliente                              ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m5.\033[0m Reservar una habitación                                                ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m6.\033[0m Eliminar una reserva                                                   || " << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "||  \033[1m7.\033[0m Calcular las ganancias de un mes especifico.                           ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "|| \033[1m 8.\033[0m  SALIR                                                                 ||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));
        cout << "|*****************************************************************************||" << endl; this_thread::sleep_for(std::chrono::milliseconds(t));

        cout << "|  \033[1mIntroduce una opcion:\033[0m" << endl << "|  "; this_thread::sleep_for(std::chrono::milliseconds(t)); 
        cin >> opcion;
        
        try {
            switch (opcion) {
            case 1:
                miHotel->mostrarHabitaciones();
                break;
            case 2:
                miHotel->gestionarPrecio();
                break;
            case 3:
                miHotel->gestionarDescuentoHabit();
                break;
            case 4:
                miHotel->consultarPrecio();
                break;
            case 5:
                miHotel->reservarHabitacion();
                break;
            case 6:
                miHotel->eliminarReserva();
                break;
            case 7:
                miHotel->calcularGanancias();
                break;
            case 8:
                miHotel->cerrarHotel();
                miHotel->~Hotel();
                break;
            default:
                throw FueraRangoMenu();
            }
        }
        catch (FueraRangoMenu& exMenu) {
            cout << exMenu.what()<<endl;
        }
        catch (exception& e)
        {
            cout << "| ERROR: " << e.what();
        }
        catch (...) {
            cout << "| Ha habido un error ";
        }

        cout << endl<<"| ";
        system("pause");
        system("cls");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        return 0;
}