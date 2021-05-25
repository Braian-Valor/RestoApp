#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Persona.h"

/// CONSTRUCTOR
Persona::Persona(const char *nombre, const char *apellido, int edad){
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    _edad=edad;
}


/// SETS
void Persona::setNombre(char *nombre){
    strcpy(_nombre, nombre);
}

void Persona::setApellido(char *apellido){
    strcpy(_apellido, apellido);
}

void Persona::setEdad(int edad){
    _edad=edad;
}


/// GETS
char *Persona::getNombre(){return _nombre;}
char *Persona::getApellido(){return _apellido;}
int Persona::getEdad(){return _edad;}


/// CARGAR Y MOSTRAR
void Persona::Cargar(){
    cout << "APELLIDO: ";
    fflush(stdin);
    cin.getline(_apellido, 50);
    cout << "NOMBRE: ";
    fflush(stdin);
    cin.getline(_nombre, 50);
    cout << "EDAD: ";
    cin >> _edad;
}

void Persona::Mostrar(){
    cout << "APELLIDO: " << _apellido << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout << "EDAD: " << _edad << endl;
}
