#include "ListaYears.h"
#include <iostream>
ListaYears::ListaYears()
{
    inicio = NULL;
}

ListaYears::~ListaYears()
{
    //dtor
}

NodoYear* ListaYears::buscar(int year){
    NodoYear*aux = inicio;
    while(aux!=NULL){
        if(aux->year == year) return aux;
        aux = aux->siguiente;
    }
    return NULL;
}

NodoYear *ListaYears::insertar(int year){
    if(inicio==NULL){
        NodoYear* nuevo = new NodoYear;
        nuevo->year = year;
        nuevo->listM = new ListaMes();
        nuevo->siguiente = nuevo->anterior = NULL;
        inicio = nuevo;
        return nuevo;
    }
    else{
        NodoYear *b = buscar(year);
        if(b==NULL){
            NodoYear* nuevo = new NodoYear;
            nuevo->year = year;
            nuevo->listM = new ListaMes();
            nuevo->siguiente = nuevo->anterior = NULL;
            if(year < (inicio->year)){
                nuevo->siguiente = inicio;
                inicio->anterior = nuevo;
                inicio = nuevo;
            }
            else{
                NodoYear *temp = inicio;
                NodoYear *ant = inicio;
                while(temp->siguiente != NULL && year > (temp->year)){
                    ant = temp;
                    temp = temp->siguiente;
                }
                if(year > temp->year){
                    temp->siguiente = nuevo;
                    nuevo->anterior = temp;
                    nuevo->siguiente = NULL;
                }
                else{
                    nuevo->siguiente = temp; temp->anterior = nuevo;
                    nuevo->anterior = ant; ant->siguiente = nuevo;
                }
            }
            return nuevo;
        }
        else{
            return b;
        }
    }
}

void ListaYears::mostrar(){
    NodoYear *temp = inicio;
    while(temp!=NULL){
        std::cout<<"Año: " <<temp->year<<std::endl;
        temp = temp->siguiente;
    }
}

bool ListaYears::eliminar(int year){
    NodoYear *borrar = buscar(year);
    if(borrar!=NULL){
        if(borrar==inicio){
            inicio = borrar->siguiente;
            inicio->anterior = NULL; borrar->siguiente = NULL;
            delete borrar;
        }
        else{
            NodoYear *temp = inicio;
            NodoYear *ant = inicio;
            while(temp!=borrar){
                ant = temp;
                temp = temp->siguiente;
            }
            if(temp->siguiente==NULL){
                ant->siguiente =NULL; temp->anterior = NULL;
                delete temp;
            }
            else{
                ant->siguiente = temp->siguiente;
                temp->anterior = ant;
                delete temp;
            }
        }
        return true;
    }
    return false;
}


bool ListaYears::estaVacioY(){
    return inicio==NULL;
}

ListaMes *ListaYears::getMes(int year){
    NodoYear *aux = buscar(year);
    if(aux!=NULL) return aux->listM;
    return NULL;
}
