#ifndef NODOSEMANA_H
#define NODOSEMANA_H
#include "MatrizOrtogonal.h"

struct semana{
    int numero;
    int inicio;
    int fin;
};

class NodoSemana
{
    public:
        NodoSemana(semana s);
        virtual ~NodoSemana();
        semana getSemana();
        void setSemana(semana s);
        NodoSemana *getSiguiente();
        void setSiguiente(NodoSemana *nodo);

        MatrizOrtogonal* getMat();

    protected:

    private:
        semana se;
        NodoSemana *siguiente;
        MatrizOrtogonal *mat;
};

#endif // NODOSEMANA_H
