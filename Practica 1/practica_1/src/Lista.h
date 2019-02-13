#ifndef LISTA_H
#define LISTA_H
#include <string>
#include "Nodo.h"
#include <list>

class Lista
{
    public:
        Lista();
        ~Lista();
        Nodo* insertar(usuario user);
        void eliminar(std::string id);
        bool estaVacia();
        void mostrar();
        usuario getUsuario(std::string id);
        int getTam();
        Nodo *getPrimero();
        std::list<usuario> linealizar();
        Nodo *buscar(std::string id);
        usuario *getUser(std::string id);
        
    protected:
        Nodo* primero; 
    private:
        int tam;


};

#endif // LISTA_H
