#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED

#include "Fecha.h"


class DetalleVenta
{
private:
    int _idVenta;
    int _idArticulo;
    float _montoUnitario;
    int _cantidad;

public:
    /// SETS
    void setIdVenta(int id);
    void setIdArticulo(int id);
    void setMontoUnitario(float monto);
    void setCantidad(int cant);
    void setEnvio(bool envio);

    /// GETS
    int getIdVenta();
    int getIdArticulo();
    float getMontoUnitario();
    int getCantidad();
    bool getEnvio();

    /// ABM
    void Cargar();
    void Mostrar();
    void consultaDetalle();


    /// ARCHIVOS
    bool escribirEnDisco();
    bool leerDeDisco(int pos);

};

#endif // DETALLEVENTA_H_INCLUDED
