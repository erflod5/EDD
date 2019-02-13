#include "Lista.h"
#include <iostream>
using namespace std;


Lista::Lista()
{
    primero = NULL;
    tam = 0;
}

Lista::~Lista(){
    Nodo *temp = primero;
    Nodo *eliminar;
    tam = 0;
    while(temp!=NULL){
        eliminar = temp;
        temp = temp->siguiente;
        delete eliminar;
    }
}

Nodo* Lista::insertar(usuario user){ 
    Nodo *nuevo = new Nodo(user);
    if(primero==NULL){
        primero = nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        tam++;
        return nuevo;
    }
    else{
        Nodo *b = buscar(user.id);
        if(b==NULL){
            const char * n1 = user.nombre.c_str();
            const char * n2 = primero->getUsuario().nombre.c_str(); //user.nombre <= (primero->getUsuario().nombre)   user.nombre >= temp->getUsuario().nombre 
            if((tolower(*n1))<=(tolower(*n2)) ){
                nuevo->siguiente = primero;
                primero->anterior = nuevo;
                primero = nuevo;
            }
            else{
                Nodo *temp = primero;
                Nodo *ant = primero;
                n2 = temp->getUsuario().nombre.c_str();
                while(temp->siguiente!=NULL && (tolower(*n1))>=(tolower(*n2))){
                    ant = temp;
                    temp = temp->siguiente;
                    n2 = temp->getUsuario().nombre.c_str();
                }
                if((tolower(*n1))>=(tolower(*n2))){
                    temp->siguiente = nuevo;
                    nuevo->anterior = temp;
                }
                else{
                    nuevo->siguiente = temp; temp->anterior = nuevo;
                    ant->siguiente = nuevo; nuevo->anterior = ant;
                }
            }
            tam++;
            return nuevo;
        }
        else{
            cout<<"Repetido"<<endl;
        	return NULL;
        }
    }
}

Nodo *Lista::buscar(std::string id){
    Nodo*temp = primero;
    while(temp!=NULL){
        if(temp->getUsuario().id==id){
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

bool Lista::estaVacia(){
    return primero == NULL;
}

void Lista::eliminar(std::string id){
    if(primero!=NULL){
        Nodo*temp = primero;
        if(temp->getUsuario().id == id){
            primero = temp->siguiente; primero->anterior = NULL; temp->siguiente = NULL;
            delete temp;
            tam--;
        }
        else{
            while(temp!=NULL && temp->getUsuario().id != id){
                temp = temp->siguiente;
            }
            if(temp==NULL) cout<<"No encontrado";
            else{
                if(temp->siguiente == NULL){
                    temp->anterior->siguiente = NULL; temp->anterior = NULL;
                    delete temp;
                }
                else{
                    Nodo *ant = temp->anterior;
                    Nodo *sig = temp->siguiente;
                    ant->siguiente = sig;
                    sig->anterior = ant;
                    delete temp;
                }
                tam--;
            }
        }
    }
}

void Lista::mostrar(){
    if(primero!=NULL){
        Nodo* temp = primero;
        while(temp!=NULL){
            cout<<"Nombre: "<<temp->getUsuario().nombre<<" Id: " <<temp->getUsuario().id<<endl;
            temp = temp->siguiente;
        }
    }
    else{
        cout<<"Esta Vacia"<<endl;
    }
}

usuario Lista::getUsuario(std::string id){
    usuario result;
    Nodo *b = buscar(id);
    if(b!=NULL) return b->getUsuario();
    return result;
}

usuario *Lista::getUser(std::string id){
    usuario *result = NULL;
    Nodo *b = buscar(id);
    if(b!=NULL) return b->getUser();
    return result;
}

int Lista::getTam(){
    return tam;
}

Nodo * Lista::getPrimero(){
	return primero;
}

std::list<usuario> Lista::linealizar()
{
    std::list<usuario> lista;
    Nodo *tmp = primero;
    while(tmp!=NULL){
        lista.push_back(tmp->getUsuario());
        tmp = tmp->siguiente;
    }
    return lista;
}



/*string Lista::listar(){
	if(primero==NULL) return "Esta Vacia";
	else{
		string res = "[\n";
		Nodo *temp = primero;	
		while(temp!=NULL){
			res+="{\n" + temp->getUsuario().nombre + "\n}";
			temp = temp->siguiente;
		}
		res+= "\n]";
		return res;
	}	
}*/