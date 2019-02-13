#ifndef NODO_H
#define NODO_H
#include <string>

struct usuario{
  std::string nombre;
  std::string id;
  std::string correo;
  std::string fecha;
};

class Nodo
{
    public:
        Nodo(usuario user);
        Nodo(usuario user, Nodo*siguiente, Nodo*anterior);
        usuario getUsuario();
        Nodo *nodoSiguiente();
        Nodo *nodoAnterior();
        void setSiguiente(Nodo *n);
        void setAnterior(Nodo *n);
        Nodo *siguiente;
        Nodo *anterior;
        usuario *getUser();

    protected:
        usuario dato;
};

#endif // NODO_H
