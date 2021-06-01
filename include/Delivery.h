#ifndef DELIVERY_H_INCLUDED
#define DELIVERY_H_INCLUDED

class Delivery
{
private:
    int _idDelivery;
    int _idVenta;
    char _domicilio[120];
    char _telefono[20];
    float _montoDelivery;

public:
    /// SETS
    void setIdDelivery(int id);
    void setIdVenta(int id);
    void setDomicilio(char *dom);
    void setTelefono(char *tel);
    void setMontoDelivery(float monto);

    /// GETS
    int getIdDelivery();
    int getIdVenta();
    char *getDomicilio();
    char *getTelefono();
    float getMonto();

    /// CARGAR/MOSTRAR
    void Cargar();
    void Mostrar();

    /// ARCHIVOS
    void consultaDetalle();
    bool escribirEnDisco();
    bool leerDeDisco(int pos);
};

#endif // DELIVERY_H_INCLUDED
