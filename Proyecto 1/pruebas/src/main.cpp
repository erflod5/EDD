#include <stdio.h>
#include <iostream>
#include "ListaYears.h"
#include "ListaUsuarios.h"
#include "ListaTratamiento.h"
#include "ListaSesiones.h"


int main(){
    /*MatrizOrtogonal *mat = new MatrizOrtogonal();
    cita c; c.idTratamiento = "123"; c.idUsuario = "123"; c.estado = false; c.transaccion = "123";


    mat->crearCita(c,5,12,13,"Martes");
    mat->crearCita(c,5,4,6,"Martes");
    mat->crearCita(c,6,10,11,"Miercoles");
    mat->crearCita(c,8,7,9,"Viernes");
    mat->crearCita(c,8,10,11,"Lunes");
    mat->crearCita(c,5,10,11,"Martes");

    c.idTratamiento = "nuevo";
    mat->editar(c,8,10,11);

    mat->eliminar(6,10,11);
    mat->imprimirNodosColumna();

  //  mat->imprimirNodosFila(5);


    cita c; c.idTratamiento = "123"; c.idUsuario = "123"; c.estado = false; c.transaccion = "123";
    MatrizOrtogonal *mat = lista->getMatriz(s);
    mat->crearCita(c,5,12,13,"Martes");
    mat->crearCita(c,5,4,6,"Martes");
    mat->crearCita(c,6,10,11,"Miercoles");
    mat->crearCita(c,8,7,9,"Viernes");
    mat->crearCita(c,8,10,11,"Lunes");
    mat->crearCita(c,5,10,11,"Martes");

    c.idTratamiento = "nuevo";
    mat->editar(c,8,10,11);

    mat->eliminar(6,10,11);
    mat->imprimirNodosColumna();

    mes m; m.mes = "Enero"; m.num=1;

    ListaMes *lista = new ListaMes();
    lista->insertar(m); m.num =3;
    lista->insertar(m); m.num = 12;
    lista->insertar(m); m.num = 7;
    lista->insertar(m); m.num = 9;
    lista->insertar(m); m.num = 8;
    lista->insertar(m); m.num = 2;
    lista->insertar(m);


    lista->eliminar(1);
    lista->eliminar(12);
    lista->eliminar(8);
    lista->eliminar(1);
    lista->eliminar(9);
    lista->eliminar(3);
    lista->eliminar(2);
    lista->eliminar(7);
    lista->eliminar(7);
        lista->mostrar();



        semana s; s.numero=3; s.inicio=4;

    ListaSemana *lista = new ListaSemana();
    lista->insertar(s); s.numero = 2;
    lista->insertar(s); s.numero = 5;
    lista->insertar(s); s.numero = 1;
    lista->insertar(s); s.numero = 12;
    lista->insertar(s);

    lista->eliminar(s); s.numero=1;
    lista->eliminar(s); s.numero=3;
    lista->eliminar(s); s.numero=5;
    lista->eliminar(s); s.numero=2;
    lista->eliminar(s);
    lista->imprimir();
    */

    ListaYears *lista = new ListaYears();
    //ORTOGONAL
    usuario u; u.user="2883388"; tratamiento t; t.id = "cord";
    cita c; c.idUsuario=u.user; c.idTratamiento=t.id; c.estado = false; c.transaccion="a001";
    int horaI = 10, horaF = 11, dia = 1;
    //semana
    semana s; s.inicio =1; s.fin = 7; s.numero=1;
    //mes
    mes m; m.mes = "Enero"; m.num=1;
    //año
    int anyo = 2018;
    NodoYear *year = lista->insertar(anyo);
    NodoMes *month = year->listM->insertar(m);
    NodoSemana *week = month->lista->insertar(s);

    week->matriz->crearCita(c,dia,horaI,horaF,"Martes");
    week->matriz->crearCita(c,2,horaI,horaF,"Miercoles");
    week->matriz->crearCita(c,3,horaI,horaF,"Jueves");
    //week->matriz->imprimirNodosColumna();

    s.numero = 2; s.inicio = 8, s.fin = 15;
    NodoSemana *week2 = month->lista->insertar(s);

    week2->matriz->crearCita(c,dia,horaI,horaF,"Martes");
    week2->matriz->crearCita(c,2,horaI,horaF,"Miercoles");
    week2->matriz->crearCita(c,3,horaI,horaF,"Jueves");
    usuario u1; u1.user =  "12345"; c.idUsuario = u1.user;
    week2->matriz->crearCita(c,2,9,10,"MIercoles");

    week2->matriz->eliminarCitasUsuario(u1.user);
    week2->matriz->imprimirNodosColumna();

    system("dot -Tpng /home/erik/grafica.dot -o imagen.png ");

    ListaSesiones *listaS = new ListaSesiones();
    NodoSesion*nuevo = listaS->insertar("id1","rol1");
    std::cout<<nuevo->s.token;

return 0;
}
