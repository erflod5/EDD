#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <string>

struct usuario{
    std::string user;
    std::string nombre;
    std::string direccion;
    std::string telefono;
};

class NodoUsuario{
    public:
        NodoUsuario(usuario u);
        NodoUsuario(usuario u, NodoUsuario *siguiente);
        usuario getUsuario();
        usuario *getUser();
        void setUsuario(usuario u);
        NodoUsuario* getSiguiente();
        void setSiguiente(NodoUsuario *siguiente);

    private:
        usuario user;
        NodoUsuario *siguiente;


    protected:

};

#endif // NODOUSUARIO_H
