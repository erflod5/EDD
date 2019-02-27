#ifndef LISTASEMANA_H
#define LISTASEMANA_H
#include "MatrizOrtogonal.h"
struct semana{
    int numero;
    int inicio;
    int fin;
};

struct NodoSemana{
    NodoSemana *siguiente;
    semana s;
    MatrizOrtogonal *matriz;
};

class ListaSemana
{
    public:
        ListaSemana();
        virtual ~ListaSemana();
        NodoSemana * insertar(semana s);
        NodoSemana * getNodo(semana s);
        void imprimir();
        MatrizOrtogonal* getMatriz(semana s);
        bool eliminar(semana s);
        bool estaVaciaS();


    protected:

    private:
        NodoSemana *inicio;
        NodoSemana *buscar(semana s);
};

#endif // LISTASEMANA_H
