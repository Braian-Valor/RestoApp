#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesReserva.h"
#include "FuncionesCarta.h"
#include "Carta.h"
#include "Fecha.h"
#include "Ventas.h"
#include "Mercaderias.h"
#include "IngredientesDeCarta.h"

void descontarMercaderias(int IDmercaderia, float cant){
    Mercaderias reg;
    float cantRestante;
    FILE *p;
    p=fopen("datos/mercaderias.dat", "rb+");
    if(p==NULL){
        cout << "ERROR, NO SE PUEDE ABRIR EL ARCHIVO DE MERCADERIAS" << endl;
        cin.get();
        return;
    }

    while(fread(&reg, sizeof(Mercaderias), 1, p)==1){
        if(reg.getID()==IDmercaderia && reg.getCantStock()>0){
            cantRestante=reg.getCantStock()-cant;
            fseek(p, ftell(p)-sizeof(Mercaderias), 0);
            reg.setCantStock(cantRestante);
            fwrite(&reg, sizeof(Mercaderias), 1, p);
            fclose(p);
            return;
        }
        else if(reg.getCantStock()<0){
            reg.setCantStock(0);
            fseek(p, ftell(p)-sizeof(Mercaderias), 0);
            fwrite(&reg, sizeof(Mercaderias), 1, p);
            fclose(p);
            return;
        }
    }
    fclose(p);
    return;
}


void buscarNroPlato(int nroPlato, int cantidad){
    Ingredientes reg;
    int pos=0;
    for(int i=0; i<cantidad; i++){
        while(reg.leerDeDisco(pos++)==true){
            if(reg.getNroPlato()==nroPlato){
                descontarMercaderias(reg.getIDmercaderia(), reg.getCant());
            }
        }
    }
    return;
}

int cantidadComprasDeCliente(int IDcliente){
    Ventas reg;
    int pos=0, cont=0;
    while(reg.leerDeDisco(pos++)==true){
        if(reg.getIDcliente()==IDcliente){
            cont++;
        }
    }
    return cont;
}



void registrarVenta(){
    Carta regCarta;
    int pos=0;
    float descuento=0;

    Ventas regVenta;
    float montoTotal=0;

    //chequearMercaderia();

    int IDcliente;
    cout << "INGRESAR ID CLIENTE: ";
    cin >> IDcliente;
    cout << endl;

    if(buscarCliente(IDcliente)==true){
        listarPlatos();
        cout << endl;
        cin.get();

        regVenta.setIDcliente(IDcliente);

        int nroPlato, cantidad;
        cout << "ELEGIR NRO PLATO: ";
        cin >> nroPlato;
        while(nroPlato<0 && buscarPlato(nroPlato)==false){
            cout << "ELEGIR NRO PLATO: ";
            cin >> nroPlato;
        }
        regVenta.setIDplato(nroPlato);

        cout << "CANTIDAD: ";
        cin >> cantidad;
        while(cantidad<=0){
            cout << "CANTIDAD: ";
            cin >> cantidad;
        }
        regVenta.setCantidad(cantidad);

        Fecha f;
        cout << "FECHA: ";
        f.Mostrar();
        regVenta.setFechaVenta(f);


        cout << endl;
        cout << "METODO DE PAGO: EFECTIVO" << endl;
        regVenta.setMetodoPago(1);
        cin.ignore();

        int cant;
        cant=cantidadComprasDeCliente(IDcliente);
        if(cant<3){
            regVenta.setDescuento(0);
            while(regCarta.leerDeDisco(pos++)==true){
                if(regCarta.getNroPlato()==nroPlato){
                    montoTotal=regCarta.getPrecioPlato()*cantidad;
                    regVenta.setMontoTotal(montoTotal);
                }
            }

            buscarNroPlato(nroPlato, cantidad);

            cout << endl;
            if(regVenta.escribirEnDisco()==true){
                regVenta.Mostrar();
                cin.get();
            }
        }

        if(cant>=3){
            //5%
            regVenta.setDescuento(5);
            while(regCarta.leerDeDisco(pos++)==true){
                if(regCarta.getNroPlato()==nroPlato){
                    descuento=regCarta.getPrecioPlato()*5/100;
                    montoTotal=regCarta.getPrecioPlato()*cantidad-descuento;
                    regVenta.setMontoTotal(montoTotal);
                }
            }

            buscarNroPlato(nroPlato, cantidad);

            cout << endl;
            if(regVenta.escribirEnDisco()==true){
                regVenta.Mostrar();
                cin.get();
            }
        }

        if(cant>=5){
            //10%
            regVenta.setDescuento(10);
            while(regCarta.leerDeDisco(pos++)==true){
                if(regCarta.getNroPlato()==nroPlato){
                    descuento=regCarta.getPrecioPlato()*10/100;
                    montoTotal=regCarta.getPrecioPlato()*cantidad-descuento;
                    regVenta.setMontoTotal(montoTotal);
                }
            }

            buscarNroPlato(nroPlato, cantidad);

            cout << endl;
            if(regVenta.escribirEnDisco()==true){
                regVenta.Mostrar();
                cin.get();
            }
        }

        if(cant>=10){
            //20%
            regVenta.setDescuento(20);
            while(regCarta.leerDeDisco(pos++)==true){
                if(regCarta.getNroPlato()==nroPlato){
                    descuento=regCarta.getPrecioPlato()*20/100;
                    montoTotal=regCarta.getPrecioPlato()*cantidad-descuento;
                    regVenta.setMontoTotal(montoTotal);
                }
            }

            buscarNroPlato(nroPlato, cantidad);

            cout << endl;
            if(regVenta.escribirEnDisco()==true){
                regVenta.Mostrar();
                cin.get();
            }
        }

    }
    else{
        cout << "EL CLIENTE BUSCADO NO EXISTE" << endl;
        cin.get();
    }
}

void listarVentas(){
    Ventas reg;
    int pos=0;
    while(reg.leerDeDisco(pos++)==true){
        reg.Mostrar();
        cout << endl;
    }
}
