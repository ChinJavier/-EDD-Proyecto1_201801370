#pragma once
#include "NodoArbol.h"
#include <string>
#include <iostream>
using namespace std;
class ArbolBinarioBus
{
private:
	string cadena;
	int numeroArbol;
	NodoArbol* raiz;
	NodoArbol* insertarAbb_rec(NodoArbol*, string);
	void mostrarArbol_rec(NodoArbol*, int);
	void preOrder_rec(NodoArbol*);
	void inOrder_rec(NodoArbol*);
	void postOrder_rec(NodoArbol*);
	void graph_rec(NodoArbol*);

public:

	ArbolBinarioBus();
	void insertarAbb(string);
	void graph();
	string convertirMinuscula(string);
	int compararNombres(string,string);

	void preOrder();
	void inOrder();
	void postOrder();


	void llenarListaPre();
	void llenarListaIn();
	void llenarListaPost();

	void vaciarListaPre();
	void vaciarListaIn();
	void vaciarListaPost();

	void mostrarArbol(int);


};

