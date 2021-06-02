#ifndef MESAS_H_INCLUDED
#define MESAS_H_INCLUDED
#include "Cliente.h"
#include "Fecha.h"

class Mesas: public Cliente
{
    private:
        int NroMesa;
        int Capacidad;
        Fecha Dia_Horario;
        bool Estado;

    public:
        /// SETS
        void setNroMesa(int);
        void setCapacidad(int);
        void setEstado(bool);
        void setFecha(Fecha);

        /// GETS
        int getNroMesa();
        int getCapacidad();
        bool getEstado();
        Fecha getFecha();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // MESAS_H_INCLUDED
