#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

class Carta{
    private:
        int _nroPlato;
        char _nombrePlato[50];
        float _precioPlato;
        bool _estado;
    public:
        /// SETS
        void setNroPlato(int nroPlato);
        void setNombrePlato(char *nombrePlato);
        void setPrecioPlato(float precioPlato);
        void setEstado(bool estado);

        /// GETS
        int getNroPlato();
        char *getNombrePlato();
        float getPrecioPlato();
        bool getEstado();

        /// MOSTRAR
        void Mostrar();
        void MostrarsinPrecio();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};

#endif // CARTA_H_INCLUDED
