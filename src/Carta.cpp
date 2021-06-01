#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "Carta.h"

/// SETS

void Carta::setIDArticulo(int ID)
{
    _idArticulo=ID;
}

void Carta::setNombre(char *nombre)
{
    strcpy(_nombre, nombre);
}

void Carta::setTipo(char *tipo)
{
    strcpy(_tipo, tipo);
}

void Carta::setPrecio(float precio)
{
    _precio = precio;
}

void Carta::setEstado(bool estado)
{
    _estado = estado;
}


/// GETS

int Carta::getIDArticulo()
{
    return _idArticulo;
}
char *Carta::getNombre()
{
    return _nombre;
}
char *Carta::getTipo()
{
    return _tipo;
}
float Carta::getPrecio()
{
    return _precio;
}
bool Carta::getEstado()
{
    return _estado;
}

/// ABM

void Carta::Cargar()
{
    cout<<"Ingrese ID de plato o bebida:         ";
    cin>>_idArticulo;
    cout<<endl;
    cout<<"Ingrese nombre:         ";
    cin>>_nombre;
    cout<<endl;
    cout<<"Teniendo en cuenta que los tipos son: ENTRADA, PRINCIPAL, POSTRE, BEBIDA"<<endl;
    cout<<"Ingrese tipo:         ";
    cin>>_tipo;
    cout<<endl;
    cout<<"Ingrese precio:         ";
    cin>>_precio;
    cout<<endl;
    _estado = true;

    cout<<_nombre<<" guardado con exito!"<<endl;
    Mostrar();
}

void Carta::Mostrar()
{
    if(_estado)
    {
        cout<<"ID: "<<_idArticulo<<endl;
        cout<<"Nombre: "<<_nombre<<endl;
        cout<<"Tipo: "<<_tipo<<endl;
        cout<<"Precio: "<<_precio<<endl;

    }

    cout<<endl;
}

void Carta::modificarCarta()
{
    int ID;
    cout << "INGRESAR ID DEL ELEMENTO A MODIFICAR: ";
    cin >> ID;
    system("cls");

    int opcion;
    bool salir=false;
    Carta reg;
    FILE *p;
    p=fopen("datos/carta.dat", "rb+");
    if(p==NULL)
    {
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }

    while(fread(&reg, sizeof(Carta), 1, p)==1)
    {
        if(reg.getIDArticulo()==ID)
        {
            while(!salir)
            {
                system("cls");
                cout << "REGISTRO A MODIFICAR" << endl;
                cout << "--------------------" << endl;
                reg.Mostrar();
                cout << endl;
                cout << " SELECCIONAR CAMPO A MODIFICAR " << endl;
                cout << " ----------------------------- " << endl;
                cout << " 1 - NOMBRE " << endl;
                cout << " 2 - TIPO   " << endl;
                cout << " 3 - PRECIO     " << endl;
                cout << " 0 - SALIR    " << endl;
                cout << endl;
                cout << "OPCION: ";
                cin >> opcion;
                system("cls");

                switch(opcion)
                {
                default:
                {
                    cout << "OPCION INCORRECTA";
                }
                break;

                case 0:
                {
                    fclose(p);
                    salir=true;
                }
                break;

                case 1:
                {
                    char nombre[50];
                    cout << "INGRESAR NOMBRE: ";
                    fflush(stdin);
                    cin.getline(nombre, 50);

                    fseek(p, ftell(p)-sizeof(Carta), 0);
                    reg.setNombre(nombre);
                    fwrite(&reg, sizeof(Carta), 1, p);
                }
                break;

                case 2:
                {
                    char tipo[50];
                    cout << "INGRESAR TIPO: ";
                    fflush(stdin);
                    cin.getline(tipo, 50);

                    fseek(p, ftell(p)-sizeof(Carta), 0);
                    reg.setTipo(tipo);
                    fwrite(&reg, sizeof(Carta), 1, p);
                }
                break;

                case 3:
                {
                    float precio;
                    cout << "INGRESAR PRECIO: ";
                    cin >> precio;

                    fseek(p, ftell(p)-sizeof(Carta), 0);
                    reg.setPrecio(precio);
                    fwrite(&reg, sizeof(Carta), 1, p);
                }
                break;
                }
                cin.get();
            }
        }
    }
    fclose(p);

}

void Carta::eliminarElemento(){
    Carta reg;
    FILE *p;
    p=fopen("datos/carta.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        cin.get();
        return;
    }

    int ID;
    cout << "INGRESAR ID DEL ELEMENTO A ELIMINAR: ";
    cin >> ID;

    while(fread(&reg, sizeof(Carta), 1, p)==1){
        if(reg.getIDArticulo()==ID){
            fseek(p, ftell(p)-sizeof(Carta), 0);
            reg.setEstado(false);
            bool escribio=fwrite(&reg, sizeof(Carta), 1, p);
            fclose(p);
            if(escribio==true){
                cout << "ELEMENTO ELIMINADO";
                cin.get();
                return;
            }
        }

    }
    fclose(p);
}

void Carta::consultaCarta(){
    int ID;
    cout << "INGRESAR ID DE CONSULTA: ";
    cin >> ID;

    Carta reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getIDArticulo()==ID){
            reg.Mostrar();
            cin.get();
            return;
        }
        pos++;
    }
}

/// ARCHIVOS

bool Carta::escribirEnDisco()
{
    bool escribio;
    FILE *p;
    p=fopen("datos/carta.dat", "ab");
    if(p==NULL)
    {
        return false;
    }
    escribio=fwrite(this, sizeof(Carta), 1, p);
    fclose(p);
    return escribio;
}

bool Carta::leerDeDisco(int pos)
{
    bool leyo;
    FILE *p;
    p=fopen("datos/carta.dat", "rb");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, sizeof(Carta)*pos, 0);
    leyo=fread(this, sizeof(Carta), 1, p);
    fclose(p);
    return leyo;
}
