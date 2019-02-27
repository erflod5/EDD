#include "ListaUsuarios.h"
#include <iostream>

ListaUsuarios::ListaUsuarios(){
    inicio = fin = NULL;
    tam = 0;
}

ListaUsuarios::~ListaUsuarios(){
    if(inicio!=NULL){
        NodoUsuario *temp =inicio->getSiguiente();
        NodoUsuario *borrar;
        while(temp!=inicio){
            borrar = temp;
            temp = temp->getSiguiente();
            delete borrar;
        }
        delete inicio;
        delete fin;
    }
}

NodoUsuario *ListaUsuarios::insertar(usuario user){
    NodoUsuario* nuevo = new NodoUsuario(user);
    if(inicio==NULL){
        nuevo->setSiguiente(nuevo);
        inicio = fin = nuevo; tam++;
        return nuevo;
    }
    else{
        NodoUsuario *b = buscar(user.user);
        if(b==NULL){
            const char * name1 = user.nombre.c_str();
            const char * name2 = inicio->getUsuario().nombre.c_str();
            if((tolower(*name1))<=tolower(*name2)){
                nuevo->setSiguiente(inicio);
                fin->setSiguiente(nuevo);
                inicio = nuevo;
                return nuevo;
            }
            else{
                NodoUsuario *temp = inicio;
                NodoUsuario *ant = inicio;
                name2 = temp->getUsuario().nombre.c_str();
                while(temp->getSiguiente()!=inicio && (tolower(*name1)) >= (tolower(*name2))){
                    ant = temp;
                    temp = temp->getSiguiente();
                    name2 = temp->getUsuario().nombre.c_str();
                }
                if((tolower(*name1)) >= (tolower(*name2))){
                    nuevo->setSiguiente(inicio);
                    fin->setSiguiente(nuevo);
                    fin = nuevo;
                    return nuevo;
                }
                else{
                    ant->setSiguiente(nuevo);
                    nuevo->setSiguiente(temp);
                    return nuevo;
                }
            }
        }
        else{
            std::cout<<"repetido"<<std::endl;
            return NULL;
        }
    }
}

bool ListaUsuarios::eliminar(std::string id){ //PENDIENTE
    if(inicio!=NULL){
        if(inicio->getUsuario().user == id){
            if(inicio== fin){
                NodoUsuario *temp = inicio;
                inicio = fin = NULL;
                delete temp;
                return true;
            }
            else{
                NodoUsuario*temp = inicio;
                inicio = inicio->getSiguiente();
                fin->setSiguiente(inicio);
                delete temp;
                return true;
            }
        }
        else{
            NodoUsuario *temp = inicio->getSiguiente();
            NodoUsuario *ant = inicio;
            bool encontrado = false;
            while(temp!=inicio && encontrado!=true){
                if(temp->getUsuario().user==id){
                    encontrado = true;
                    if(temp == fin) {
                        fin = ant;
                        fin->setSiguiente(inicio);
                        delete temp;
                        return true;
                    }
                    else{
                        ant->setSiguiente(temp->getSiguiente());
                        temp->setSiguiente(NULL);
                        delete temp;
                        return true;
                    }
                }
                ant = temp; temp = temp->getSiguiente();
            }

        }
    }
    return false;
}

bool ListaUsuarios::editar(usuario u,std::string id){
    NodoUsuario* b = buscar(id);
    if(b==NULL) return false;
    else{
        b->setUsuario(u);
        return true;
    }
}

bool ListaUsuarios::estaVacia(){
    return inicio == NULL;
}

int ListaUsuarios::size(){
    return tam;
}

NodoUsuario* ListaUsuarios::buscar(std::string id){
    if(inicio!=NULL){
        if(inicio->getUsuario().user == id) return inicio;
        if(fin->getUsuario().user==id) return fin;
        NodoUsuario *temp = inicio;
        while(temp->getSiguiente()!=inicio){
            if(temp->getUsuario().user == id) return temp;
            temp = temp->getSiguiente();
        }
    }
    return NULL;
}

usuario *ListaUsuarios::getUsuario(std::string id){
    NodoUsuario *b = buscar(id);
    if(b!=NULL) return b->getUser();
    return NULL;
}

NodoUsuario *ListaUsuarios::getInicio(){
    return inicio;
}

NodoUsuario *ListaUsuarios::getFin(){
    return fin;
}

std::list<usuario> ListaUsuarios::linealizar(){
    std::list<usuario> lista;
    if(inicio!=NULL){
        NodoUsuario *temp = inicio;
        do{
            lista.push_back(temp->getUsuario());
            temp = temp->getSiguiente();
        }
        while(temp!=inicio);
    }
    return lista;
}

void ListaUsuarios::imprimir(){
    if(inicio!=NULL){
        NodoUsuario *temp = inicio;
        do{
            std::cout<<"Nombre: "<<temp->getUsuario().nombre<<" Id: "<<temp->getUsuario().user<<std::endl;
            temp = temp->getSiguiente();
        }
        while(temp!=inicio);
    }
}


std::string ListaUsuarios::imprimirDot(){ //PENDIENTE
 std::string dot = "dot";


 return dot;
}
/*NodoUsuario* insertar(usuario user);
        void eliminar(std::string id);
        bool estaVacia();
        int size();
        NodoUsuario* buscar(std::string id);
        usuario *getUsuario(std::string id);
        NodoUsuario*getInicio();
        NodoUsuario*getFin();
        std::list<usuario> linealizar();
        void imprimir();*/
