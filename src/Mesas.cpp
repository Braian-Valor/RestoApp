#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mesas.h"

/// SETS
void Mesas::setNroMesa(int nroMesa){
    _nroMesa=nroMesa;
}

void Mesas::setCapacidad(int capacidad){
    _capacidad=capacidad;
}

void Mesas::setEstado(bool estado){
    _estado=estado;
}


/// GETS
int Mesas::getNroMesa(){return _nroMesa;}
int Mesas::getCapacidad(){return _capacidad;}
bool Mesas::getEstado(){return _estado;}


/// CARGAR Y MOSTRAR
void Mesas::Cargar(){
    cout << "Nro DE MESA: ";
    cin >> _nroMesa;
    cout << "CAPACIDAD: ";
    cin >> _capacidad;
    _estado=true;
}

void Mesas::Mostrar(){
    //cout << "Nro DE MESA | CAPACIDAD | ESTADO " << endl;
    if(_estado==true){
        cout << "     " << _nroMesa << "            " << _capacidad << "       ";
        if (_estado==true){
            cout << "DISPONIBLE";
        }
        cout << endl;
    }
}

/// ARCHIVOS
bool Mesas::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/mesas.dat", "ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this, sizeof(Mesas), 1, p);
    fclose(p);
    return escribio;
}

bool Mesas::leerDeDisco(int pos){
    bool leyo;
    FILE *p;
    p=fopen("datos/mesas.dat", "rb");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Mesas)*pos,0);
    leyo=fread(this, sizeof(Mesas), 1, p);
    fclose(p);
    return leyo;
}
