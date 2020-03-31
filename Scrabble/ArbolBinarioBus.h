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
	NodoArbol* insertarAbb_rec(NodoArbol*, Usuario*);

	void mostrarArbol_rec(NodoArbol*, int);
	void preOrder_rec(NodoArbol*);
	void inOrder_rec(NodoArbol*);
	void postOrder_rec(NodoArbol*);
	void preOrderConsola_rec(NodoArbol*);
	void graph_rec(NodoArbol*);
	NodoArbol* buscarAbb_rec(NodoArbol*, string);

public:

	ArbolBinarioBus();
	void insertarAbb(Usuario*);
	void graph();
	string convertirMinuscula(string);
	int compararNombres(string,string);
	NodoArbol* buscarAbb(string);


	void preOrderConsola();

	void preOrder();
	void inOrder();
	void postOrder();


	void llenarListaPre(string);
	void llenarListaIn(string);
	void llenarListaPost(string);

	void graphPre();
	void graphIn();
	void graphPost();

	void vaciarListaPre();
	void vaciarListaIn();
	void vaciarListaPost();

	void mostrarArbol(int);


};

