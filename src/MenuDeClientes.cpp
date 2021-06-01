#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "MenuDeClientes.h"
#include "FuncionesClientes.h"

void dibujarMenuDeClientes(){
    cout << "     MENU CLIENTES           " << endl;
    cout << " ---------------------------- " << endl;
    cout << " 1 - REGISTRAR                " << endl;
    cout << " 2 - MODIFICAR/ACTUALIZAR     " << endl;
    cout << " 3 - ELIMINAR                 " << endl;
    cout << " 4 - CONSULTAR                " << endl;
    cout << " 5 - LISTAR CLIENTES          " << endl;
    cout << " 0 - VOLVER AL MENU PRINCIPAL " << endl;
    cout << " ---------------------------- " << endl;
    cout << endl;
}

void menuClientes(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir){
        system("cls");
        dibujarMenuDeClientes();
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
                registrarCliente();
            }break;

            case 2:{
                modificarCliente();
            }break;

            case 3:{
                eliminarCliente();
            }break;

            case 4:{
                consultaCliente();
            }break;

            case 5:{
                listarClientes();
            }break;
        }
        cin.get();
    }
}
