#pragma once
#include <iostream>
#include <string>
#include "NodoOrdenado.h"
using namespace std;
class ListaOrdenada
{
private:
	NodoOrdenado* primero;
	int tamanio;

public:
	ListaOrdenada();
	void insertar(string,int);
	void graph();
	void vaciar();
	NodoOrdenado* getPrimero();
};

