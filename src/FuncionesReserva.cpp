#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "Reserva.h"
#include "FuncionesReserva.h"
#include "Mesas.h"
#include "Cliente.h"

bool chequearFechaHora(int nroMesa, int dia, int mes, int anio, int hora, int minutos){
    Reserva reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getNroMesa()==nroMesa){
            if(reg.getFecha().getDia()==dia &&
               reg.getFecha().getMes()==mes &&
               reg.getFecha().getAnio()==anio &&
               reg.getHora()==hora &&
               reg.getMinutos()==minutos){

               return true;
            }
        }
        pos++;
    }
    return false;
}


bool buscarCliente(int IDcliente){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getID()==IDcliente){
            return true;
        }
        pos++;
    }
    return false;
}

void mesaReservada(int nroMesa){
    Mesas reg;
    FILE *p;
    p=fopen("datos/mesas.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUEDE ABRIR EL ARCHIVO";
        cin.get();
        return;
    }

    while(fread(&reg, sizeof(Mesas), 1, p)==1){
        if(reg.getNroMesa()==nroMesa){
            fseek(p, ftell(p)-sizeof(Mesas), 0);
            reg.setEstado(false);
            fwrite(&reg, sizeof(Mesas), 1, p);
            fclose(p);
        }
    }
    fclose(p);
}

bool buscarMesa(int nroMesa){
    Mesas reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getNroMesa()==nroMesa /*&& reg.getEstado()==true*/){
            return true;
        }
        pos++;
    }
    return false;
}

bool cargarDatosReserva(){
    Reserva reg;

    bool encontroMesa;
    int nroMesa;
    cout << "NRO MESA: ";
    cin >> nroMesa;
    encontroMesa=buscarMesa(nroMesa);
    if(encontroMesa==true){
        reg.setNroMesa(nroMesa);
    }
    else{
        return false;
    }

    bool encontroCliente;
    int IDcliente;
    cout << "ID CLIENTE: ";
    cin >> IDcliente;
    encontroCliente=buscarCliente(IDcliente);
    if(encontroCliente==true){
        reg.setIDcliente(IDcliente);
    }
    else{
        return false;
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
    while(!(anio==reg.getFecha().getAnio())){
        cout << "AÑO: ";
        cin >> anio;
    }
    f.setAnio(anio);

    int hora, minutos;
    cout << "HORA: (11:00 A 23:30)";
    cin >> hora;
    while(!(hora>10 && hora<24)){
        cout << "HORA: (11:00 A 23:30)";
        cin >> hora;
    }
    reg.setHora(hora);

    cout << "MINUTOS: ";
    cin >> minutos;
    while(!(minutos>0 && minutos<61)){
        cout << "MINUTOS: ";
        cin >> minutos;
    }
    reg.setMinutos(minutos);

    bool chequeado;
    chequeado=chequearFechaHora(nroMesa, dia, mes, anio, hora, minutos);
    if(chequeado==true){
        cout << "ERROR, LA MESA YA SE ENCUENTRA RESERVADA PARA LA FECHA Y HORA QUE DESEA";
        cin.get();
        return false;
    }

    bool estado=true;
    reg.setEstado(estado);

    mesaReservada(nroMesa);

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }
}

void registrarReserva(){
    bool registro;
    registro=cargarDatosReserva();
    if(registro==true){
        cout << "RESERVA REGISTRADA CON EXITO";
        cin.get();
        return;
    }
    else{
        cout << "ERROR, NO SE PUDO REGISTRAR LA RESERVA";
        cin.get();
        return;
    }
}


void listarReservas(){
    int pos=0;
    Reserva reg;
    while(reg.leerDeDisco(pos)==true){
        reg.mostrar();
        pos++;
        cout << endl;
    }
}
