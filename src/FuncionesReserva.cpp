#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "Reserva.h"
#include "FuncionesReserva.h"

void registrarReserva(){
    bool registro;
    Reserva reg;
    reg.cargar();
    registro=reg.escribirEnDisco();
    if(registro==true){
        cout << "RESERVA REGISTRADA";
        cin.get();
        return;
    }
    else{
        cout << "ERROR, NO SE PUDO REGISTRAR LA RESERVA";
        cin.get();
        return;
    }
}


void listarReservas(){
    int pos=0;
    Reserva reg;
    while(reg.leerDeDisco(pos)==true){
        reg.mostrar();
        pos++;
        cout << endl;
    }
}
