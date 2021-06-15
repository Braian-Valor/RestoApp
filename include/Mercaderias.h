#ifndef MERCADERIAS_H_INCLUDED
#define MERCADERIAS_H_INCLUDED

#include "Fecha.h"

class Mercaderias {
    private:
        char _nombre[50];
        Fecha _fechaVencimiento;
        float _cantStock;
        bool _estado;
    public:
        /// SETS
        void setNombre(char *nombre);
        void setFechaVencimiento(Fecha fechaVencimiento);
        void setCantStock(float cantStock);
        void setEstado(bool estado);

        /// GETS
        char *getNombre();
        Fecha getFechaVencimiento();
        float getCantStock();
        bool getEstado();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};


#endif // MERCADERIAS_H_INCLUDED
