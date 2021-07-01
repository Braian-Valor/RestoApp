#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <locale.h>
using namespace std;
#include "FuncionesVentas.h"
#include "Ventas.h"
#include "Mercaderias.h"
#include "Fecha.h"
#include "Carta.h"

void RecaudacionAnual();
void RecaudacionMensual();
void RecaudacionDiaria();
void RecaudacionPorPlato();
int buscadoranio(int);
int buscadormes(int,int);
int SumatoriadiaFinal(int);
int buscarplato(int);



#endif // REPORTES_H_INCLUDED
