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

bool chequearFechaHora(int nroMesa, int dia, int mes, int hora, int minutos){
    Reserva reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getNroMesa()==nroMesa){
            if(reg.getFecha().getDia()==dia &&
               reg.getFecha().getMes()==mes &&
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

bool buscarMesa(int nroMesa){
    Mesas reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==true){
        if(reg.getNroMesa()==nroMesa){
            return true;
        }
        pos++;
    }
    return false;
}

int contarRegistrosReserva(){
    int  pos=0, cont=0;
    Reserva reg;
    while(reg.leerDeDisco(pos++)==true){
        cont++;
    }
    return cont;
}

bool cargarDatosReserva(){
    Reserva reg;

    int cant=0, nro=0;
    cant=contarRegistrosReserva();
    if(cant==0){
        nro=1;
        reg.setNro(nro);
    }
    else if(cant!=0){
        nro=cant+1;
        reg.setNro(nro);
    }
    cout << "NRO: " << reg.getNro() << endl;

    int nroMesa;
    cout << "NRO MESA: ";
    cin >> nroMesa;
    while(buscarMesa(nroMesa)==false){
        cout << "NRO MESA: ";
        cin >> nroMesa;
    }
    reg.setNroMesa(nroMesa);

    int IDcliente;
    cout << "ID CLIENTE: ";
    cin >> IDcliente;
    while(buscarCliente(IDcliente)==false){
        cout << "ID CLIENTE: ";
        cin >> IDcliente;
    }
    reg.setIDcliente(IDcliente);

    Fecha f;
    int dia, mes;
    cout << "DIA: ";
    cin >> dia;
    while(!(dia>=reg.getFecha().getDia() && dia<32)){
        cout << "DIA: ";
        cin >> dia;
    }
    f.setDia(dia);

    cout << "MES: ";
    cin >> mes;
    while(!(mes>=reg.getFecha().getMes() && mes<13)){
        cout << "MES: ";
        cin >> mes;
    }
    f.setMes(mes);

    cout << "AÑO: ";
    cout << f.getAnio() << endl;

    reg.setFecha(f);

    int hora, minutos;
    cout << "HORA: (11 A 23)";
    cin >> hora;
    while(!(hora>10 && hora<24)){
        cout << "HORA: (11 A 23)";
        cin >> hora;
    }
    reg.setHora(hora);

    cout << "MINUTOS: (0 A 59)";
    cin >> minutos;
    while(!(minutos>=0 && minutos<60)){
        cout << "MINUTOS: ";
        cin >> minutos;
    }
    reg.setMinutos(minutos);

    bool chequeado;
    chequeado=chequearFechaHora(nroMesa, dia, mes, hora, minutos);
    if(chequeado==true){
        cout << "ERROR, LA MESA YA SE ENCUENTRA RESERVADA PARA LA FECHA Y HORA QUE DESEA";
        cin.get();
        return false;
    }

    bool estado=true;
    reg.setEstado(estado);

    if(reg.escribirEnDisco()==true){
        return true;
    }
    else{
        return false;
    }
}

bool registrarReserva(){
    if(cargarDatosReserva()==true){
        return true;
    }
    else{
        return false;
    }
}

void bajaReserva(){
    cout << "RESERVAS TOTALES HASTA EL MOMENTO" << endl;
    cout << "---------------------------------" << endl;
    listarReservas();
    cout << endl;
    FILE *p;
    p=fopen("datos/reservas.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUEDE ABRIR EL ARCHIVO";
        cin.get();
        return;
    }

    int nro;
    cout << "INGRESAR EL NRO DE RESERVA A DAR DE BAJA: ";
    cin >> nro;
    cout << endl;

    Reserva reg;
    while(fread(&reg, sizeof(Reserva), 1, p)==1){
        if(reg.getNro()==nro && reg.getEstado()==true){
            fseek(p, ftell(p)-sizeof(Reserva), 0);
            reg.setEstado(false);
            fwrite(&reg, sizeof(Reserva), 1, p);
            fclose(p);
            cout << "RESERVA DADA DE BAJA";
            cin.get();
            return;
        }

    }
    fclose(p);
    cout << "ERROR, NO EXISTE EL NRO DE RESERVA";
    cin.get();
    return;
}

void modificarReserva(){
    cout << "RESERVAS TOTALES HASTA EL MOMENTO" << endl;
    cout << "---------------------------------" << endl;
    listarReservas();
    cout << endl;

    int nro;
    cout << "INGRESAR EL NRO DE RESERVA A MODIFICAR: ";
    cin >> nro;
    system("cls");

    int opcion;
    bool salir=false;
    Reserva reg;
    FILE *p;
    p=fopen("datos/reservas.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUDO ABRIR EL ARCHIVO";
        return;
    }

    while(fread(&reg, sizeof(Reserva), 1, p)==1){
        if(reg.getNro()==nro && reg.getEstado()!=false){
            while(!salir){
                system("cls");
                cout << "REGISTRO A MODIFICAR" << endl;
                cout << "--------------------" << endl;
                cout << "NRO |" << " NRO MESA |" << " ID CLIENTE |" << "  FECHA    |" << " HORA " << endl;
                reg.mostrar();
                cout << endl;
                cout << " SELECCIONAR CAMPO A MODIFICAR " << endl;
                cout << " ----------------------------- " << endl;
                cout << " 1 - NRO MESA   " << endl;
                cout << " 2 - ID CLIENTE " << endl;
                cout << " 3 - FECHA      " << endl;
                cout << " 4 - HORA       " << endl;
                cout << " 0 - SALIR      " << endl;
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
                        int nroMesa;
                        cout << "NRO MESA: ";
                        cin >> nroMesa;
                        while(buscarMesa(nroMesa)==false){
                            cout << "NRO MESA: ";
                            cin >> nroMesa;
                        }

                        fseek(p, ftell(p)-sizeof(Reserva), 0);
                        reg.setNroMesa(nroMesa);
                        fwrite(&reg, sizeof(Reserva), 1, p);
                    }break;

                    case 2:{
                        int IDcliente;
                        cout << "ID CLIENTE: ";
                        cin >> IDcliente;
                        while(buscarCliente(IDcliente)==false){
                            cout << "ID CLIENTE: ";
                            cin >> IDcliente;
                        }

                        fseek(p, ftell(p)-sizeof(Reserva), 0);
                        reg.setIDcliente(IDcliente);
                        fwrite(&reg, sizeof(Reserva), 1, p);
                    }break;

                    case 3:{
                        Fecha fecha;
                        int dia, mes;
                        cout << "INGRESAR FECHA" << endl;
                        cout << "DIA: ";
                        cin >> dia;
                        while(!(dia>=fecha.getDia() && dia<32)){
                            cout << "DIA: ";
                            cin >> dia;
                        }
                        fecha.setDia(dia);

                        cout << "MES: ";
                        cin >> mes;
                        while(!(mes>=fecha.getMes() && mes<13)){
                            cout << "MES: ";
                            cin >> mes;
                        }
                        fecha.setMes(mes);

                        cout << "AÑO: ";
                        cout << fecha.getAnio() << endl;

                        fseek(p, ftell(p)-sizeof(Reserva), 0);
                        reg.setFecha(fecha);
                        fwrite(&reg, sizeof(Reserva), 1, p);
                    }break;

                    case 4:{
                        int hora, minutos;
                        cout << "INGRESAR HORARIO" << endl;
                        cout << "HORA:  (11 A 23) ";
                        cin >> hora;
                        while(!(hora>10 && hora<24)){
                            cout << "HORA: (11 A 23) ";
                            cin >> hora;
                        }

                        cout << "MINUTOS: (0 A 59) ";
                        cin >> minutos;
                        while(!(minutos>=0 && minutos<60)){
                            cout << "MINUTOS: (0 A 59) ";
                            cin >> minutos;
                        }

                        fseek(p, ftell(p)-sizeof(Reserva), 0);
                        reg.setHora(hora);
                        reg.setMinutos(minutos);
                        fwrite(&reg, sizeof(Reserva), 1, p);
                    }break;
                }
                cin.get();
            }
        }
    }
    fclose(p);
}



void listarReservas(){
    int pos=0;
    Reserva reg;
    cout << "NRO |" << " NRO MESA |" << " ID CLIENTE |" << "  FECHA    |" << " HORA " << endl;
    while(reg.leerDeDisco(pos)==true){
        reg.mostrar();
        pos++;
        cout << endl;
    }
}
