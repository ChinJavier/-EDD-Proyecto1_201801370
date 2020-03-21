#pragma once
#include "NodoDobleEnl.h"
#include <string>
#include <iostream>
using namespace std;
class ListaDobleEnl
{
private:
	NodoDobleEnl* primero;
	NodoDobleEnl* ultimo;
	int tamanio;

public:

	ListaDobleEnl();

	void insertarFinal(char);
	bool buscarCaracter(char);
	bool estaVacia();
	void eliminarTodo();
	void codigoGraph();
	NodoDobleEnl* buscarNodo(char);
	void eliminarNodo(char);

	void setTamanio(int);
	NodoDobleEnl* getPrimero();
	NodoDobleEnl* getUltimo();
	int getTamanio();
};




