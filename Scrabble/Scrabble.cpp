#include "ListaDobleEnlCircular.h"
#include "ArbolBinarioBus.h"
#include "MatrizDisper.h"
#include "ListaDobleEnl.h"
#include "ListaOrdenada.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include "Menu.h"

#include "/Users/Javier C/Downloads/json.hpp";
using namespace std;
using json = nlohmann::json;

/*
static ArbolBinarioBus arbol;
static MatrizDisper matriz;
static ListaDobleEnl dobleEnlazada;
static ListaOrdenada listaOrdenada;
json juego;
json dimensionJs;
json dobleJs;
json tripleJs;
json diccionarioJs;
int dimension;
int cordenadaX = 0;
int cordenadaY = 0;
string diccionarioF = " ";
void crear(string);*/
static MatrizDisper matriz;
Menu menu;

int main()
{
    menu.menuPrincipal();
    //matriz.insertar(1, 10, 'A');
    //matriz.insertar(11, 0, 'B');
    //matriz.graph();
    return 0;
}


/*
    matriz.insertar(8, 5, 'O');
    matriz.insertar(9,5,'S');
    matriz.insertar(10,5,'O');
    matriz.insertar(10, 4, 'H');
    matriz.insertar(10, 4, 'H');
    matriz.insertar(10, 6, 'L');
    matriz.insertar(10, 7, 'A');
    cout << endl;
    matriz.graph();

    arbol.insertarAbb("Heidy");
    arbol.insertarAbb("Rodrigo");
    arbol.insertarAbb("Carlos");
    arbol.insertarAbb("Antonio");
    arbol.insertarAbb("Eduardo");
    arbol.mostrarArbol(0);
    arbol.preOrder();
    cout << endl;
    arbol.inOrder();
    cout << endl;
    arbol.postOrder();
    cout << endl;
    arbol.graph();
    arbol.insertarAbb("Ximena");
    arbol.insertarAbb("Xamara");
    arbol.insertarAbb("Zulma");
    arbol.graph();
    arbol.graph();
cout << arbol.getRaiz()->getIzq()->getJugador();
string cadena = "HOLA";
cout << cadena << endl;
cout << "**";
string min =  arbol.convertirMinuscula(cadena);
int size = min.length();
for (int i = 0; i < size ; i++)
{
    cout << (int)min.at(i) <<endl;
}
listaDC.insertarFinal("hola");
listaDC.insertarFinal("mundo");
listaDC.insertarFinal("prueba");
listaDC.insertarFinal("edd");
listaDC.insertarFinal("ldc");
if (listaDC.encontrarPalabra("ldc"))
{
    cout << "Encontrado" <<endl;
}
else
{
    cout << "No encontrado";
}
string hola = "holasd";
cout << hola.length();
cout<< hola.at(2);
cout << hola.at(3);
int ascii = 'A';
cout << ascii;

listaDC.codigoGraph();*/