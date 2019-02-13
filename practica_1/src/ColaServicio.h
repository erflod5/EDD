#ifndef COLASERVICIO_H_INCLUDED
#define COLASERVICIO_H_INCLUDED
#include "NodoServicio.h"
#include <list>

class ColaServicio{
    public:
        ColaServicio();
        ~ColaServicio();
        void encolar(servicio ser);
        servicio desencolar();
        void imprimir();
        bool estaVacia();
        std::list<servicio> linealizar(); 
        std::string getVarSesion();
        
    protected:
        NodoServicio*cabeza;
        NodoServicio*cola;
    private:
        char getRandomChar();
};


#endif // COLASERVICIO_H_INCLUDED
