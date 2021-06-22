#ifndef FUNCIONESCARTA_H_INCLUDED
#define FUNCIONESCARTA_H_INCLUDED

/// PROTOTIPOS FUNCIONES CARTA
int contarRegistrosDeCarta();
bool cargarDatosPlato();
bool registrarPlato();

bool actualizarPrecio(int nroPlato);
bool registrarIngredientesDePlato();
void listarPlatos();

void listarIngredientesDePlato(int nroPlato);

#endif // FUNCIONESCARTA_H_INCLUDED
