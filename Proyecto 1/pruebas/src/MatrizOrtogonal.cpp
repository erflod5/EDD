#include "MatrizOrtogonal.h"
#include <iostream>

MatrizOrtogonal::MatrizOrtogonal()
{
    inicioF = NULL;
    inicioC = NULL;
}

MatrizOrtogonal::~MatrizOrtogonal()
{
    //dtor
}

nodo_C* MatrizOrtogonal::crearColumna(int dia, std::string nombre){
    nodo_C *nuevo = new nodo_C;
    nuevo->dia = dia;
    nuevo->nombre = nombre;
    nuevo->mat = NULL;
    return nuevo;
}

nodo_F* MatrizOrtogonal::crearFila(int inicio, int fin){
    nodo_F *nuevo = new nodo_F;
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    nuevo->mat = NULL;
    return nuevo;
}

nodo_F * MatrizOrtogonal::buscarF(int inicio, int fin){
    nodo_F *temp = inicioF;
    while(temp!=NULL){
        if(temp->horaInicio == inicio && temp->horaFin== fin) return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

nodo_C* MatrizOrtogonal::buscarC(int dia){
    nodo_C *temp = inicioC;
    while(temp!=NULL){
        if(temp->dia==dia) return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

bool MatrizOrtogonal::estaVacioC(){
    return inicioC==NULL;
}

bool MatrizOrtogonal::estaVacioF(){
    return inicioF==NULL;
}

nodo_C *MatrizOrtogonal::insertarColumna(int dia, std::string nombre){
    if(estaVacioC()){
        nodo_C *nuevo = crearColumna(dia,nombre);
        inicioC = nuevo;
        inicioC->siguiente = inicioC->anterior = NULL;
        inicioC->mat = NULL;
        return nuevo;
    }
    else{
        nodo_C *aux = buscarC(dia);
        if(aux !=NULL ) return aux;

        nodo_C *nuevo = crearColumna(dia,nombre);
        nuevo->mat = NULL;
        if(dia < inicioC->dia){
            nuevo->siguiente = inicioC;
            inicioC->anterior = nuevo;
            inicioC = nuevo;
        }
        else{
            nodo_C *atras = inicioC;
            aux = inicioC;
            while(dia >= aux->dia && aux->siguiente!=NULL){
                atras = aux;
                aux = aux->siguiente;
            }
            if(dia >= aux->dia){
                aux->siguiente = nuevo;
                nuevo->anterior = aux;
            }
            else{
                nuevo->siguiente = aux;
                aux->anterior = nuevo;
                atras->siguiente = nuevo;
                nuevo->anterior = atras;
            }
        }
    return nuevo;
    }
}

nodo_F *MatrizOrtogonal::insertarFila(int inicio, int fin){
 if(estaVacioF()){
        nodo_F *nuevo = crearFila(inicio,fin);
        inicioF = nuevo;
        inicioF->siguiente = inicioF->anterior = NULL;
        inicioF->mat = NULL;
        return nuevo;
    }
    else{
        nodo_F *aux = buscarF(inicio,fin);
        if(aux !=NULL ) return aux;

        nodo_F *nuevo = crearFila(inicio,fin);
        nuevo->mat = NULL;
        if(inicio < inicioF->horaInicio){
            nuevo->siguiente = inicioF;
            inicioF->anterior = nuevo;
            inicioF = nuevo;
        }
        else{
            nodo_F *atras = inicioF;
            aux = inicioF;
            while(inicio >= aux->horaInicio && aux->siguiente!=NULL){
                atras = aux;
                aux = aux->siguiente;
            }
            if(inicio >= aux->horaInicio){
                aux->siguiente = nuevo;
                nuevo->anterior = aux;
            }
            else{
                nuevo->siguiente = aux;
                aux->anterior = nuevo;
                atras->siguiente = nuevo;
                nuevo->anterior = atras;
            }
        }
    return nuevo;
    }
}

nodo_M *MatrizOrtogonal::insertarNodo_F(int inicio,int fin, nodo_M *nodo){
    nodo_F *nuevo = insertarFila(inicio,fin);
    if(nuevo->mat == NULL ) nuevo->mat = nodo;
    else{
        nodo_M *temp = nuevo->mat;
        if(nodo->dia < temp->dia){
            nodo->siguiente = temp;
            temp->anterior = nodo;
            nuevo->mat = nodo;
            return nuevo->mat;
        }
        while(temp->siguiente!=NULL && nodo->dia > temp->dia){
            temp = temp->siguiente;
        }
        if(nodo->dia > temp->dia){
            nodo->siguiente = NULL;
            nodo->anterior = temp;
            temp->siguiente = nodo;
        }
        else{
            nodo_M *ant = temp->anterior;
            ant->siguiente = nodo;
            nodo->anterior = ant;
            temp->anterior = nodo;
            nodo->siguiente = temp;
        }
    }
    return nuevo->mat;
}

nodo_M *MatrizOrtogonal::insertarNodo_C(int dia, std::string nombre, nodo_M *nodo){
    nodo_C *nuevo = insertarColumna(dia,nombre);
    if(nuevo->mat ==NULL) nuevo->mat = nodo;
    else{
        nodo_M *temp = nuevo->mat;
        if(nodo->horaI <= temp->horaI){
            nodo->abajo = temp;
            temp->arriba = nodo;
            nuevo->mat = nodo;
            return nuevo->mat;
        }
        while(temp->abajo!=NULL && nodo->horaI > temp->horaI){
            temp = temp->abajo;
        }
        if(nodo->horaI > temp->horaI){
            nodo->abajo = NULL;
            nodo->arriba = temp;
            temp->abajo = nodo;

        }
        else{
            nodo_M *ant = temp->arriba;
            ant->abajo = nodo;
            nodo->arriba = ant;
            nodo->abajo = temp;
            temp->arriba = nodo;
        }
    }
    return nuevo->mat;
}

nodo_M *MatrizOrtogonal::crearCita(cita c, int dia, int inicio, int fin, std::string nombre){
    nodo_M *nuevo = new nodo_M;
    nuevo->c = c;
    nuevo->dia = dia;
    nuevo->horaF = fin;
    nuevo->horaI = inicio;
    insertarNodo_C(dia,nombre,nuevo);
    insertarNodo_F(inicio,fin,nuevo);
    return nuevo;
}

nodo_M *MatrizOrtogonal::buscarCita(int dia, int inicio, int fin){
    nodo_F *buscar = buscarF(inicio, fin);
    if(buscar!=NULL){
        nodo_M *temp = buscar->mat;
        if(temp->dia == dia) return temp;
        else{
            while(temp!=NULL){
                if(temp->dia == dia) return temp;
                temp = temp->siguiente;
            }
            return NULL;
        }
    }
    return NULL;
}

void MatrizOrtogonal::eliminarCitasUsuario(std::string id){
    if(inicioC!=NULL){
        nodo_C *aux = inicioC;
        while(aux!=NULL){
            nodo_M *temp = aux->mat;
            aux = aux->siguiente;
            while(temp!=NULL){
                if(temp->c.idUsuario == id) {
                    nodo_M* borrar = temp;
                    temp = temp->abajo;
                    eliminar(borrar->dia,borrar->horaI,borrar->horaF,borrar);
                   }
                else{
                    temp = temp->abajo;
                }
            }
        }
    }
}
//

bool MatrizOrtogonal::editar(cita c, int dia, int inicio, int fin){
    nodo_M *editar = buscarCita(dia,inicio,fin);
    if(editar!=NULL){
        editar->c = c;
        return true;
    }
    return false;
}

bool MatrizOrtogonal::eliminar(int dia, int inicio, int fin,nodo_M *eliminar){
    if(eliminar!=NULL){
        nodo_C *col = buscarC(dia);
        nodo_F *fil = buscarF(inicio,fin);
        if(fil->mat == eliminar) fil->mat = eliminar->siguiente;
        if(col->mat == eliminar) col->mat = eliminar->abajo;

        if(eliminar->arriba!=NULL){
            eliminar->arriba->abajo = eliminar->abajo;
        }
        if(eliminar->abajo!=NULL){
            eliminar->abajo->arriba = eliminar->arriba;
        }
        if(eliminar->siguiente!=NULL){
            eliminar->siguiente->anterior = eliminar->anterior;
        }
        if(eliminar->anterior!=NULL){
            eliminar->anterior->siguiente = eliminar->siguiente;
        }
        delete eliminar;
        if(col->mat == NULL) eliminarColumna(dia);
        if(fil->mat == NULL) eliminarFila(inicio,fin);
        return true;
    }
    return false;
}

bool MatrizOrtogonal::eliminar(int dia, int inicio, int fin){
    nodo_M *eliminar = buscarCita(dia,inicio,fin);
    if(eliminar!=NULL){
        nodo_C *col = buscarC(dia);
        nodo_F *fil = buscarF(inicio,fin);
        if(fil->mat == eliminar) fil->mat = eliminar->siguiente;
        if(col->mat == eliminar) col->mat = eliminar->abajo;

        if(eliminar->arriba!=NULL){
            eliminar->arriba->abajo = eliminar->abajo;
        }
        if(eliminar->abajo!=NULL){
            eliminar->abajo->arriba = eliminar->arriba;
        }
        if(eliminar->siguiente!=NULL){
            eliminar->siguiente->anterior = eliminar->anterior;
        }
        if(eliminar->anterior!=NULL){
            eliminar->anterior->siguiente = eliminar->siguiente;
        }
        delete eliminar;
        if(col->mat == NULL) eliminarColumna(dia);
        if(fil->mat == NULL) eliminarFila(inicio,fin);
        return true;
    }
    return false;
}

void MatrizOrtogonal::imprimirNodosColumna(){
    if(inicioC!=NULL){
        nodo_C *aux = inicioC;
        while(aux!=NULL){
            nodo_M *temp = aux->mat;
            while(temp!=NULL){
                std::cout<<"Dato: "<< temp->c.idTratamiento <<" Hora: "<<temp->horaI <<" Dia: "<<temp->dia <<" Usuario: "<<temp->c.idUsuario<<std::endl;
                temp = temp->abajo;
            }
            aux = aux->siguiente;
        }
    }
}

void MatrizOrtogonal::imprimirNodosFila(int dia){
    nodo_C *nodo = buscarC(dia);
    if(nodo!=NULL){
        nodo_M *temp = nodo->mat;
        while(temp!=NULL){
            std::cout<<"Dato: "<< temp->horaI <<" Columna: "<<temp->dia<<std::endl;

            temp = temp->abajo;
        }
    }
    else std::cout<<"La fila no existe"<<std::endl;
}

void MatrizOrtogonal::eliminarFila(int inicio, int fin){
    nodo_F *eliminar = buscarF(inicio, fin);
    if(eliminar!=NULL){
        if(inicioF==eliminar){
            inicioF = inicioF->siguiente;
            eliminar->siguiente=NULL;
            delete eliminar;
        }
        else{
            nodo_F *temp = inicioF;
            while(temp!=NULL && temp!=eliminar){
                temp = temp->siguiente;
            }
            if(temp->siguiente == NULL){
                temp->anterior->siguiente = NULL; temp->anterior=NULL;
                delete temp;
                delete eliminar;
            }
            else{
                nodo_F *ant = temp->anterior;
                ant->siguiente = temp->siguiente;
                temp->siguiente->anterior = ant;
                delete temp;
                delete eliminar;
            }
        }
    }
}

void MatrizOrtogonal::eliminarColumna(int dia){
    nodo_C *eliminar = buscarC(dia);
    if(eliminar!=NULL){
        if(inicioC==eliminar){
            inicioC = inicioC->siguiente;
            eliminar->siguiente=NULL;
            delete eliminar;
        }
        else{
            nodo_C *temp = inicioC;
            while(temp!=NULL && temp!=eliminar){
                temp = temp->siguiente;
            }
            if(temp->siguiente == NULL){
                temp->anterior->siguiente = NULL; temp->anterior=NULL;
                delete temp;
                delete eliminar;
            }
            else{
                nodo_C *ant = temp->anterior;
                ant->siguiente = temp->siguiente;
                temp->siguiente->anterior = ant;
                delete temp;
                delete eliminar;
            }
        }
    }
}

bool MatrizOrtogonal::estaVacia(){
    if(inicioC==NULL || inicioF==NULL) return true;
    return false;
}

