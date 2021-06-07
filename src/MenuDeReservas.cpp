#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "MenuDeReservas.h"
#include "FuncionesReserva.h"

void dibujarMenuDeReservas(){
    cout << "     MENU RESERVAS            " << endl;
    cout << " ---------------------------- " << endl;
    cout << " 1 - REGISTRAR RESERVA        " << endl;
    cout << " 2 -                       " << endl;
    cout << " 3 -                      " << endl;
    cout << " 4 -                     " << endl;
    cout << " 5 - LISTAR RESERVAS          " << endl;
    cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
    cout << " ---------------------------- " << endl;
    cout << endl;
}

void menuReservas(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir){
        system("cls");
        dibujarMenuDeReservas();
        cout << "INGRESAR OPCION: ";
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch(opcion){
            default:{
                cout << "OPCION INCORRECTA";
            }break;

            case 0:{
                salir=true;
                cout << "VOLVIENDO AL MENU PRINCIPAL..";
            }break;

            case 1:{
                registrarReserva();
            }break;



            case 5:{
                listarReservas();
            }break;

        }
        cin.get();
    }
}