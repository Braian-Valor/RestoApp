#ifndef MESAS_H_INCLUDED
#define MESAS_H_INCLUDED

class Mesas{
    private:
        int _nroMesa;
        int _capacidad;
        bool _estado;

    public:
        /// SETS
        void setNroMesa(int nroMesa);
        void setCapacidad(int capacidad);
        void setEstado(bool estado);

        /// GETS
        int getNroMesa();
        int getCapacidad();
        bool getEstado();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // MESAS_H_INCLUDED
