#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#include "Ventas.h"



/// SETS

void Ventas::setIdVenta(int id)
{
    _idVenta = id;
}

void Ventas::setFecha(Fecha fecha)
{
    _fecha  = fecha;
}

void Ventas::setMetodoPago(int met)
{
    _metodoPago = met;
}

void Ventas::setIdCliente(int id)
{
    _idCliente = id;
}

void Ventas::setContDescuentos(int cont)
{
    _contDescuentos = cont;
}

void Ventas::setMonto(float monto)
{
    _montoTotal = monto;
}

void Ventas::setEnvio(bool envio)
{
    _envio = envio;
}


/// GETS

int Ventas::getIdVenta()
{
    return _idVenta;
}

Fecha Ventas::getFecha()
{
    return _fecha;
}

int Ventas::getMetodoPago()
{
    return _metodoPago;
}

int Ventas::getIdCliente()
{
    return _idCliente;
}

int Ventas::getContDescuentos()
{
    return _contDescuentos;
}

float Ventas::getTotalVenta()
{
    return _montoTotal;
}

bool Ventas::getEnvio()
{
    return _envio;
}

/// CARGAR/MOSTRAR

void Ventas::Cargar()

{
    cout<<"Ingrese ID venta:         ";
    cin>>_idVenta;
    cout<<endl;
    cout<<"Ingrese fecha Venta:         ";
    _fecha.Cargar();
    cout<<endl;
    cout<<"Ingrese metodo de pago:         ";
    cin>>_metodoPago;
    cout<<endl;
    cout<<"Ingrese id de Cliente:         ";
    cin>>_idCliente;
    cout<<endl;
    cout<<"Ingrese contador de Descuentos:         ";
    cin>>_contDescuentos;
    cout<<endl;
    cout<<"Ingrese total de la Venta:         ";
    cin>>_montoTotal;
    cout<<endl;
    cout<<"Es con envío?: "<<endl;
    cout<<"1-SI"<<endl<<"2-NO"<<endl;
    cin>>_envio;
    cout<<endl;

    cout<<"Venta registrada con exito!"<<endl;
    Mostrar();
}

void Ventas::Mostrar()
{

    cout<<"ID Venta: "<<_idVenta<<endl;
    cout<<"Fecha Venta: ";
    _fecha.Mostrar();
    cout<<endl;
    cout<<"Metodo de Pago: "<<_metodoPago<<endl;
    cout<<"Id de Cliente: "<<_idCliente<<endl;
    cout<<"Contador de descuentos: "<<_contDescuentos<<endl;
    cout<<"Monto total: "<<_montoTotal<<endl;
    if(_envio)
    {
        cout<<"Envio?: Si"<<endl;
    }
    else
    {
        cout<<"Envio?: No"<<endl;
    }
    cout<<endl;
}

/// ARCHIVOS

void Ventas::consultaVenta()
{

    int ID;
    cout << "INGRESAR ID DE CONSULTA: ";
    cin >> ID;

    Ventas reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getIdVenta()==ID){
            reg.Mostrar();
            cin.get();
            return;
        }
        pos++;
    }
}


bool Ventas::escribirEnDisco()
{
    bool escribio;
    FILE *p;
    p=fopen("datos/ventas.dat", "ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this, sizeof(Ventas), 1, p);
    fclose(p);
    return escribio;
}

bool Ventas::leerDeDisco(int pos)
{
    bool leyo;
    FILE *p;
    p=fopen("datos/ventas.dat", "rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Ventas)*pos, 0);
    leyo=fread(this, sizeof(Ventas), 1, p);
    fclose(p);
    return leyo;
}
