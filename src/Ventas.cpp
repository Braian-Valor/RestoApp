#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Ventas.h"

/// SETS
void Ventas::setIDcliente(int IDcliente){
    _IDcliente=IDcliente;
}
void Ventas::setIDplato(int IDplato){
    _IDplato=IDplato;
}
void Ventas::setFechaVenta(Fecha fecha){
    _fecha=fecha;
}
void Ventas::setCantidad(int cantidad){
    _cantidad=cantidad;
}
void Ventas::setMetodoPago(int metodoDePago){
    _metodoDePago=metodoDePago;
}
void Ventas::setDescuento(float descuento){
    _descuento=descuento;
}
void Ventas::setMontoTotal(float montoTotal){
    _montoTotal=montoTotal;
}

/// GETS
int Ventas::getIDcliente(){return _IDcliente;}
int Ventas::getIDplato(){return _IDcliente;}
Fecha Ventas::getFechaVenta(){return _fecha;}
int Ventas::getCantidad(){return _cantidad;}
int Ventas::getMetodoPago(){return _metodoDePago;}
float Ventas::getDescuento(){return _descuento;}
float Ventas::getMontoTotal(){return _montoTotal;}

/// MOSTRAR
void Ventas::Mostrar(){
    cout << "ID CLIENTE: " << _IDcliente << endl;
    cout << "ID PLATO:   " << _IDplato << endl;
    _fecha.Mostrar();
    cout << "CANTIDAD:   " << _cantidad << endl;
    cout << "METODO DE PAGO: " << _metodoDePago << endl;
    cout << "DESCUENTO:  " << _descuento << endl;
    cout << "MONTO TOTAL: " << _montoTotal << endl;
}

/// ARCHIVOS
bool Ventas::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/ventas.dat", "ab");
    if(p==NULL) {
        return false;
    }
    escribio=fwrite(this, sizeof(Ventas), 1, p);
    fclose(p);
    return escribio;
}
bool Ventas::leerDeDisco(int pos) {
    bool leyo;
    FILE *p;
    p=fopen("datos/ventas.dat", "rb");
    if(p==NULL) {
        return false;
    }
    fseek(p, sizeof(Ventas)*pos, 0);
    leyo=fread(this, sizeof(Ventas), 1, p);
    fclose(p);
    return leyo;
}
