#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Mesas.h"

/// SETS


void Mesas::setNroMesa(int nroMesa)
{
    NroMesa=nroMesa;                                        ///Validaciones de valores Negativos
}

void Mesas::setCapacidad(int capacidad)
{
    Capacidad=capacidad;
}

void Mesas::setEstado(bool estado)
{
    Estado=estado;
}
void Mesas::setFecha(Fecha f)
{
    Dia_Horario=f;
}

/// GETS

int Mesas::getNroMesa()
{
    return NroMesa;
}
int Mesas::getCapacidad()
{
    return Capacidad;
}
bool Mesas::getEstado()
{
    return Estado;
}
Fecha Mesas::getFecha()
{
    return Dia_Horario;
}


/// CARGAR Y MOSTRAR
void Mesas::Cargar()
{
    cout << "Nro DE MESA: ";
    cin >> NroMesa;
    cout << "CAPACIDAD: ";
    cin >> Capacidad;
    Estado=true;
}

void Mesas::Mostrar()
{
    //cout << "Nro DE MESA | CAPACIDAD | ESTADO " << endl;

    cout << "     " << NroMesa << "            " << Capacidad << "       ";
    if (Estado==true)
    {
        cout << "DISPONIBLE";
    }
    else
    {
        cout<< "NO DISPONIBLE";
    }
    cout << endl;

}

/// ARCHIVOS
bool Mesas::escribirEnDisco()
{
    bool escribio;
    FILE *p;
    p=fopen("datos/mesas.dat", "ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this, sizeof(Mesas), 1, p);
    fclose(p);
    return escribio;
}

bool Mesas::leerDeDisco(int pos)
{
    bool leyo;
    FILE *p;
    p=fopen("datos/mesas.dat", "rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Mesas)*pos,0);
    leyo=fread(this, sizeof(Mesas), 1, p);
    fclose(p);
    return leyo;
}
