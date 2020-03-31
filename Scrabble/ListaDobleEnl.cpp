#include "ListaDobleEnl.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ListaDobleEnl::ListaDobleEnl() {
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void ListaDobleEnl::insertarFinal(Ficha* c) {
	NodoDobleEnl* nuevo = new NodoDobleEnl(c);
	if (ListaDobleEnl::estaVacia())
	{
		this->primero = nuevo;
		this->ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
	}
	this->tamanio++;
}

bool ListaDobleEnl::buscarCaracter(char c) {
	NodoDobleEnl* aux = new NodoDobleEnl();
	aux = this->primero;
	while (aux != NULL)
	{
		if (aux->getFicha()->getCaracter() == c)
		{
			return true;
		}
		aux = aux->getSiguiente();
	}
	return false;
}

bool ListaDobleEnl::estaVacia() {
	if (this->primero == NULL && this->ultimo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ListaDobleEnl::eliminarTodo() {
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void ListaDobleEnl::codigoGraph() {
	ofstream escribe;
	escribe.open("C:\\EDD\\dobleE.txt", ios::out);
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

	NodoDobleEnl* aux = this->primero;


	while (aux!=NULL)
	{
		if (this->tamanio == 1)
		{
			acumulador2 += aux->getFicha()->getCaracter() + to_string(indice) + "-> NULL ;";
		}
		else 
		{
			if (aux->getSiguiente() == NULL)
			{

			}
			else 
			{
				acumulador2 += aux->getFicha()->getCaracter() + to_string(indice) + "->" + aux->getSiguiente()->getFicha()->getCaracter() + to_string(indice2) + ";";
				acumulador2 += aux->getSiguiente()->getFicha()->getCaracter() + to_string(indice2) + "->" + aux->getFicha()->getCaracter() + to_string(indice) + ";";
				indice++;
				indice2++;
			}

		}
		aux = aux->getSiguiente();

	}



	acumulador += acumulador2 + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\dobleE.txt -o C:\\EDD\\dobleE.jpg";
	system(g);
	char e[] = "C:\\EDD\\dobleE.jpg";
	system(e);
	system("pause");
}

void ListaDobleEnl::setTamanio(int i) {
	this->tamanio = i;
}

NodoDobleEnl* ListaDobleEnl::getPrimero() {
	return this->getPrimero();
}

NodoDobleEnl* ListaDobleEnl::getUltimo() {
	return this->getUltimo();
}

void ListaDobleEnl::eliminarNodo(char c) {
	NodoDobleEnl* auxEliminador = ListaDobleEnl::buscarNodo(c);
	if (auxEliminador == NULL)
	{
		return;
	}
	else 
	{
		if (auxEliminador == this->primero && auxEliminador == this->ultimo) //Solo hay un nodo
		{
			cout << "Elimino el único" << endl;
			ListaDobleEnl::eliminarTodo();
			return;
		}
		else if (auxEliminador == this->primero && auxEliminador != this->ultimo) //Elimino el primero
		{
			cout << "Elimino el primero" << endl;
			this->primero = auxEliminador->getSiguiente();
			this->primero->setAnterior(NULL);
		}
		else if (auxEliminador != this->primero && auxEliminador == this->ultimo) //Elimino el ultimo
		{
			cout << "Elimino el ultimo" << endl;
			this->ultimo = auxEliminador->getAnterior();
			this->ultimo->setSiguiente(NULL);
		}
		else { //Elimino un nodo intermedio
			cout << "Elimino intermedio" << endl;
			auxEliminador->getAnterior()->setSiguiente(auxEliminador->getSiguiente());
			auxEliminador->getSiguiente()->setAnterior(auxEliminador->getAnterior());
			auxEliminador->setAnterior(NULL);
			auxEliminador->setSiguiente(NULL);

		}
		this->tamanio--;
	}
}

NodoDobleEnl* ListaDobleEnl::buscarNodo(char c) {
	NodoDobleEnl* aux = new NodoDobleEnl();
	aux = this->primero;
	while (aux != NULL)
	{
		if (aux->getFicha()->getCaracter() == c)
		{
			return aux;
		}
		aux = aux->getSiguiente();
	}
	return NULL;
}

int ListaDobleEnl::getTamanio() {
	return this->tamanio;
}