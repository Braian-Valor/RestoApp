#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mercaderias.h"

/// SETS
void Mercaderias::setID(int ID){
    _ID=ID;
}
void Mercaderias::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}
void Mercaderias::setCantStock(float cantStock){
    _cantStock=cantStock;
}
void Mercaderias::setEstado(bool estado){
    _estado=estado;
}


/// GETS
int Mercaderias::getID(){return _ID;}
char *Mercaderias::getNombre(){return _nombre;}
float Mercaderias::getCantStock(){return _cantStock;}
bool Mercaderias::getEstado(){return _estado;}


/// MOSTRAR
void Mercaderias::Mostrar(){
    if(_estado==true){
        cout << "ID: " << _ID << endl;
        cout << "NOMBRE:     " << _nombre << endl;
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
