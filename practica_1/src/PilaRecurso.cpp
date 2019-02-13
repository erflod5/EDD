#include "PilaRecurso.h"
#include <iostream>
#include <string>
using namespace std;

PilaRecurso::PilaRecurso(){
    raiz = NULL;
}

PilaRecurso::~PilaRecurso(){
    NodoRecurso *temp = raiz;
    NodoRecurso *borrar;
    while(temp!=NULL){
        borrar = temp;
        temp = temp->siguiente;
        delete borrar;
    }
}

void PilaRecurso::Push(recurso rec){
    NodoRecurso *nuevo = new NodoRecurso(rec);
    if(raiz==NULL){
        raiz = nuevo;
        nuevo->siguiente = NULL;
    }
    else{
        nuevo->siguiente = raiz;
        raiz = nuevo;
    }
}

recurso PilaRecurso::Pop(){
    if(raiz!=NULL){
        recurso inf = raiz->getRecurso();
        NodoRecurso*temp = raiz;
        raiz = raiz->siguiente;
        delete temp;
        return inf;
    }
    else return raiz->getRecurso();
}

void PilaRecurso::imprimir(){
    if(raiz!=NULL){
        NodoRecurso*temp = raiz;
        while(temp!=NULL){
            cout<<"Dato: "<<temp->getRecurso().contenido<<endl;
            temp = temp->siguiente;
        }
    }
}
bool PilaRecurso::estaVacia(){
    return NULL==raiz;
}
