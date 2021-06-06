#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include "Fecha.h"

class Cliente:public Persona {
    private:
        int _ID;
        Fecha _fechaIngreso;
        bool _estado;

    public:
        /// SETS
        void setID(int ID);
        void setFecha(Fecha fechaIngreso);
        void setEstado(bool estado);

        /// GETS
        int getID();
        Fecha getFecha();
        bool getEstado();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // CLIENTE_H
