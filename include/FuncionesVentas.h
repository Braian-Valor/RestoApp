#ifndef FUNCIONESVENTAS_H_INCLUDED
#define FUNCIONESVENTAS_H_INCLUDED

/// PROTOTIPOS
void descontarMercaderias(int IDmercaderia, float cant);
void buscarNroPlato(int nroPlato, int cantidad);
int cantidadComprasDeCliente(int IDcliente);
void registrarVenta();

void bajaDePlato(int nroPlato);
void chequearIngredientesParaBaja(int IDmercaderia);
void chequearMercaderia();


void listarVentas();

#endif // FUNCIONESVENTAS_H_INCLUDED
