#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesVentas.h"

void dibujarMenuDeVentas() {
    cout << "     MENU VENTAS             " << endl;
    cout << " --------------------------- " << endl;
    cout << " 1 - HACER UNA VENTA         " << endl;
    cout << " 2 - MODIFICAR / ACTUALIZAR  " << endl;
    cout << " 3 - LISTAR VENTAS           " << endl;
    cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
    cout << " ---------------------------- " << endl;
    cout << endl;
}

void menuDeVentas() {
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir) {
        system("cls");
        dibujarMenuDeVentas();
        cout << "INGRESAR OPCION: ";
        cin >> opcion;
        cin.ignore();
        system("cls");

        switch(opcion) {
            default: {
                cout << "OPCION INCORRECTA";
            }break;

            case 0: {
                salir=true;
                cout << "VOLVIENDO AL MENU PRINCIPAL..";
            }break;

            case 1: {
                registrarVenta();
            }break;
        }
        cin.get();
    }
}
