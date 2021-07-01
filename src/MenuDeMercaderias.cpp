#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "MenuDeMercaderias.h"
#include "FuncionesMercaderias.h"

void dibujarMenuDeMercaderias(){
    cout << "     MENU MERCADERIAS     " << endl;
    cout << " ------------------------ " << endl;
    cout << " 1 - REGISTRAR MERCADERIA " << endl;
    cout << " 2 - MODIFICAR/ACTUALIZAR " << endl;
    cout << " 3 - ELIMINAR             " << endl;
    cout << " 4 - LISTAR MERCADERIA    " << endl;
    cout << " 5 - MERCADERIA A REPONER " << endl;
    cout << " 0 - SALIR DEL PROGRAMA   " << endl;
    cout << " ------------------------ " << endl;
    cout << endl;
}

void menuMercaderias(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir){
        system("cls");
        dibujarMenuDeMercaderias();
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
                if(registrarMercaderia()==true){
                    cout << endl;
                    cout << "MERCADERIA REGISTRADA CON EXITO";
                    cin.get();
                }
                else{
                    cout << endl;
                    cout << "ERROR, NO SE PUDO REALIZAR LA REGISTRACION";
                    cin.get();
                }
            }break;

            case 2:{
                int ID;
                cout << "ID: ";
                cin >> ID;
                modificarMercaderia(ID);
            }break;

            case 3:{
                int ID;
                cout << "ID: ";
                cin >> ID;
                eliminarMercaderia(ID);
            }break;

            case 4:{
                listarMercaderias();
            }break;

            case 5:{
                mercaderiaReponer();
            }break;
        }
        cin.get();
    }
}
