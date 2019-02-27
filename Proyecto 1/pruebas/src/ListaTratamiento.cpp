#include "ListaTratamiento.h"
#include <iostream>
#include <string>

ListaTratamiento::ListaTratamiento()
{
    inicio = NULL;
}

ListaTratamiento::~ListaTratamiento()
{
    if(inicio!=NULL){
        NodoTratamiendo *t = inicio->getSiguiente();
        while(t!= inicio){
            NodoTratamiendo*borrar = t;
            t = t->getSiguiente();
            delete borrar;
        }
        delete t;
    }
}

NodoTratamiendo* ListaTratamiento::insertarInicio(tratamiento t){
    NodoTratamiendo *nuevo = new NodoTratamiendo(t);
    if(inicio==NULL){
        inicio = nuevo;
        fin = nuevo;
        inicio->setSiguiente(inicio); inicio->setAnterior(fin);
        return nuevo;}

    if(buscar(t.id) == NULL ){
        fin->setSiguiente(nuevo);
        nuevo->setAnterior(fin);
        nuevo->setSiguiente(inicio);
        fin = nuevo;
        inicio->setAnterior(fin);
        return nuevo;
    }
    else {std::cout<<"Repetido"<<std::endl; return NULL;}
}

std::string ListaTratamiento::imprimirDot(){//PENDIENTE
    return "";
}

NodoTratamiendo* ListaTratamiento::buscar(std::string id){
    NodoTratamiendo *nuevo = NULL;
    if(inicio!=NULL){
        if(inicio->getTratamiento().id == id) return inicio;
        nuevo = inicio->getSiguiente();
        while(nuevo!=inicio){
            if(nuevo->getTratamiento().id == id) return nuevo;
            nuevo = nuevo->getSiguiente();
        }
    }
    return NULL;
}
bool ListaTratamiento::editar(tratamiento t, std::string id){
    NodoTratamiendo *edit = buscar(id);
    if(edit!=NULL){
        edit->setTratamiento(t);
        return true;
    }
    return false;
}

bool ListaTratamiento::eliminar(std::string id){
    if(inicio!=NULL){
        if(inicio->getTratamiento().id == id){
            if(inicio == inicio->getSiguiente()){
                inicio = NULL;
                return true;
            }
            else{
                NodoTratamiendo* borrar = inicio;
                inicio->getAnterior()->setSiguiente(inicio->getSiguiente());
                inicio->getSiguiente()->setAnterior(inicio->getAnterior());
                inicio = inicio->getSiguiente();
                delete borrar;
            }
            return true;
        }
        NodoTratamiendo *temp = inicio->getSiguiente();
        while(temp!=inicio){
            if(temp->getTratamiento().id == id){
                temp->getAnterior()->setSiguiente(temp->getSiguiente());
                temp->getSiguiente()->setAnterior(temp->getAnterior());
                delete temp;
                return true;
            }
            temp = temp->getSiguiente();
        }
    }
    return false;
}

/*void ListaTratamiento::imprimir(){
    if(inicio!=NULL){
        NodoTratamiendo*temp = inicio;
        std::cout<<inicio->getTratamiento().id<<" "<<inicio->getTratamiento().nombre<<std::endl;
        temp = inicio->getSiguiente();
        while(temp!=inicio){
            std::cout<<temp->getTratamiento().id<<" "<<temp->getTratamiento().nombre<<std::endl;
            temp = temp->getSiguiente();
        }
    }
}*/

void ListaTratamiento::imprimir(){
    if(inicio!=NULL){
        NodoTratamiendo *temp = inicio;
        do{
            std::cout<<"Nombre: "<<temp->getTratamiento().nombre<<" Id: "<<temp->getTratamiento().id<<std::endl;
            temp = temp->getSiguiente();
        }
        while(temp!=inicio);
    }
}

std::list<tratamiento> ListaTratamiento::linealizar(){
    std::list<tratamiento> lista;
    if(inicio!=NULL){
        NodoTratamiendo *temp = inicio;
        do{
            lista.push_back(temp->getTratamiento());
            temp = temp->getSiguiente();
        }
        while(temp!=inicio);
    }
    return lista;
}
