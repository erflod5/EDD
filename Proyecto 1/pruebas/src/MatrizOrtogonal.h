#ifndef MATRIZORTOGONAL_H
#define MATRIZORTOGONAL_H
#include <string>
struct cita{
    std::string transaccion;
    std::string idTratamiento;
    std::string idUsuario;
    bool estado;
};

struct nodo_M{
    cita c;
    nodo_M *siguiente;
    nodo_M *anterior;
    nodo_M *arriba;
    nodo_M *abajo;
    int dia, horaI,horaF;
};

struct nodo_F{
    int horaInicio, horaFin;
    nodo_F *siguiente;
    nodo_F *anterior;
    nodo_M *mat;
};

struct nodo_C{
    int dia;
    std::string nombre;
    nodo_C *siguiente;
    nodo_C *anterior;
    nodo_M *mat;
};

class MatrizOrtogonal
{
    public:
        MatrizOrtogonal();
        virtual ~MatrizOrtogonal();
        nodo_M *crearCita(cita c, int dia, int inicio, int fin, std::string nombre);
        void imprimirNodosColumna();
        void imprimirNodosFila(int dia);
        bool editar(cita c,int dia, int inicio, int fin);
        bool eliminar(int dia, int inicio, int fin);
        bool estaVacia();
        void eliminarCitasUsuario(std::string id);


    protected:
        nodo_M *insertarNodo_F(int inicio, int fin, nodo_M *nodo);
        nodo_M *insertarNodo_C(int dia, std::string nombre, nodo_M *nodo);

    private:
        nodo_F *inicioF;
        nodo_C *inicioC;

        nodo_C *insertarColumna(int dia, std::string nombre);
        nodo_F *insertarFila(int inicio, int fin);

        bool estaVacioF();
        bool estaVacioC();

        nodo_F *buscarF(int inicio, int fin);
        nodo_C *buscarC(int dia);

        nodo_F *crearFila(int inicio, int fin);
        nodo_C *crearColumna(int dia, std::string nombre);

        nodo_M *buscarCita(int dia, int inicio, int fin);

        void eliminarFila(int inicio, int fin);
        void eliminarColumna(int dia);
        bool eliminar(int dia, int inicio, int fin, nodo_M *eliminar);

};

#endif // MATRIZORTOGONAL_H
