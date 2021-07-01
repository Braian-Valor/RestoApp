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
void Mesas::setMesaOcupada(bool v)
{
    MesaOcupada=v;
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
bool Mesas::getMesaOcupada()
{
    return MesaOcupada;
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
    if(MesaOcupada!=false)
    {
        cout << "  " <<"MESA"  << "        "  << "CAPACIDAD "<<"        "<<endl;
        cout << "   " << NroMesa << "              " << Capacidad << "      ";
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

}
void Mesas::MostrarFalsos()
{
    if(MesaOcupada==false)
    {
        cout << "     " << NroMesa << "            " << Capacidad << "       "<<endl;
    }

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

bool Mesas::ModificarValorMesa(int pos)
{
    FILE *p;
    bool escribio;
    p=fopen("datos/mesas.dat","rb+");
    if(p==NULL)
    {
        cout<< "ERROR DE MEMORIA"<<endl;
        return false;
    }
    fseek(p,sizeof(Mesas)*pos,0);
    escribio=fwrite(this,sizeof(Mesas),1,p);
    fclose(p);
    return escribio;
}
