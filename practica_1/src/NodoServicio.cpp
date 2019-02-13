#include "NodoServicio.h"

NodoServicio::NodoServicio(servicio s)
{
    dato = s;
    siguiente = 0;
}

NodoServicio::NodoServicio(servicio s,NodoServicio *sig)
{
    dato = s;
    siguiente = sig;
}


servicio NodoServicio::getServicio(){
    return dato;
}

NodoServicio* NodoServicio::nodoSiguiente(){
    return siguiente;
}


void NodoServicio::setSiguiente(NodoServicio *n){
    siguiente = n;
}

