#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Carta.h"

/// SETS
void Carta::setNroPlato(int nroPlato){
    _nroPlato=nroPlato;
}
void Carta::setNombrePlato(char *nombrePlato){
    strcpy(_nombrePlato, nombrePlato);
}
void Carta::setPrecioPlato(float precioPlato){
    _precioPlato=precioPlato;
}
void Carta::setEstado(bool estado){
    _estado=estado;
}

/// GETS
int Carta::getNroPlato(){return _nroPlato;}
char *Carta::getNombrePlato(){return _nombrePlato;}
float Carta::getPrecioPlato(){return _precioPlato;}
bool Carta::getEstado(){return _estado;}

/// MOSTRAR
void Carta::Mostrar(){
    cout << _nroPlato << "___" << _nombrePlato << "_____$" << _precioPlato << endl;
}

/// ARCHIVOS
bool Carta::escribirEnDisco() {
    bool escribio;
    FILE *p;
    p=fopen("datos/carta.dat", "ab");
    if(p==NULL) {
        return false;
    }
    escribio=fwrite(this, sizeof(Carta), 1, p);
    fclose(p);
    return escribio;
}

bool Carta::leerDeDisco(int pos) {
    bool leyo;
    FILE *p;
    p=fopen("datos/carta.dat", "rb");
    if(p==NULL) {
        return false;
    }
    fseek(p, sizeof(Carta)*pos, 0);
    leyo=fread(this, sizeof(Carta), 1, p);
    fclose(p);
    return leyo;
}
