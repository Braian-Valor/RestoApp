#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mercaderias.h"

/// SETS
void Mercaderias::setCodigo(char *codigo){
    strcpy(_codigo, codigo);
}

void Mercaderias::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}

void Mercaderias::setCant(int cant){
    _cant=cant;
}

void Mercaderias::setGastoEntrada(float gastoEntrada){
    _gastoEntrada=gastoEntrada;
}

void Mercaderias::setFecha(Fecha fechaVencimiento){
    _fechaVencimiento=fechaVencimiento;
}

void Mercaderias::setEstado(bool estado){
    _estado=estado;
}


/// GETS
char *Mercaderias::getcodigo(){return _codigo;}
char *Mercaderias::getNombre(){return _nombre;}
int Mercaderias::getCant(){return _cant;}
float Mercaderias::getGastoEntrada(){return _gastoEntrada;}
Fecha Mercaderias::getFecha(){return _fechaVencimiento;}
bool Mercaderias::getEstado(){return _estado;}


/// CARGAR Y MOSTRAR
void Mercaderias::Cargar(){
    cout << "CODIGO:              ";
    cin >> _codigo;
    cout << "NOMBRE:              ";
    cin >> _nombre;
    cout << "CANTIDAD:            ";
    cin >> _cant;
    cout << "GASTO DE ENTRADA:    ";
    cin >> _gastoEntrada;
    cout << "FECHA DE VENCIMIENTO " << endl;
    _fechaVencimiento.Cargar();
}

void Mercaderias::Mostrar(){
    cout << "CODIGO:              " << _codigo << endl;
    cout << "NOMBRE:              " << _nombre << endl;
    cout << "CANTIDAD:            " << _cant << endl;
    cout << "GASTO DE ENTRADA:    " << _gastoEntrada << endl;
    cout << "FECHA DE VENCIMIENTO ";
    _fechaVencimiento.Mostrar();
    cout << endl;
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
