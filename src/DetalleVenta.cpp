#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "DetalleVenta.h"
#include "Carta.h"


/// SETS

void DetalleVenta::setIdVenta(int id)
{
    _idVenta=id;
}

void DetalleVenta::setMontoUnitario(float monto)
{
    _montoUnitario = monto;
}

void DetalleVenta::setCantidad(int cant)
{
    _cantidad = cant;
}

void DetalleVenta::setIdArticulo(int idArt)
{
    _idArticulo = idArt;
}

/// GETS

int DetalleVenta::getIdVenta()
{
    return _idVenta;
}

int DetalleVenta::getIdArticulo()
{
    return _idArticulo;
}

float DetalleVenta::getMontoUnitario()
{
    return _montoUnitario;
}

int DetalleVenta::getCantidad()
{
    return _cantidad;
}



/// CARGAR/MOSTRAR


void DetalleVenta::Cargar()

{
    cout<<"Ingrese ID venta:         ";
    cin>>_idVenta;
    cout<<endl;
    cout<<"Ingrese ID articulo:         ";
    cin>>_idArticulo;
    cout<<endl;
    cout<<"Ingrese cantidad:         ";
    cin>>_cantidad;
    cout<<endl;
    cout<<"Ingrese monto del articulo:         ";
    cin>>_montoUnitario;
    cout<<endl;

    cout<<"Venta registrada con exito!"<<endl;
    Mostrar();
}

void DetalleVenta::Mostrar()
{


    cout<<"ID Venta: "<<_idVenta<<endl;
    cout<<"ID Articulo: "<<_idArticulo<<endl;
    cout<<"Cantidad: "<<_cantidad<<endl;
    cout<<"Monto unitario: "<<_montoUnitario<<endl;

    cout<<endl;
}


/// ARCHIVOS


void DetalleVenta::consultaDetalle(){
    int ID;
    cout << "INGRESAR ID DE CONSULTA: ";
    cin >> ID;

    DetalleVenta reg;
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


bool DetalleVenta::escribirEnDisco()
{
    bool escribio;
    FILE *p;
    p=fopen("datos/detalleVenta.dat", "ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return escribio;
}

bool DetalleVenta::leerDeDisco(int pos)
{
    bool leyo;
    FILE *p;
    p=fopen("datos/detalleVenta.dat", "rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(DetalleVenta)*pos, 0);
    leyo=fread(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return leyo;
}
