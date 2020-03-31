#include "ListaSimple.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ListaSimple::ListaSimple() {
	this->ultimo = NULL;
	this->primero = NULL;
	this->tamanio = 0;
}

void ListaSimple::insertar(string nombre) {
	NodoListaSimple* nuevo = new NodoListaSimple(nombre);
	if (this->primero == NULL)
	{
		this->primero = nuevo;
		this->ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
	this->tamanio++;
}

void ListaSimple::graph() {
	ofstream escribe;
	escribe.open("C:\\EDD\\ordenArbol.txt", ios::out);
	if (escribe.fail())
	{
		cout << "*No se pudo abrir el archivo*" << endl;
		system("pause");
		exit(1);
	}

	string diagr = "digraph G ";
	string acumulador = diagr + "{ style = filled; color = lightgrey; node[color = black]; " + '\n';
	string acumulador2 = " ";

	NodoListaSimple* aux = this->primero;


	while (aux != NULL)
	{
		if (this->tamanio == 1)
		{
			acumulador2 += aux->getNombre() + "-> NULL ;";
		}
		else
		{
			if (aux->getSiguiente() == NULL)
			{

			}
			else
			{
				acumulador2 += aux->getNombre() + "->" + aux->getSiguiente()->getNombre() + ";";
			}

		}
		aux = aux->getSiguiente();

	}



	acumulador += acumulador2 + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\ordenArbol.txt -o C:\\EDD\\ordenArbol.jpg";
	system(g);
	char e[] = "C:\\EDD\\ordenArbol.jpg";
	system(e);
	system("pause");
}

void ListaSimple::vaciar() {
	this->primero = NULL;
	this->tamanio = 0;
}

NodoListaSimple* ListaSimple::getPrimero() {
	return this->primero;
}

NodoListaSimple* ListaSimple::getUltimo() {
	return this->ultimo;
}


