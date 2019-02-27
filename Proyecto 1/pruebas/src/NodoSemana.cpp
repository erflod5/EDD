#include "NodoSemana.h"

NodoSemana::NodoSemana(semana s)
{
    se =s;
    siguiente = NULL;
    mat = new MatrizOrtogonal();
}

NodoSemana::~NodoSemana()
{
    //dtor
}

semana NodoSemana::getSemana(){
    return se;
}

void NodoSemana::setSemana(semana s){
    se = s;
}

NodoSemana *NodoSemana::getSiguiente(){
    return siguiente;
}

void NodoSemana::setSiguiente(NodoSemana *nodo){
    siguiente = nodo;
}

MatrizOrtogonal *NodoSemana::getMat(){
    return mat;
}
