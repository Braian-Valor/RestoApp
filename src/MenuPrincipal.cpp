#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "MenuDeClientes.h"
#include "MenuDeReservas.h"
#include "MenuDeMesas.h"
#include "MenuDeMercaderias.h"
#include "MenuDeCarta.h"
#include "MenuDeVentas.h"
#include "MenuReportes.h"

void dibujarMenuPrincipal(){
    cout << "     MENU PRINCIPAL     " << endl;
    cout << " -----------------------" << endl;
    cout << " 1 - CLIENTES           " << endl;
    cout << " 2 - RESERVAS           " << endl;
    cout << " 3 - MESAS              " << endl;
    cout << " 4 - MERCADERIAS        " << endl;
    cout << " 5 - CARTA              " << endl;
    cout << " 6 - VENTAS             " << endl;
    cout << " 7 - REPORTES           " << endl;
    cout << " 0 - SALIR DEL PROGRAMA " << endl;
    cout << " -----------------------" << endl;
    cout << endl;
}

void menuPrincipal(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir){
        system("cls");
        dibujarMenuPrincipal();
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
                cout << "SALIENDO DEL PROGRAMA..";
            }break;

            case 1:{
                menuClientes();
            }break;

            case 2:{
                menuReservas();
            }break;

            case 3:{
                MenuMesas();
            }break;

            case 4:{
                menuMercaderias();
            }break;

            case 5:{
                menuDeCarta();
            }break;

            case 6:{
                menuDeVentas();
            }break;

            case 7:{
                MenuReportes();
            }break;
        }
        cin.get();
    }
}
