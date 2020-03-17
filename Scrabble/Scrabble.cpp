#include "ListaDobleEnlCircular.h"
#include "ArbolBinarioBus.h"
#include <iostream>
#include <string>
using namespace std;
static ListaDobleEnlCircular listaDC;
static ArbolBinarioBus arbol;
int main()
{

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

    //cout << arbol.getRaiz()->getIzq()->getJugador();

    /*
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

    return 0;
}

