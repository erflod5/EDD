#ifndef LISTAMES_H
#define LISTAMES_H
#include <string>
#include "ListaSemana.h"

struct mes{
    int num;
    std::string mes;
};

struct NodoMes{
    NodoMes *siguiente;
    mes m;
    ListaSemana *lista;
};

class ListaMes
{
    public:
        ListaMes();
        virtual ~ListaMes();
        NodoMes *insertar(mes m);
        NodoMes *insertar(std::string nombre, int me);
        NodoMes *buscar(int n);
        bool eliminar(int n);
        ListaSemana *getSemana(int n);
        bool estaVacioM();
        void mostrar();

    protected:

    private:
        NodoMes *inicio;
};

#endif // LISTAMES_H
