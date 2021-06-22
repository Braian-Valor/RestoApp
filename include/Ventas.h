#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"

class Ventas{
    private:
        int _IDcliente;
        int _IDplato;
        Fecha _fecha;
        int _cantidad;
        int _metodoDePago;
        float _descuento;
        float _montoTotal;

    public:
        /// SETS
        void setIDcliente(int IDcliente);
        void setIDplato(int IDplato);
        void setFechaVenta(Fecha fecha);
        void setCantidad(int cantidad);
        void setMetodoPago(int metodoDePago);
        void setDescuento(float descuento);
        void setMontoTotal(float montoTotal);

        /// GETS
        int getIDcliente();
        int getIDplato();
        Fecha getFechaVenta();
        int getCantidad();
        int getMetodoPago();
        float getDescuento();
        float getMontoTotal();

        /// MOSTRAR
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // VENTAS_H_INCLUDED
