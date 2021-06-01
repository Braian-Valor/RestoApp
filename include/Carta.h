#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

class Carta{
    private:
        int _idArticulo;
        char _nombre[50];
        char _tipo[50];
        float _precio;
        bool _estado;

    public:
        /// SETS
        void setIDArticulo(int ID);
        void setNombre(char *nombre);
        void setTipo(char *tipo);
        void setPrecio(float precio);
        void setEstado(bool estado);

        /// GETS
        int getIDArticulo();
        char *getNombre();
        char *getTipo();
        float getPrecio();
        bool getEstado();

        /// ABM
        void Cargar();
        void Mostrar();
        void modificarCarta();
        void eliminarElemento();
        void consultaCarta();


        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);


};

#endif // CARTA_H_INCLUDED
