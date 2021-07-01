#ifndef INGREDIENTESDECARTA_H_INCLUDED
#define INGREDIENTESDECARTA_H_INCLUDED

class Ingredientes{
    private:
        int _nroPlato;
        int _IDmercaderia;
        float _cant;

    public:
        /// SETS
        void setNroPlato(int nroPlato);
        void setIDmercaderia(int IDmercaderia);
        void setCant(float cant);

        /// GETS
        int getNroPlato();
        int getIDmercaderia();
        float getCant();

        /// MOSTRAR
        void mostrar();

        /// ARCHIVOS
        bool escribirEnDisco();
        bool leerDeDisco(int pos);
};


#endif // INGREDIENTESDECARTA_H_INCLUDED
