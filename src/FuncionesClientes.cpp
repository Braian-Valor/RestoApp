#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesClientes.h"
#include "Fecha.h"
#include "Cliente.h"

int contarRegistros(){
    int  pos=0, cont=0;
    Cliente reg;
    while(reg.leerDeDisco(pos++)==true){
        cont++;
    }
    return cont;
}

bool buscarDNI(int DNI){
    int  pos=0;
    Cliente reg;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getDNI()==DNI){
            return true;
        }
        pos++;
    }
    return false;
}

bool cargarDatos(){
    Cliente reg;
    int cant=0, ID=0;
    cant=contarRegistros();
    if(cant==0){
        ID=1;
        reg.setID(ID);
    }
    else if(cant!=0){
        ID=cant+1;
        reg.setID(ID);
    }
    cout << "ID: " << reg.getID() << endl;

    char apellido[50];
    cout << "APELLIDO: ";
    fflush(stdin);
    cin.getline(apellido, 50);
    reg.setApellido(apellido);

    char nombre[50];
    cout << "NOMBRE: ";
    fflush(stdin);
    cin.getline(nombre, 50);
    reg.setNombre(nombre);

    int edad;
    cout << "EDAD: ";
    cin >> edad;
    reg.setEdad(edad);

    bool encontro;
    int DNI;
    cout << "DNI: ";
    cin >> DNI;
    encontro=buscarDNI(DNI);
    if(encontro==true){
        cout << "ERROR, DNI EXISTENTE" << endl;
        return false;
    }
    else if(encontro==false){
        reg.setDNI(DNI);
    }

    Fecha f;
    int dia, mes, anio;
    cout << "DIA: ";
    cin >> dia;
    while(!(dia>0 && dia<32)){
        cout << "DIA: ";
        cin >> dia;
    }
    f.setDia(dia);

    cout << "MES: ";
    cin >> mes;
    while(!(mes>0 && mes<13)){
        cout << "MES: ";
        cin >> mes;
    }
    f.setMes(mes);

    cout << "AÑO: ";
    cin >> anio;
    while(!(anio>2000) && !(anio<=reg.getFecha().getAnio())){
        cout << "AÑO: ";
        cin >> anio;
    }
    f.setAnio(anio);

    bool estado=true;
    reg.setEstado(estado);
    cout << endl;

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }
}

void registrarCliente(){
    bool datosCargados;
    datosCargados=cargarDatos();
    if(datosCargados==true){
        cout << "CLIENTE REGISTRADO CORRECTAMENTE" << endl;
        cin.get();
        return;
    }
    else{
        cout << "ERROR, NO SE PUDO REGISTRAR EL CLIENTE" << endl;
        cin.get();
        return;
    }
}


void modificarCliente(){
    int ID;
    cout << "INGRESAR ID DEL CLIENTE A MODIFICAR: ";
    cin >> ID;
    system("cls");

    int opcion;
    bool salir=false;
    Cliente reg;
    FILE *p;
    p=fopen("datos/clientes.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }

    while(fread(&reg, sizeof(Cliente), 1, p)==1){
        if(reg.getID()==ID){
            while(!salir){
                system("cls");
                cout << "REGISTRO A MODIFICAR" << endl;
                cout << "--------------------" << endl;
                reg.Mostrar();
                cout << endl;
                cout << " SELECCIONAR CAMPO A MODIFICAR " << endl;
                cout << " ----------------------------- " << endl;
                cout << " 1 - APELLIDO " << endl;
                cout << " 2 - NOMBRE   " << endl;
                cout << " 3 - EDAD     " << endl;
                cout << " 4 - FECHA    " << endl;
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
                        char apellido[50];
                        cout << "INGRESAR APELLIDO: ";
                        fflush(stdin);
                        cin.getline(apellido, 50);

                        fseek(p, ftell(p)-sizeof(Cliente), 0);
                        reg.setApellido(apellido);
                        fwrite(&reg, sizeof(Cliente), 1, p);
                    }break;

                    case 2:{
                        char nombre[50];
                        cout << "INGRESAR NOMBRE: ";
                        fflush(stdin);
                        cin.getline(nombre, 50);

                        fseek(p, ftell(p)-sizeof(Cliente), 0);
                        reg.setNombre(nombre);
                        fwrite(&reg, sizeof(Cliente), 1, p);
                    }break;

                    case 3:{
                        int edad;
                        cout << "INGRESAR EDAD: ";
                        cin >> edad;

                        fseek(p, ftell(p)-sizeof(Cliente), 0);
                        reg.setEdad(edad);
                        fwrite(&reg, sizeof(Cliente), 1, p);
                    }break;

                    case 4:{
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

                        fseek(p, ftell(p)-sizeof(Cliente), 0);
                        reg.setFecha(fecha);
                        fwrite(&reg, sizeof(Cliente), 1, p);
                    }break;
                }
                cin.get();
            }
        }
    }
    fclose(p);
}


void eliminarCliente(){
    Cliente reg;
    FILE *p;
    p=fopen("datos/clientes.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        cin.get();
        return;
    }

    int ID;
    cout << "INGRESAR ID DE CLIENTE A ELIMINAR: ";
    cin >> ID;

    while(fread(&reg, sizeof(Cliente), 1, p)==1){
        if(reg.getID()==ID){
            fseek(p, ftell(p)-sizeof(Cliente), 0);
            reg.setEstado(false);
            bool escribio=fwrite(&reg, sizeof(Cliente), 1, p);
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


void consultaCliente(){
    int ID;
    cout << "INGRESAR ID DE CONSULTA: ";
    cin >> ID;

    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getID()==ID){
            reg.Mostrar();
            cin.get();
            return;
        }
        pos++;
    }
}


void listarClientes(){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        reg.Mostrar();
        pos++;
        cout << endl;
    }
}
