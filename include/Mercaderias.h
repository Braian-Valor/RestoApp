#ifndef MERCADERIAS_H_INCLUDED
#define MERCADERIAS_H_INCLUDED

class Mercaderias{
    private:
        int _ID;
        char _nombre[50];
        float _cantStock;
        bool _estado;
    public:
        /// SETS
        void setID(int ID);
        void setNombre(char *nombre);
        void setCantStock(float cantStock);
        void setEstado(bool estado);

        /// GETS
        int getID();
        char *getNombre();
        float getCantStock();
        bool getEstado();

        /// MOSTRAR
        void Mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};


#endif // MERCADERIAS_H_INCLUDED
