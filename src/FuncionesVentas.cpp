#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesReserva.h"
#include "FuncionesCarta.h"
#include "Carta.h"
#include "Fecha.h"
#include "Ventas.h"

void registrarVenta(){
    int IDcliente;
    cout << "INGRESAR ID CLIENTE: ";
    cin >> IDcliente;
    cout << endl;

    if(buscarCliente(IDcliente)==true){
        listarPlatos();
        cout << endl;
        cin.get();

        int nroPlato, cantidad;
        cout << "ELEGIR NRO PLATO: ";
        cin >> nroPlato;
        cout << "CANTIDAD: ";
        cin >> cantidad;
        Fecha f;
        cout << "FECHA: ";
        f.Mostrar();
        cout << endl;
        cout << "METODO DE PAGO: EFECTIVO" << endl;
        /// agregar a la venta
        cin.get();
    }
    else{
        cout << "EL CLIENTE BUSCADO NO EXISTE" << endl;
        cin.get();
    }
}
