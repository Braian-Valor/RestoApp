#ifndef INGRESOMERCADERIAS_H_INCLUDED
#define INGRESOMERCADERIAS_H_INCLUDED

#include "Fecha.h"

class IngresoMercaderias{
    protected:
        Fecha _fechaVencimiento;
        float _cantStock;
        bool _estado;

    public:
        /// SETS
        void setFechaVencimiento(Fecha fechaVencimiento);
        void setCantStock(float cantStock);
        void setEstado(bool estado);

        /// GETS
        Fecha getFechaVencimiento();
        float getCantStock();
        bool getEstado();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

};


#endif // INGRESOMERCADERIAS_H_INCLUDED
