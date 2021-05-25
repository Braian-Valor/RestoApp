#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
#include "Fecha.h"

/// CONSTRUCTOR - FECHA DEL SISTEMA
Fecha::Fecha(int dia, int mes, int anio) {
    time_t marcaDeTiempo;
    marcaDeTiempo=time(NULL);
    struct tm *fecha;
    fecha=localtime(&marcaDeTiempo);

    _dia=fecha->tm_mday;
    _mes=fecha->tm_mon+1;
    _anio=fecha->tm_year+1900;
}


/// SETS
void Fecha::setDia(int dia){
    _dia=dia;
}

void Fecha::setMes(int mes){
    _mes=mes;
}

void Fecha::setAnio(int anio){
    _anio=anio;
}


/// GETS
int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}


/// CARGAR Y MOSTRAR
void Fecha::Cargar(){
    cout << "DIA: ";
    cin >> _dia;
    cout << "MES: ";
    cin >> _mes;
    cout << "AÑO: ";
    cin >> _anio;
}

void Fecha::Mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio;
}

