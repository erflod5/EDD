#include "ListaSemana.h"
#include <iostream>
ListaSemana::ListaSemana()
{
    inicio = NULL;
}

ListaSemana::~ListaSemana()
{
    //dtor
}

NodoSemana *ListaSemana::insertar(semana s){
    NodoSemana* nuevo = new NodoSemana;
    nuevo->matriz = new MatrizOrtogonal();
    nuevo->s = s;

    if(inicio==NULL){
        nuevo->siguiente = NULL;
        inicio = nuevo;
        return nuevo;
    }
    else{
        NodoSemana *b = buscar(s);
        if(b==NULL){
            if(s.numero < inicio->s.numero){
                nuevo->siguiente = inicio;
                inicio = nuevo;
            }
            else{
                NodoSemana *temp = inicio;
                NodoSemana* ant = inicio;
                while(temp->siguiente !=NULL && s.numero > temp->s.numero){
                    ant = temp;
                    temp = temp->siguiente;
                }
                if(s.numero > temp->s.numero){
                    temp->siguiente = nuevo;
                    nuevo->siguiente = NULL;
                }
                else{
                    ant->siguiente = nuevo;
                    nuevo->siguiente = temp;
                }
            }
            return nuevo;
        }
        return b;
    }
}


NodoSemana *ListaSemana::buscar(semana s){
    NodoSemana *temp = inicio;
    while(temp!=NULL){
        if(temp->s.numero == s.numero){
        return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

bool ListaSemana::eliminar(semana s){
    NodoSemana*b = buscar(s);
    if(b!=NULL){
        if(b->matriz->estaVacia()){
            if(b == inicio){
                inicio = inicio->siguiente;
                delete b;
                return true;
            }
            else{
                NodoSemana* aux = inicio;
                while(aux->siguiente!=b){
                    aux = aux->siguiente;
                }
                aux->siguiente = b->siguiente;
                delete b;
                return true;
            }
            return true;
        }
        return false;
    }
    return false;
}

NodoSemana *ListaSemana::getNodo(semana s){
    return buscar(s);
}

MatrizOrtogonal *ListaSemana::getMatriz(semana s){
    NodoSemana *nodo = buscar(s);
    return nodo->matriz;
}


bool ListaSemana::estaVaciaS(){
    return inicio==NULL;
}

void ListaSemana::imprimir(){
    if(inicio!=NULL){
        NodoSemana*temp = inicio;
        while(temp!=NULL){
            std::cout<<"Numero: "<<temp->s.numero <<" Inicio: " <<temp->s.inicio<<std::endl;
            temp = temp->siguiente;
        }
    }
}
