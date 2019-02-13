#ifndef NODORECURSO_H_INCLUDED
#define NODORECURSO_H_INCLUDED

#include <string>

struct recurso{
  std::string tipo;
  std::string contenido;
};

class NodoRecurso
{
    public:
        NodoRecurso(recurso recurso);
        NodoRecurso(recurso recurso, NodoRecurso*siguiente);
        recurso getRecurso();
        NodoRecurso *getSiguiente();
        void setSiguiente(NodoRecurso *n);
        NodoRecurso *siguiente;

    protected:
        recurso dato;
};


#endif // NODORECURSO_H_INCLUDED
