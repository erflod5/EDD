#ifndef NODOTRATAMIENDO_H
#define NODOTRATAMIENDO_H
#include <string>

struct tratamiento{
    std::string id;
    std::string nombre;
    float costo;
};

class NodoTratamiendo
{
    public:
        NodoTratamiendo(tratamiento t);
        NodoTratamiendo(tratamiento t,NodoTratamiendo *siguiente,NodoTratamiendo *anterior);
        tratamiento *getTrat();
        tratamiento getTratamiento();
        void setTratamiento(tratamiento t);
        NodoTratamiendo *getSiguiente();
        void setSiguiente(NodoTratamiendo *sig);
        NodoTratamiendo *getAnterior();
        void setAnterior(NodoTratamiendo *ant);


    protected:

    private:
        tratamiento t;
        NodoTratamiendo *siguiente;
        NodoTratamiendo *anterior;
};

#endif // NODOTRATAMIENDO_H
