#include "NodoTratamiendo.h"

NodoTratamiendo::NodoTratamiendo(tratamiento trat)
{
    t = trat;
    siguiente = anterior = NULL;
}

NodoTratamiendo::NodoTratamiendo(tratamiento trat,NodoTratamiendo *sig,NodoTratamiendo*ant){
    t = trat;
    siguiente = sig;
    anterior = ant;
}

tratamiento NodoTratamiendo::getTratamiento(){
    return t;
}

tratamiento *NodoTratamiendo::getTrat(){
    tratamiento *trat = &t;
    return trat;
}

void NodoTratamiendo::setTratamiento(tratamiento trat){
    t = trat;
}

NodoTratamiendo *NodoTratamiendo::getSiguiente(){
    return siguiente;
}

void NodoTratamiendo::setSiguiente(NodoTratamiendo *sig){
    siguiente = sig;
}

NodoTratamiendo *NodoTratamiendo::getAnterior(){
    return anterior;
}


void NodoTratamiendo::setAnterior(NodoTratamiendo *ant){
    anterior = ant;
}


/*
-NodoTratamiendo(tratamiento t);
        NodoTratamiendo(tratamiento t,NodoTratamiendo *siguiente,NodoTratamiendo *anterior);
        tratamiento *getTrat();
        tratamiento getTratamiento();
        void setTratamiento(tratamiento t);
        NodoTratamiendo *getSiguiente();
        void setSiguiente(NodoTratamiendo *sig);
        NodoTratamiendo *getAnterior();
        void setAnterior(NodoTratamiendo *ant);
*/
