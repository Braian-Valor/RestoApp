#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "Fecha.h"
#include "DetalleVenta.h"

class Ventas
{
private:
    int _idVenta;
    Fecha _fecha;
    int _metodoPago;
    int _idCliente;
    int _contDescuentos;
    float _montoTotal;
    bool _envio;

    public:
        /// SETS
        void setIdVenta(int ID);
        void setFecha(Fecha fecha);
        void setMetodoPago(int met);
        void setIdCliente(int id);
        void setContDescuentos(int cont);
        void setMonto(float monto);
        void setEnvio(bool envio);

        /// GETS
        int getIdVenta();
        Fecha getFecha();
        int getMetodoPago();
        int getIdCliente();
        int getContDescuentos();
        float getTotalVenta();
        bool getEnvio();

        /// CARGAR/MOSTRAR
        void Cargar();
        void Mostrar();


        /// ARCHIVOS
        void consultaVenta();
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // VENTAS_H_INCLUDED
