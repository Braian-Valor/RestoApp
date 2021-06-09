#ifndef MERCADERIAS_H_INCLUDED
#define MERCADERIAS_H_INCLUDED

#include "IngresoMercaderias.h"

class Mercaderias:public IngresoMercaderias{
    protected:
        char _tipoAlimento[50];
        char _nombre[50];

    public:
        /// SETS
        void setTipoAlimento(char *tipoAlimento);
        void setNombre(char *nombre);

        /// GETS
        char *getTipoAlimento();
        char *getNombre();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};


#endif // MERCADERIAS_H_INCLUDED
