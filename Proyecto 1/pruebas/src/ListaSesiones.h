#ifndef LISTASESIONES_H
#define LISTASESIONES_H
#include <string>

struct sesion{
    std::string token;
    std::string id;
    std::string rol;
};

struct NodoSesion{
    sesion s;
    NodoSesion *siguiente;
};

class ListaSesiones
{
    public:
        ListaSesiones();
        virtual ~ListaSesiones();

        NodoSesion *insertar(std::string id, std::string rol);
        bool eliminar(std::string token);
        sesion buscar(std::string token);
        std::string getVarSesion();

    protected:

    private:
        NodoSesion *inicio;
        char getRandomChar();
};

#endif // LISTASESIONES_H
