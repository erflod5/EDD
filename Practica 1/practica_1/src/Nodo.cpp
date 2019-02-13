#include "Nodo.h"

Nodo::Nodo(usuario user)
{
    dato = user;
    siguiente = anterior = 0;
}

Nodo::Nodo(usuario user,Nodo *sig, Nodo *ant)
{
    dato = user;
    siguiente = sig;
    anterior = ant;
}


usuario Nodo::getUsuario(){
    return dato;
}

usuario* Nodo::getUser(){
    usuario *user = &dato;
    return user;
}

Nodo* Nodo::nodoSiguiente(){
    return siguiente;
}

Nodo* Nodo::nodoAnterior(){
    return anterior;
}

void Nodo::setSiguiente(Nodo *n){
    siguiente = n;
}

void Nodo::setAnterior(Nodo *n){
    anterior = n;
}
