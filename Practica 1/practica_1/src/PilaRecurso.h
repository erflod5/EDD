#ifndef PILARECURSO_H_INCLUDED
#define PILARECURSO_H_INCLUDED
#include "NodoRecurso.h"

class PilaRecurso{
    public:
        PilaRecurso();
        ~PilaRecurso();
        void Push(recurso rec);
        recurso Pop();
        void imprimir();
        bool estaVacia();

    protected:
        NodoRecurso* raiz;

    private:

};


#endif // PILARECURSO_H_INCLUDED
