#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesMercaderias.h"
#include "Mercaderias.h"

int contarRegistrosDeMercaderias(){
    int  pos=0, cont=0;
    Mercaderias reg;
    while(reg.leerDeDisco(pos++)==true){
        cont++;
    }
    return cont;
}

bool cargarDatosMercaderia(){
    Mercaderias reg;
    int cant=0, ID=0;
    cant=contarRegistrosDeMercaderias();
    if(cant==0){
        ID=1;
        reg.setID(ID);
    }
    else if(cant!=0){
        ID=cant+1;
        reg.setID(ID);
    }
    cout << "ID: " << reg.getID() << endl;

    char nombre[50];
    cout << "NOMBRE: ";
    fflush(stdin);
    cin.getline(nombre,50);
    reg.setNombre(nombre);

    Fecha fecha;
    int dia, mes, anio;
    cout << "FECHA DE VENCIMIENTO" << endl;
    cout << "DIA: ";
    cin >> dia;
    fecha.setDia(dia);
    cout << "MES: ";
    cin >> mes;
    fecha.setMes(mes);
    cout << "AÑO: ";
    cin >> anio;
    fecha.setAnio(anio);
    reg.setFechaVencimiento(fecha);

    float cantStock;
    cout << "CANTIDAD EN STOCK: ";
    cin >> cantStock;
    reg.setCantStock(cantStock);

    bool estado=true;
    reg.setEstado(estado);

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }

}

bool registrarMercaderia(){
    if(cargarDatosMercaderia()==true){
        return true;
    }
    else{
        return false;
    }
}

void modificarMercaderia(char *nombre){
    int opcion;
    bool salir=false;
    Mercaderias reg;
    FILE *p;
    p=fopen("datos/mercaderias.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }

    while(fread(&reg, sizeof(Mercaderias), 1, p)==1){
        if(strcmp(reg.getNombre(), nombre)==0){
            while(!salir){
                system("cls");
                cout << "REGISTRO A MODIFICAR" << endl;
                cout << "--------------------" << endl;
                reg.Mostrar();
                cout << endl;
                cout << " SELECCIONAR CAMPO A MODIFICAR " << endl;
                cout << " ----------------------------- " << endl;
                cout << " 1 - FECHA      " << endl;
                cout << " 2 - CANT STOCK " << endl;
                cout << " 0 - SALIR    " << endl;
                cout << endl;
                cout << "OPCION: ";
                cin >> opcion;
                system("cls");

                switch(opcion){
                    default:{
                        cout << "OPCION INCORRECTA";
                    }break;

                    case 0:{
                        fclose(p);
                        salir=true;
                    }break;

                    case 1:{
                        Fecha fecha;
                        int dia, mes, anio;
                        cout << "INGRESAR FECHA" << endl;
                        cout << "DIA: ";
                        cin >> dia;
                        fecha.setDia(dia);

                        cout << "MES: ";
                        cin >> mes;
                        fecha.setMes(mes);

                        cout << "AÑO: ";
                        cin >> anio;
                        fecha.setAnio(anio);

                        fseek(p, ftell(p)-sizeof(Mercaderias), 0);
                        reg.setFechaVencimiento(fecha);
                        fwrite(&reg, sizeof(Mercaderias), 1, p);
                    }break;

                    case 2:{
                        float cantStock;
                        cout << "INGRESAR CANT STOCK: ";
                        cin >> cantStock;

                        reg.setCantStock(cantStock);
                        fseek(p, ftell(p)-sizeof(Mercaderias), 0);
                        fwrite(&reg, sizeof(Mercaderias), 1, p);
                    }break;
                }
                cin.get();
            }
        }
    }
    fclose(p);
}


void eliminarMercaderia(char *nombre){
    Mercaderias reg;
    FILE *p;
    p=fopen("datos/mercaderias.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        cin.get();
        return;
    }

    while(fread(&reg, sizeof(Mercaderias), 1, p)==1){
        if(strcmp(reg.getNombre(), nombre)==0){
            fseek(p, ftell(p)-sizeof(Mercaderias), 0);
            reg.setEstado(false);
            bool escribio=fwrite(&reg, sizeof(Mercaderias), 1, p);
            fclose(p);
            if(escribio==true){
                cout << "CLIENTE ELIMINADO";
                cin.get();
                return;
            }
        }

    }
    fclose(p);
}

void listarMercaderias(){
    Mercaderias reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout << endl;
    }
}

