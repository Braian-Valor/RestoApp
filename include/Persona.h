#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    protected:
        char _nombre[50];
        char _apellido[50];
        int _edad;
        int _DNI;

    public:
        /// CONSTRUCTOR
        Persona(const char *nombre="XXXXX", const char *apellido="XXXXX", int edad=0);

        /// SETS
        void setNombre(char *nombre);
        void setApellido(char *apellido);
        void setEdad(int edad);
        void setDNI(int DNI);

        /// GETS
        char *getNombre();
        char *getApellido();
        int getEdad();
        int getDNI();

        /// CARGAR Y MOSTRAR
        void Cargar();
        void Mostrar();
};

#endif // PERSONA_H_INCLUDED
