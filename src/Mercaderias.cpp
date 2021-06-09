#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mercaderias.h"

/// SETS
void Mercaderias::setTipoAlimento(char *tipoAlimento){
    strcpy(_tipoAlimento, tipoAlimento);
}

void Mercaderias::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}


/// GETS
char *Mercaderias::getTipoAlimento(){return _tipoAlimento;}
char *Mercaderias::getNombre(){return _nombre;}


/// CARGAR Y MOSTRAR
void Mercaderias::Cargar(){
    cout << "TIPO ALIMENTO:       ";
    cin >> _tipoAlimento;
    cout << "NOMBRE:              ";
    cin >> _nombre;
    IngresoMercaderias::Cargar();
}

void Mercaderias::Mostrar(){
    cout << "TIPO ALIMENTO:       " << _tipoAlimento << endl;
    cout << "NOMBRE:              " << _nombre << endl;
    IngresoMercaderias::Mostrar();
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
