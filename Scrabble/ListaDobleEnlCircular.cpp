#include "ListaDobleEnlCircular.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ListaDobleEnlCircular::ListaDobleEnlCircular() {
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void ListaDobleEnlCircular::insertarFinal(string palabra) {

	Nodo_D_E_C* nuevo = new Nodo_D_E_C(palabra);
	if (ListaDobleEnlCircular::estaVacia())
	{
		this->primero = nuevo;
		this->ultimo = nuevo;
		nuevo->setSiguiente(this->primero);
		nuevo->setAnterior(this->ultimo);
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		ultimo->setSiguiente(this->primero);
		primero->setAnterior(this->ultimo);
	}
	this->tamanio++;
}

bool ListaDobleEnlCircular::encontrarPalabra(string palabra) { //Falta
	
	Nodo_D_E_C* aux = new Nodo_D_E_C();
	aux = this->primero;
	for (int i = 0; i < this->tamanio; i++)
	{
		if (aux->getPalabra().compare(palabra) == 0)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}


bool ListaDobleEnlCircular::estaVacia() {
	if (this->primero == NULL && this->ultimo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ListaDobleEnlCircular::codigoGraph() { //Falta
	ofstream escribe;
	escribe.open("C:\\EDD\\dE.txt", ios::out);
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

	Nodo_D_E_C* aux = this->primero;

	for (int i = 0; i < this->tamanio; i++)
	{
		if (aux->getSiguiente() == this->primero)
		{
			acumulador2 += this->primero->getPalabra() + to_string(0) + "->" + this->ultimo->getPalabra() + to_string(indice) + ";";
			acumulador2 += this->ultimo->getPalabra() + to_string(indice) + "->" + this->primero->getPalabra() + to_string(0) + ";";
		}
		else {
			acumulador2 += aux->getPalabra() + to_string(indice) + "->" + aux->getSiguiente()->getPalabra() + to_string(indice2) + ";";
			acumulador2 += aux->getSiguiente()->getPalabra() + to_string(indice2) + "->" + aux->getPalabra() + to_string(indice) + ";";
			indice++;
			indice2++;
			aux = aux->getSiguiente();
		}
	}





	acumulador += acumulador2 + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\dE.txt -o C:\\EDD\\dE.jpg";
	system(g);
	char e[] = "C:\\EDD\\dE.jpg";
	system(e);
	system("pause");
}

void ListaDobleEnlCircular::imprimirContenido() {
	Nodo_D_E_C* aux = new Nodo_D_E_C();
	aux = this->primero;
	if (ListaDobleEnlCircular::estaVacia())
	{
		cout << "Lista vacia";
	}
	else
	{
		do {
			cout << "***" << aux->getPalabra();
			cout << '\n';
			aux = aux->getSiguiente();
		} while (aux != this->primero);
	}
}

void ListaDobleEnlCircular::eliminarTodo() {
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void ListaDobleEnlCircular::setTamanio(int tamanio) {
	this->tamanio = tamanio;
}

Nodo_D_E_C* ListaDobleEnlCircular::getPrimero() {
	return this->primero;
}

Nodo_D_E_C* ListaDobleEnlCircular::getUltimo() {
	return this->ultimo;
}

int ListaDobleEnlCircular::getTamanio() {
	return this->tamanio;
}













