#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "IngredientesDeCarta.h"

/// SETS
void Ingredientes::setNroPlato(int nroPlato){
    _nroPlato=nroPlato;
}
void Ingredientes::setIDmercaderia(int IDmercaderia){
    _IDmercaderia=IDmercaderia;
}
void Ingredientes::setCant(float cant){
    _cant=cant;
}


/// GETS
int Ingredientes::getNroPlato(){return _nroPlato;}
int Ingredientes::getIDmercaderia(){return _IDmercaderia;}
float Ingredientes::getCant(){return _cant;}


/// MOSTRAR
void Ingredientes::mostrar(){
    cout << "NRO PLATO: " << _nroPlato << endl;
    cout << "ID MERCADERIA: " << _IDmercaderia << endl;
    cout << "CANT: " << _cant << endl;
}


/// ARCHIVOS
bool Ingredientes::escribirEnDisco(){
    bool escribio;
    FILE *p;
    p=fopen("datos/ingredientes.dat", "ab");
    if(p==NULL) {
        return false;
    }
    escribio=fwrite(this, sizeof(Ingredientes), 1, p);
    fclose(p);
    return escribio;
}
bool Ingredientes::leerDeDisco(int pos) {
    bool leyo;
    FILE *p;
    p=fopen("datos/ingredientes.dat", "rb");
    if(p==NULL) {
        return false;
    }
    fseek(p, sizeof(Ingredientes)*pos, 0);
    leyo=fread(this, sizeof(Ingredientes), 1, p);
    fclose(p);
    return leyo;
}
