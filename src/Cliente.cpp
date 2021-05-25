#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Cliente.h"

/// SETS
void Cliente::setID(int ID){
    _ID=ID;
}

void Cliente::setFecha(Fecha fechaIngreso){
    _fechaIngreso=fechaIngreso;
}

void Cliente::setNroMesa(int nroMesa){
    _nroMesa=nroMesa;
}

void Cliente::setEstado(bool estado){
    _estado=estado;
}


/// GETS
int Cliente::getID(){return _ID;}
Fecha Cliente::getFecha(){return _fechaIngreso;}
int Cliente::getNroMesa(){return _nroMesa;}
bool Cliente::getEstado(){return _estado;}


/// CARGAR Y MOSTRAR
void Cliente::Cargar(){
    cout << "ID: ";
    cin >> _ID;
    Persona::Cargar();
    cout << "FECHA DE INGRESO" << endl;
    _fechaIngreso.Cargar();
    cout << "Nro DE MESA: ";
    cin >> _nroMesa;
    _estado=true;
    cout << endl;
}

void Cliente::Mostrar(){
    if(_estado==true){
        cout << "ID: " << _ID << endl;
        Persona::Mostrar();
        _fechaIngreso.Mostrar();
        cout << endl;
        cout << "Nro DE MESA: " << _nroMesa << endl;
        cout << endl;
    }
}


/// ARCHIVOS
bool Cliente::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/clientes.dat", "ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

bool Cliente::leerDeDisco(int pos){
    bool leyo;
    FILE *p;
    p=fopen("datos/clientes.dat", "rb");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Cliente)*pos,0);
    leyo=fread(this, sizeof(Cliente), 1, p);
    fclose(p);
    return leyo;
}
