#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mercaderias.h"

/// SETS
void Mercaderias::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}

void Mercaderias::setFechaVencimiento(Fecha fechaVencimiento){
    _fechaVencimiento=fechaVencimiento;
}

void Mercaderias::setCantStock(float cantStock){
    _cantStock=cantStock;
}

void Mercaderias::setEstado(bool estado){
    _estado=estado;
}

/// GETS
char *Mercaderias::getNombre(){return _nombre;}
Fecha Mercaderias::getFechaVencimiento(){return _fechaVencimiento;}
float Mercaderias::getCantStock(){return _cantStock;}
bool Mercaderias::getEstado(){return _estado;}

/// CARGAR Y MOSTRAR
void Mercaderias::Cargar(){
    cout << "NOMBRE:              ";
    cin >> _nombre;
    _fechaVencimiento.Cargar();
    cout << "CANT STOCK: ";
    cin >> _cantStock;
    _estado=true;
}

void Mercaderias::Mostrar(){
    if(_estado==true){
        cout << "NOMBRE:     " << _nombre << endl;
        _fechaVencimiento.Mostrar();
        cout << endl;
        cout << "CANT STOCK: " << _cantStock << endl;
    }
}


/// ARCHIVOS
bool Mercaderias::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/mercaderias.dat", "ab");
    if(p==NULL){
        return false;
    }
    escribio=fwrite(this, sizeof(Mercaderias), 1, p);
    fclose(p);
    return escribio;
}

bool Mercaderias::leerDeDisco(int pos){
    bool leyo;
    FILE *p;
    p=fopen("datos/mercaderias.dat", "rb");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Mercaderias)*pos, 0);
    leyo=fread(this, sizeof(Mercaderias), 1, p);
    fclose(p);
    return leyo;
}
