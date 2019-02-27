#include "ListaMes.h"
#include <iostream>

ListaMes::ListaMes()
{
    inicio = NULL;
}

ListaMes::~ListaMes()
{
    //dtor
}

NodoMes *ListaMes::insertar(mes m){
    if(inicio==NULL){
        NodoMes *nuevo = new NodoMes;
        nuevo->m = m;
        nuevo->lista = new ListaSemana();
        nuevo->siguiente = NULL;
        inicio = nuevo;
        return nuevo;
    }
    else{
        NodoMes *b = buscar(m.num);
        if(b==NULL){
            NodoMes *nuevo = new NodoMes;
            nuevo->m = m;
            nuevo->lista = new ListaSemana();
            if(nuevo->m.num < inicio->m.num){
                nuevo->siguiente = inicio;
                inicio = nuevo;
                return nuevo;
            }
            else{
                NodoMes *temp = inicio;
                NodoMes *ant = inicio;
                while(temp->siguiente!=NULL && nuevo->m.num > temp->m.num){
                    ant =temp;
                    temp = temp->siguiente;
                }
                if(nuevo->m.num > temp->m.num){
                    temp->siguiente = nuevo;
                    nuevo->siguiente = NULL;
                    return nuevo;
                }
                else{
                    ant->siguiente = nuevo;
                    nuevo->siguiente =temp;
                    return nuevo;
                }
            }
        }
        return b;
    }
}
NodoMes *ListaMes::insertar(std::string nombre, int me){
    mes m; m.num = me; m.mes = nombre;
    if(inicio==NULL){
        NodoMes *nuevo = new NodoMes;
        nuevo->m = m;
        nuevo->lista = new ListaSemana();
        nuevo->siguiente = NULL;
        inicio = nuevo;
        return nuevo;
    }
    else{
        NodoMes *b = buscar(m.num);
        if(b==NULL){
            NodoMes *nuevo = new NodoMes;
            nuevo->m = m;
            nuevo->lista = new ListaSemana();
            if(nuevo->m.num < inicio->m.num){
                nuevo->siguiente = inicio;
                inicio = nuevo;
                return nuevo;
            }
            else{
                NodoMes *temp = inicio;
                NodoMes *ant = inicio;
                while(temp->siguiente!=NULL && nuevo->m.num > temp->m.num){
                    ant =temp;
                    temp = temp->siguiente;
                }
                if(nuevo->m.num > temp->m.num){
                    temp->siguiente = nuevo;
                    nuevo->siguiente = NULL;
                    return nuevo;
                }
                else{
                    ant->siguiente = nuevo;
                    nuevo->siguiente =temp;
                    return nuevo;
                }
            }
        }
        return b;
    }
}

NodoMes *ListaMes::buscar(int n){
    NodoMes *temp = inicio;
    while(temp!=NULL){
        if(temp->m.num == n) return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

bool ListaMes::eliminar(int n){
    NodoMes *borrar = buscar(n);
    if(borrar!=NULL){
        if(borrar == inicio){
            inicio = inicio->siguiente;
            delete borrar;
        }
        else{
            NodoMes *aux = inicio;
            while(aux->siguiente != borrar){
                aux = aux->siguiente;
            }
            aux->siguiente = borrar->siguiente;
            delete borrar;
        }
        return true;
    }
    return false;
}

ListaSemana *ListaMes::getSemana(int n){
    NodoMes *b = buscar(n);
    if(b!=NULL) return b->lista;
    return NULL;
}

bool ListaMes::estaVacioM(){
    return inicio==NULL;
}

void ListaMes::mostrar(){
    NodoMes *temp = inicio;
    while(temp!=NULL){
        std::cout<<"Mes: " <<temp->m.num<<std::endl;
        temp = temp->siguiente;
    }
}

