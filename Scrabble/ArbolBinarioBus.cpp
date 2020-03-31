#include "ArbolBinarioBus.h"
#include "ListaSimple.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

static ListaSimple preL;
static ListaSimple inL;
static ListaSimple postL;

ArbolBinarioBus::ArbolBinarioBus() {
	this->raiz = NULL;
    this->cadena = "";
    this->numeroArbol = 0;
}

void ArbolBinarioBus::insertarAbb(Usuario* usuario) {
    this->raiz = this->insertarAbb_rec(this->raiz, usuario);
}

NodoArbol* ArbolBinarioBus::insertarAbb_rec(NodoArbol* root, Usuario* nombre) {
    //Si el árbol está vacio
    if (root == NULL)
    {
        root = new NodoArbol(nombre,this->numeroArbol);
        this->numeroArbol++;
    }
    else if ((this->compararNombres(this->convertirMinuscula(nombre->getNombre()), this->convertirMinuscula(root->getJugador()->getNombre()))) == 2) // La raiz es mayor, me voy a la izq
    {
        //cout << "!!A la izquierda " << nombre << endl;
        root->setIzq(insertarAbb_rec(root->getIzq(), nombre));
    }
    else if ((this->compararNombres(this->convertirMinuscula(nombre->getNombre()), this->convertirMinuscula(root->getJugador()->getNombre()))) == 1) // La raiz es menor, me voy a la der
    {
        //cout << "!!A la derecha " << nombre << endl;
        root->setDer(insertarAbb_rec(root->getDer(), nombre));
    }
    else
    {
        cout << "*****Este jugador ya existe *****";
    }
    return root;
}

void ArbolBinarioBus::mostrarArbol(int cont) {
    ArbolBinarioBus::mostrarArbol_rec(this->raiz, cont);
}

void ArbolBinarioBus::mostrarArbol_rec(NodoArbol* arbol, int cont) {
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        ArbolBinarioBus::mostrarArbol_rec(arbol->getDer(), cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "      ";
        }
        cout << arbol->getJugador() << endl;
        ArbolBinarioBus::mostrarArbol_rec(arbol->getIzq(), cont + 1);

    }
}

void ArbolBinarioBus::preOrder() {
    ArbolBinarioBus::preOrder_rec(this->raiz);
}

void ArbolBinarioBus::preOrder_rec(NodoArbol* raiz) {
    if (raiz != NULL)
    {
        ArbolBinarioBus::llenarListaPre(raiz->getJugador()->getNombre());
        ArbolBinarioBus::preOrder_rec(raiz->getIzq());
        ArbolBinarioBus::preOrder_rec(raiz->getDer());
    }
}

void ArbolBinarioBus::inOrder() {
    ArbolBinarioBus::inOrder_rec(this->raiz);
}

void ArbolBinarioBus::inOrder_rec(NodoArbol* raiz) {
    if (raiz != NULL)
    {
        ArbolBinarioBus::inOrder_rec(raiz->getIzq());
        ArbolBinarioBus::llenarListaIn(raiz->getJugador()->getNombre());
        ArbolBinarioBus::inOrder_rec(raiz->getDer());
    }
}

void ArbolBinarioBus::postOrder() {
    ArbolBinarioBus::postOrder_rec(this->raiz);
}

void ArbolBinarioBus::postOrder_rec(NodoArbol* raiz) {
    if (raiz != NULL)
    {
        ArbolBinarioBus::postOrder_rec(raiz->getIzq());
        ArbolBinarioBus::postOrder_rec(raiz->getDer());
        ArbolBinarioBus::llenarListaPost(raiz->getJugador()->getNombre());
    }
}

void ArbolBinarioBus::preOrderConsola() {
    ArbolBinarioBus::preOrderConsola_rec(this->raiz);
}

void ArbolBinarioBus::preOrderConsola_rec(NodoArbol* raiz) {
    if (raiz != NULL)
    {
        cout << "->" << raiz->getJugador()->getNombre() << endl;
        ArbolBinarioBus::preOrderConsola_rec(raiz->getIzq());
        ArbolBinarioBus::preOrderConsola_rec(raiz->getDer());
    }
}

void ArbolBinarioBus::graph() {

    ofstream escribe;
    escribe.open("C:\\EDD\\arbol.txt", ios::out);
    if (escribe.fail())
    {
        cout << "*No se pudo abrir el archivo*" << endl;
        system("pause");
        exit(1);
    }

    string diagr = "digraph G ";
    string acumulador = diagr + "{ style = filled; color = lightgrey; node[color = black]; " + '\n';
    string acumulador2 = " ";


    ArbolBinarioBus::graph_rec(this->raiz);

    acumulador += this->cadena + "}";

    escribe << acumulador;
    escribe.close();
    char g[] = "dot -Tjpg C:\\EDD\\arbol.txt -o C:\\EDD\\arbol.jpg";
    system(g);
    char e[] = "C:\\EDD\\arbol.jpg";
    system(e);
    system("pause");

    this->cadena = "";

}

void ArbolBinarioBus::graph_rec(NodoArbol* raiz) {
    if (raiz != NULL) {

        this->cadena += "nodo" + to_string(raiz->getNumero()) + "[label=\"" + raiz->getJugador()->getNombre() + "\"];\n";

        graph_rec(raiz->getIzq());
        graph_rec(raiz->getDer());

        if (raiz->getIzq() != NULL) {
           this->cadena += "nodo" + to_string(raiz->getNumero()) + "-> nodo" + to_string(raiz->getIzq()->getNumero()) + ";\n";
        }

        if (raiz->getDer() != NULL) {
            this->cadena += "nodo" + to_string(raiz->getNumero()) + "-> nodo" + to_string(raiz->getDer()->getNumero()) + ";\n";
        }
    }
}

void ArbolBinarioBus::llenarListaPre(string nombre) {
    preL.insertar(nombre);
}

void ArbolBinarioBus::llenarListaIn(string nombre) {
    inL.insertar(nombre);
}

void ArbolBinarioBus::llenarListaPost(string nombre) {
    postL.insertar(nombre);
}

void ArbolBinarioBus::graphPre() {
    preL.graph();
}

void ArbolBinarioBus::graphIn() {
    inL.graph();
}

void ArbolBinarioBus::graphPost() {
    postL.graph();
}

void ArbolBinarioBus::vaciarListaPre() {
    preL.vaciar();
}

void ArbolBinarioBus::vaciarListaIn() {
    inL.vaciar();
}

void ArbolBinarioBus::vaciarListaPost() {
    postL.vaciar();
}

string ArbolBinarioBus::convertirMinuscula(string palabra) {
    int tamanio = palabra.length();
    for (int i = 0; i < tamanio; i++) {
        palabra[i] = tolower(palabra[i]);
    }
    return palabra;
}
 
int ArbolBinarioBus::compararNombres(string n1, string n2) { //0 si son iguales, 1 si la primera es mayor, 2 si la segunda es mayor
    if (n1.compare(n2) == 0)
    {
        return 0;
    }
    else 
    {
        int tamanioMin = 0;
        int tamanio1 = n1.length();
        int tamanio2 = n2.length();
        if (n1>n2) // la cadena n1 es más larga
        {
            tamanioMin = tamanio2;
        }
        else {
            tamanioMin = tamanio1;
        }

        for (int i = 0; i < tamanioMin; i++)
        {
            if ((int)n1[i] == (int)n2[i])
            {
               if (i == tamanioMin-1)
                {
                    if (tamanio1>tamanio2)
                    {
                        return 1;
                    }
                    else {
                        return 2;
                    }
                }
                //Son iguales
            }
            else if ((int)n1[i] > (int)n2[i])
            {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    return 0;
}

NodoArbol* ArbolBinarioBus::buscarAbb(string usuario) {
    return this->buscarAbb_rec(this->raiz, usuario);
}

NodoArbol* ArbolBinarioBus::buscarAbb_rec(NodoArbol* root, string nombre) {
    if (root == NULL)
    {
        cout << "**Usuario ingresado invalido" << endl;
        return NULL;
    }
    else if ((this->compararNombres(this->convertirMinuscula(nombre), this->convertirMinuscula(root->getJugador()->getNombre()))) == 2) // La raiz es mayor, me voy a la izq
    {
        return buscarAbb_rec(root->getIzq(), nombre);
    }
    else if ((this->compararNombres(this->convertirMinuscula(nombre), this->convertirMinuscula(root->getJugador()->getNombre()))) == 1) // La raiz es menor, me voy a la der
    {
        return buscarAbb_rec(root->getDer(), nombre);
    }
    else
    {
        cout << "**Usuario aceptado" << endl;
        return root;
    }

}