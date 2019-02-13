#include "NodoRecurso.h"

NodoRecurso::NodoRecurso(recurso rec)
{
    dato = rec;
    siguiente =0;
}

NodoRecurso::NodoRecurso(recurso rec,NodoRecurso *sig)
{
    dato = rec;
    siguiente = sig;
}


recurso NodoRecurso::getRecurso(){
    return dato;
}

NodoRecurso* NodoRecurso::getSiguiente(){
    return siguiente;
}


void NodoRecurso::setSiguiente(NodoRecurso *n){
    siguiente = n;
}

