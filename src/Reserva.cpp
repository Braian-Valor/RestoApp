#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Reserva.h"
//#include "Fecha.h"

/// SETS
void Reserva::setNroMesa(int nroMesa){
    _nroMesa=nroMesa;
}

void Reserva::setIDcliente(int IDcliente){
    _IDcliente=IDcliente;
}

void Reserva::setFecha(Fecha fecha){
    _fecha=fecha;
}

void Reserva::setHora(int hora){
    _hora=hora;
}

void Reserva::setMinutos(int minutos){
    _minutos=minutos;
}

void Reserva::setEstado(bool estado){
    _estado=estado;
}


/// GETS
int Reserva::getNroMesa(){return _nroMesa;}
int Reserva::getIDcliente(){return _IDcliente;}
Fecha Reserva::getFecha(){return _fecha;}
int Reserva::getHora(){return _hora;}
int Reserva::getMinutos(){return _minutos;}
bool Reserva::getEstado(){return _estado;}


/// ARCHIVOS
bool Reserva::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/reservas.dat", "ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this, sizeof(Reserva), 1, p);
    fclose(p);
    return escribio;
}

bool Reserva::leerDeDisco(int pos){
    bool leyo;
    FILE *p;
    p=fopen("datos/reservas.dat", "rb");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Reserva)*pos, 0);
    leyo=fread(this, sizeof(Reserva), 1, p);
    fclose(p);
    return leyo;
}

/// CARGAR Y MOSTRAR
void Reserva::cargar(){
    cout << "NRO MESA: ";
    cin >> _nroMesa;
    cout << "ID CLIENTE: ";
    cin >> _IDcliente;
    cout << "FECHA: " << endl;
    _fecha.Cargar();
    cout << "HORA: ";
    cin >> _hora;
    cout << "MINUTOS: ";
    cin >> _minutos;
    _estado=true;
}

void Reserva::mostrar(){
    cout << "NRO MESA: " << _nroMesa << endl;
    cout << "ID CLIENTE: " << _IDcliente << endl;;
    _fecha.Mostrar();
    cout << endl;
    cout << "HORA: " << _hora << endl;
    cout << "MINUTOS: " << _minutos << endl;
}
