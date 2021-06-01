#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#include "Delivery.h"

/// SETS

void Delivery::setIdDelivery(int id)
{
    _idDelivery = id;
}

void Delivery::setIdVenta(int id)
{
    _idVenta = id;
}

void Delivery::setDomicilio(char *dom)
{
    strcpy(_domicilio, dom);
}

void Delivery::setTelefono(char *tel)
{
    strcpy(_telefono, tel);
}

void Delivery::setMontoDelivery(float monto)
{
    _montoDelivery = monto;
}

/// GETS

int Delivery::getIdDelivery()
{
    return _idDelivery;
}

int Delivery::getIdVenta()
{
    return _idVenta;
}

char *Delivery::getDomicilio()
{
    return _domicilio;
}

char *Delivery::getTelefono()
{
    return _telefono;
}

float Delivery::getMonto()
{
    return _montoDelivery;
}

/// CARGAR/MOSTRAR

void Delivery::Cargar()

{
    cout<<"Ingrese ID Delivery:         ";
    cin>>_idDelivery;
    cout<<endl;
    cout<<"Ingrese ID de venta:         ";
    cin>>_idVenta;
    cout<<endl;
    cout<<"Ingrese domicilio:         ";
    cin>>_domicilio;
    cout<<endl;
    cout<<"Ingrese telefono:         ";
    cin>>_telefono;
    cout<<endl;
    cout<<"Ingrese monto del delivery:         ";
    cin>>_montoDelivery;
    cout<<endl;

    cout<<"Delivery registrado con exito!"<<endl;
    Mostrar();
}

void Delivery::Mostrar()
{


    cout<<"ID Delivery: "<<_idDelivery<<endl;
    cout<<"ID Venta: "<<_idVenta<<endl;
    cout<<"Domicilio: "<<_domicilio<<endl;
    cout<<"Telefono: "<<_telefono<<endl;
    cout<<"Monto Delivery: "<<_montoDelivery<<endl;

    cout<<endl;
}


/// ARCHIVOS

void Delivery::consultaDetalle(){
    int ID;
    cout << "INGRESAR ID DE CONSULTA: ";
    cin >> ID;

    Delivery reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getIdDelivery()==ID){
            reg.Mostrar();
            cin.get();
            return;
        }
        pos++;
    }
}


bool Delivery::escribirEnDisco()
{
    bool escribio;
    FILE *p;
    p=fopen("datos/delivery.dat", "ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this, sizeof(Delivery), 1, p);
    fclose(p);
    return escribio;
}

bool Delivery::leerDeDisco(int pos)
{
    bool leyo;
    FILE *p;
    p=fopen("datos/delivery.dat", "rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Delivery)*pos, 0);
    leyo=fread(this, sizeof(Delivery), 1, p);
    fclose(p);
    return leyo;
}
