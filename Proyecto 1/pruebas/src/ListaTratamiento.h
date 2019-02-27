#ifndef LISTATRATAMIENTO_H
#define LISTATRATAMIENTO_H
#include "NodoTratamiendo.h"
#include <list>


class ListaTratamiento
{
    public:
        ListaTratamiento();
        virtual ~ListaTratamiento();
        NodoTratamiendo *insertarInicio(tratamiento t);
        std::string imprimirDot();
        NodoTratamiendo* buscar(std::string id);
        bool editar(tratamiento t, std::string id);
        bool eliminar(std::string id);
        void imprimir();
        std::list<tratamiento> linealizar();

    protected:

    private:
        NodoTratamiendo *inicio, *fin;
};

#endif // LISTATRATAMIENTO_H
