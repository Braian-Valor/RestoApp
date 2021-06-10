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
                if(registrarCliente()==true){
                    cout << "CLIENTE REGISTRADO CORRECTAMENTE" << endl;
                    cin.get();
                }
                else{
                    cout << "ERROR, NO SE PUDO REGISTRAR EL CLIENTE" << endl;
                    cin.get();
                }
            }break;

            case 2:{
                int ID;
                cout << "INGRESAR ID DEL CLIENTE A MODIFICAR: ";
                cin >> ID;
                system("cls");
                modificarCliente(ID);
            }break;

            case 3:{
                int ID;
                cout << "INGRESAR ID DE CLIENTE A ELIMINAR: ";
                cin >> ID;
                eliminarCliente(ID);
            }break;

            case 4:{
                int ID;
                cout << "INGRESAR ID DE CONSULTA: ";
                cin >> ID;
                consultaCliente(ID);
            }break;

            case 5:{
                listarClientes();
            }break;
        }
        cin.get();
    }
}
