#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "MenuDeMercaderias.h"

void dibujarMenuDeMercaderias(){
    cout << "     MENU MERCADERIAS     " << endl;
    cout << " ------------------------ " << endl;
    cout << " 1 - REGISTRAR MERCADERIA " << endl;
    cout << " 2 - MODIFICAR/ACTUALIZAR " << endl;
    cout << " 3 -               " << endl;
    cout << " 4 - LISTAR MERCADERIA    " << endl;
    cout << " 0 - SALIR DEL PROGRAMA   " << endl;
    cout << " ------------------------ " << endl;
    cout << endl;
}

void menuMercaderias(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir) {
        system("cls");
        dibujarMenuDeMercaderias();
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
        }
        cin.get();
    }

}
