#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "IngresoMercaderias.h"

/// SETS
void IngresoMercaderias::setFechaVencimiento(Fecha fechaVencimiento){
    _fechaVencimiento=fechaVencimiento;
}

void IngresoMercaderias::setCantStock(float cantStock){
    _cantStock=cantStock;
}

void IngresoMercaderias::setEstado(bool estado){
    _estado=estado;
}

/// GETS
Fecha IngresoMercaderias::getFechaVencimiento(){return _fechaVencimiento;}
float IngresoMercaderias::getCantStock(){return _cantStock;}
bool IngresoMercaderias::getEstado(){return _estado;}

/// CARGAR Y MOSTRAR
void IngresoMercaderias::Cargar(){
    _fechaVencimiento.Cargar();
    cout << "CANT STOCK: ";
    cin >> _cantStock;
    _estado=true;
}

void IngresoMercaderias::Mostrar(){
    _fechaVencimiento.Mostrar();
    cout << endl;
    cout << "CANT STOCK: " << _cantStock << endl;
}
