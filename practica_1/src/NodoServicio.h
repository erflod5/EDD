#ifndef NODOSERVICIO_H
#define NODOSERVICIO_H
#include <string>

struct servicio{
  std::string idSesion;
  std::string idUsuario;
  std::string contenido;
  std::string tipo;
};

class NodoServicio
{
    public:
        NodoServicio(servicio s);
        NodoServicio(servicio s, NodoServicio*siguiente);
        servicio getServicio();
        NodoServicio *nodoSiguiente();
        void setSiguiente(NodoServicio *n);
        NodoServicio *siguiente;

    protected:
        servicio dato;
};

#endif // NODO_H
