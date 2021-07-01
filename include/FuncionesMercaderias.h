#ifndef FUNCIONESMERCADERIAS_H_INCLUDED
#define FUNCIONESMERCADERIAS_H_INCLUDED

/// PROTOTIPOS DE FUNCIONES PARA EL MENU DE MERCADERIAS
int contarRegistrosDeMercaderias();
bool cargarDatosMercaderia();
bool registrarMercaderia();

void modificarMercaderia(char *nombre);
void eliminarMercaderia(char *nombre);

void listarMercaderias();

bool altaCarta(int NroPlato);
bool altaPlato(int IDmercaderia);
void mercaderiaReponer();

#endif // FUNCIONESMERCADERIAS_H_INCLUDED
