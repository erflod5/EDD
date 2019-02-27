#include "NodoUsuario.h"

NodoUsuario::NodoUsuario(usuario u){
    user = u;
    siguiente = NULL;
}

NodoUsuario::NodoUsuario(usuario u, NodoUsuario * sig){
    user = u;
    siguiente = sig;
}

usuario NodoUsuario::getUsuario(){
    return user;
}

void NodoUsuario::setUsuario(usuario u){
    user = u;
}

NodoUsuario* NodoUsuario::getSiguiente(){
    return siguiente;
}

void NodoUsuario::setSiguiente(NodoUsuario *sig){
    siguiente = sig;
}

usuario* NodoUsuario::getUser(){
    usuario *u = &user;
    return u;
}


