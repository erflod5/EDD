#ifndef LISTAYEARS_H
#define LISTAYEARS_H
#include "ListaMes.h"

struct NodoYear{
    int year;
    NodoYear *siguiente;
    NodoYear *anterior;
    ListaMes *listM;
};



class ListaYears
{
    public:
        ListaYears();
        virtual ~ListaYears();
        NodoYear *insertar(int year);
        NodoYear *buscar(int year);
        void mostrar();
        bool eliminar(int year);
        ListaMes *getMes(int year);
        bool estaVacioY();


    protected:

    private:
        NodoYear *inicio;
};

#endif // LISTAYEARS_H
