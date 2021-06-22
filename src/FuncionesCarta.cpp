#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
#include "FuncionesCarta.h"
#include "Carta.h"
#include "IngredientesDeCarta.h"

int contarRegistrosDeCarta(){
    int  pos=0, cont=0;
    Carta reg;
    while(reg.leerDeDisco(pos++)==true){
        cont++;
    }
    return cont;
}

bool cargarDatosPlato(){
    Carta reg;
    int cant=0, nroPlato=0;
    cant=contarRegistrosDeCarta();
    if(cant==0){
        nroPlato=1;
        reg.setNroPlato(nroPlato);
    }
    else if(cant!=0){
        nroPlato=cant+1;
        reg.setNroPlato(nroPlato);
    }
    cout << "NRO PLATO: " << reg.getNroPlato() << endl;

    char nombrePlato[50];
    cout << "NOMBRE: ";
    fflush(stdin);
    cin.getline(nombrePlato, 50);
    reg.setNombrePlato(nombrePlato);

    float precioPlato;
    cout << "PRECIO: ";
    cin >> precioPlato;
    reg.setPrecioPlato(precioPlato);

    bool estado=true;
    reg.setEstado(estado);

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }
}

bool registrarPlato(){
    if(cargarDatosPlato()==true){
        return true;
    }
    else{
        return false;
    }
}

bool actualizarPrecio(int nroPlato){
    float precio;
    Carta reg;
    FILE *p;
    p=fopen("datos/carta.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return false;
    }

    while(fread(&reg, sizeof(Carta), 1, p)==1){
        if(reg.getNroPlato()==nroPlato){
            system("cls");
            cout << "REGISTRO A MODIFICAR" << endl;
            cout << "--------------------" << endl;
            reg.Mostrar();
            cout << endl;
            cout << "INGRESAR EL NUEVO PRECIO: ";
            cin >> precio;
            system("cls");

            fseek(p, ftell(p)-sizeof(Carta), 0);
            reg.setPrecioPlato(precio);
            fwrite(&reg, sizeof(Carta), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

bool registrarIngredientesDePlato(){
    Ingredientes reg;
    int nroPlato;
    cout << "INGRESAR NRO PLATO: ";
    cin >> nroPlato;
    reg.setNroPlato(nroPlato);

    int IDmercaderia;
    cout << "INGRESAR ID MERCADERIA: ";
    cin >> IDmercaderia;
    reg.setIDmercaderia(IDmercaderia);

    float cant;
    cout << "INGRESAR CANTIDAD: ";
    cin >> cant;
    reg.setCant(cant);

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }
}

void listarPlatos(){
    Carta reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
    }
}

void listarIngredientesDePlato(int nroPlato){
    Ingredientes reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getNroPlato()==nroPlato){
            reg.mostrar();
        }
    }
}
