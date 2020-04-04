#include "ListaOrdenada.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ListaOrdenada::ListaOrdenada() {
	this->primero = NULL;
	this->tamanio = 0;
}

void ListaOrdenada::insertar(string nombre, int puntaje) {
	NodoOrdenado* nodo = new NodoOrdenado(nombre,puntaje);
	NodoOrdenado* aux = this->primero;
	if (this->primero == NULL) { //Lista vacia
		this->primero = nodo;
	}
	else {
		NodoOrdenado* pre = new NodoOrdenado();

		while (aux != NULL && (puntaje < aux->getPuntaje())) { //Hasta encontrar el mayor a puntaje insertado
			pre = aux;
			aux = aux->getSiguiente();
		}

		if (aux == this->primero) { //Inserto al inicio
			nodo->setSiguiente(this->primero);
			this->primero = nodo;
		}
		else if (aux == NULL) { //Insertar al final
			pre->setSiguiente(nodo);
		}
		else { //Inserto "al medio"
			pre->setSiguiente(nodo);
			nodo->setSiguiente(aux);
		}

	}
	this->tamanio++;
}

void ListaOrdenada::graph() {
	ofstream escribe;
	escribe.open("C:\\EDD\\ordenada.txt", ios::out);
	if (escribe.fail())
	{
		cout << "*No se pudo abrir el archivo*" << endl;
		system("pause");
		exit(1);
	}

	string diagr = "digraph G ";
	string acumulador = diagr + "{ style = filled; color = lightgrey; node[color = black]; " + '\n';
	string acumulador2 = " ";
	int indice = 0;
	int indice2 = 1;

	NodoOrdenado* aux = this->primero;


	while (aux != NULL)
	{
		if (this->tamanio == 1)
		{
			acumulador2 += aux->getNombre()  + to_string(aux->getPuntaje()) + "_" + to_string(indice) + "-> NULL ;";
		}
		else
		{
			if (aux->getSiguiente() == NULL)
			{

			}
			else
			{
				acumulador2 += aux->getNombre()  + to_string(aux->getPuntaje()) + "_" + to_string(indice) + "->" + aux->getSiguiente()->getNombre() + to_string(aux->getSiguiente()->getPuntaje()) + "_" + to_string(indice2) + ";";
				indice++;
				indice2++;
			}

		}
		aux = aux->getSiguiente();

	}



	acumulador += acumulador2 + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\ordenada.txt -o C:\\EDD\\ordenada.jpg";
	system(g);
	char e[] = "C:\\EDD\\ordenada.jpg";
	system(e);
	system("pause");
}

void ListaOrdenada::vaciar() {
	this->primero = NULL;
	this->tamanio = 0;
}
NodoOrdenado* ListaOrdenada::getPrimero() {
	return this->primero;
}
