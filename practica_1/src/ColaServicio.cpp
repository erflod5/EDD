#include "ColaServicio.h"
#include <iostream>
#include <string>
using namespace std;

ColaServicio::ColaServicio(){
    cabeza = cola = NULL;
}

ColaServicio::~ColaServicio(){
    NodoServicio *temp = cabeza;
    NodoServicio *borrar;
    while(temp!=NULL){
        borrar =temp;
        temp = temp->nodoSiguiente();
        delete borrar;
    }
}

void ColaServicio::encolar(servicio s){
    NodoServicio *nuevo = new NodoServicio(s); 
    if(cabeza==NULL){
        cabeza = cola = nuevo;
        nuevo->siguiente = NULL;
    }
    else{
        cola->setSiguiente(nuevo);
        cola = nuevo;
        nuevo->setSiguiente(NULL);
    }
}

servicio ColaServicio::desencolar(){
    servicio s;
    if(cabeza!=NULL){
        s = cabeza->getServicio();
        NodoServicio *borrar = cabeza;
        cabeza = cabeza->nodoSiguiente();
        delete borrar;
        return s;
    }
    else{
        return s;
    }
}

void ColaServicio::imprimir(){
    if(cabeza!=NULL){
        NodoServicio* temp = cabeza;
        while(temp!=NULL){
            cout<<"Usuario: "<<temp->getServicio().idUsuario<<endl;
            temp = temp->nodoSiguiente();
        }
    }
    else cout<<"Esta Vacia"<<endl;
}

bool ColaServicio::estaVacia(){
    return NULL==cabeza;
}

std::list<servicio> ColaServicio::linealizar(){
    std::list<servicio> lista;
    NodoServicio *temp = cabeza;
    while(temp!=NULL){
        lista.push_back(temp->getServicio());
        temp = temp->nodoSiguiente();
    }
    return lista;
}

const char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
int poolsize = sizeof(pool) - 1;


char ColaServicio::getRandomChar(){

    return pool[rand() %poolsize];
}

std::string ColaServicio::getVarSesion(){
    string pass;
    for(int i = 0; i<9; i++){
        pass += getRandomChar(); 
    } 
    return pass;  
}