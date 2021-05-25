#ifndef FECHA_H
#define FECHA_H

class Fecha {
    private:
        int _dia, _mes, _anio;

    public:
        /// CONSTRUCTOR
        Fecha(int dia=0, int mes=0, int anio=0);

        /// SETS
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        /// GETS
        int getDia();
        int getMes();
        int getAnio();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();
};

#endif // FECHA_H
