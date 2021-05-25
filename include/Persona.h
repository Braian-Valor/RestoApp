#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    protected:
        char _nombre[50];
        char _apellido[50];
        int _edad;

    public:
        /// CONSTRUCTOR
        Persona(const char *nombre="XXXXX", const char *apellido="XXXXX", int edad=0);

        /// SETS
        void setNombre(char *nombre);
        void setApellido(char *apellido);
        void setEdad(int edad);

        /// GETS
        char *getNombre();
        char *getApellido();
        int getEdad();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();
};

#endif // PERSONA_H_INCLUDED
