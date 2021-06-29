#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesCarta.h"

void dibujarMenuDeCarta(){
    cout << "     MENU CARTA                       " << endl;
    cout << " ------------------------------------ " << endl;
    cout << " 1 - REGISTRAR PLATO                  " << endl;
    cout << " 2 - ACTUALIZAR PRECIO                " << endl;
    cout << " 3 - INGREDIENTES DE PLATO            " << endl;
    cout << " 4 - LISTAR PLATOS                    " << endl;
    cout << " 5 - MOSTRAR INGREDIENTES DE UN PLATO " << endl;
    cout << " 0 - VOLVER AL MENU PRINCIPAL         " << endl;
    cout << " ------------------------------------ " << endl;
    cout << endl;
}

void menuDeCarta(){
    setlocale(LC_CTYPE, "Spanish");

    bool salir=false;
    int opcion;

    while(!salir) {
        system("cls");
        dibujarMenuDeCarta();
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
                if(registrarPlato()==true){
                    cout << "PLATO REGISTRADO" << endl;
                    cin.get();
                }
                else{
                    cout << "ERROR, NO SE PUDO REGISTRAR EL PLATO" << endl;
                    cin.get();
                }
            }break;

            case 2: {
                int nroPlato;
                cout << "INGRESAR NRO PLATO: ";
                cin >> nroPlato;
                if(actualizarPrecio(nroPlato)==true){
                    cout << "PRECIO ACTUALIZADO" << endl;
                    cin.get();
                }
                else{
                    cout << "ERROR, NO SE ENCONTRO EL PLATO" << endl;
                    cin.get();
                }
            }break;

            case 3:{
                if(registrarIngredientesDePlato()==true){
                    cout << "INGREDIENTES DE PLATO REGISTRADO" << endl;
                    cin.get();
                }
                else{
                    cout << "ERROR, NO SE PUDO REGISTRAR EL INGREDIENTE DEL PLATO" << endl;
                    cin.get();
                }
            }break;

            case 4:{
                listarPlatos();
            }break;

            case 5:{
                int nroPlato;
                cout << "INGRESAR NRO PLATO: ";
                cin >> nroPlato;
                listarIngredientesDePlato(nroPlato);
                cin.get();
            }break;
        }
        cin.get();
    }
}
