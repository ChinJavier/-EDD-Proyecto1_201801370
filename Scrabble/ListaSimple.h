#pragma once
#include <iostream>
#include <string>
#include "NodoListaSimple.h"
using namespace std;
class ListaSimple
{
private:
	NodoListaSimple* primero;
	NodoListaSimple* ultimo;
	int tamanio;

public:
	ListaSimple();
	void insertar(string);
	void graph();
	void vaciar();
	NodoListaSimple* getPrimero();
	NodoListaSimple* getUltimo();

};

