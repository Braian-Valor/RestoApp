#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include "Fecha.h"

class Reserva{
    private:
        int _nro;
        int _nroMesa;
        int _IDcliente;
        Fecha _fecha;
        int _hora, _minutos;
        bool _estado;

    public:
        /// SETS
        void setNro(int nro);
        void setNroMesa(int nroMesa);
        void setIDcliente(int IDcliente);
        void setFecha(Fecha fecha);
        void setHora(int hora);
        void setMinutos(int minutos);
        void setEstado(bool estado);

        /// GETS
        int getNro();
        int getNroMesa();
        int getIDcliente();
        Fecha getFecha();
        int getHora();
        int getMinutos();
        bool getEstado();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);

        /// CARGAR Y MOSTRAR
        void cargar();
        void mostrar();
};


#endif // RESERVA_H_INCLUDED
