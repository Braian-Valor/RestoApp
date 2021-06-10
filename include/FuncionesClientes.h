#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

/// PROTOTIPOS DE FUNCIONES PARA EL MENU CLIENTES
int contarRegistros();
bool buscarDNI();
bool cargarDatos();
bool registrarCliente();

void modificarCliente(int ID);

void eliminarCliente(int ID);

void consultaCliente(int ID);

void listarClientes();


#endif // FUNCIONESCLIENTES_H_INCLUDED
