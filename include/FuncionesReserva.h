#ifndef FUNCIONESRESERVA_H_INCLUDED
#define FUNCIONESRESERVA_H_INCLUDED

/// PROTOTIPOS DE FUNCIONES PARA EL MENU RESERVAS
bool chequearFechaHora(int nroMesa, int dia, int mes, int anio, int hora, int minutos);
int contarRegistrosReserva();

bool buscarCliente(int IDcliente);
void mesaReservada(int nroMesa);
bool buscarMesa(int nroMesa);
bool cargarDatosReserva();
bool registrarReserva();

void bajaReserva();

void modificarReserva();

void listarReservas();
#endif // FUNCIONESRESERVA_H_INCLUDED
