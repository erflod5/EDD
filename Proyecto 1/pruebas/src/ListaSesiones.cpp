#include "ListaSesiones.h"
#include <string>

ListaSesiones::ListaSesiones()
{
    inicio = NULL;
}

ListaSesiones::~ListaSesiones()
{
    NodoSesion *temp = inicio;
    NodoSesion *borrar;
    while(temp!=NULL){
        borrar = temp;
        temp = temp->siguiente;
        delete borrar;
    }
}

NodoSesion* ListaSesiones::insertar(std::string id, std::string rol){
    NodoSesion *nuevo = new NodoSesion;
    sesion se; se.id = id; se.rol = rol; se.token = getVarSesion();
    nuevo->s = se; nuevo->siguiente = NULL;
    if(inicio ==NULL){
        inicio = nuevo;
    }
    else{
        NodoSesion *temp = inicio;
        while(temp->siguiente!=NULL && temp->s.id != id){
            temp = temp->siguiente;
        }
        if(temp->s.id == id) return temp;
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    return nuevo;
}

bool ListaSesiones::eliminar(std::string token){
    if(inicio==NULL){
        return false;
    }
    else{
        if(inicio->s.token == token){
            NodoSesion *temp = inicio;
            inicio = inicio->siguiente;
            temp->siguiente = NULL;
            delete temp; return true;
        }
        else{
            NodoSesion *temp = inicio;
            NodoSesion *ant = temp;
            while(temp->siguiente!=NULL && temp->s.token != token){
                ant = temp;
                temp = temp->siguiente;
            }
            if(temp->s.token == token){
                ant->siguiente = temp->siguiente;
                delete temp; return true;
            }
            return false;
        }
    }
}

sesion ListaSesiones::buscar(std::string token){
    sesion s;
    if(inicio!=NULL){
        NodoSesion *temp = inicio;
        if(temp->s.token == token){
            return temp->s;
        }
        else{
            while(temp->siguiente!=NULL && temp->s.token!=token){
                temp = temp->siguiente;
            }
            if(temp->s.token==token){
                return temp->s;
            }
        }
    }
    return s;
}


const char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int poolsize = sizeof(pool) - 1;

char ListaSesiones::getRandomChar(){
    return pool[rand() %poolsize];
}


std::string ListaSesiones::getVarSesion(){
    std::string pass;
    for(int i = 0; i<9; i++){
        pass += getRandomChar();
    }
    return pass;
}
