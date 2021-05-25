#ifndef MERCADERIAS_H_INCLUDED
#define MERCADERIAS_H_INCLUDED

#include "Fecha.h"

class Mercaderias {
    private:
        char _codigo[50];
        char _nombre[50];
        int _cant;
        float _gastoEntrada;
        Fecha _fechaVencimiento;
        bool _estado;

    public:
        /// SETS
        void setCodigo(char *codigo);
        void setNombre(char *nombre);
        void setCant(int cant);
        void setGastoEntrada(float gastoEntrada);
        void setFecha(Fecha fechaVencimiento);
        void setEstado(bool estado);

        /// GETS
        char *getcodigo();
        char *getNombre();
        int getCant();
        float getGastoEntrada();
        Fecha getFecha();
        bool getEstado();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};


#endif // MERCADERIAS_H_INCLUDED
