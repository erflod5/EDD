#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include "NodoUsuario.h"
#include <list>

class ListaUsuarios
{
    public:
        ListaUsuarios();
        virtual ~ListaUsuarios();
        NodoUsuario* insertar(usuario user);
        bool eliminar(std::string id);
        bool estaVacia();
        int size();
        NodoUsuario* buscar(std::string id);
        usuario *getUsuario(std::string id);
        NodoUsuario*getInicio();
        NodoUsuario*getFin();
        std::list<usuario> linealizar();
        void imprimir();
        std::string imprimirDot();
        bool editar(usuario u,std::string id);


    protected:
        NodoUsuario *inicio;
        NodoUsuario *fin;

    private:
        int tam;
};

#endif // LISTAUSUARIOS_H
