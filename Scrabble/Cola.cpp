#include "Cola.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Cola::Cola() {
	this->cabeza = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void Cola::encolar(Ficha* ficha) {
	NodoCola* nuevo = new NodoCola(ficha);
	if (this->cabeza == NULL)
	{
		this->cabeza = nuevo;
		this->ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
	this->tamanio++;
}

NodoCola* Cola::descolar() {
	NodoCola* devolvedor = this->cabeza;
	if (this->cabeza == NULL && this->ultimo == NULL)
	{
		return NULL;
	}
	else
	{
		
		NodoCola* aux = this->cabeza;
		if (aux == this->ultimo && aux == this->cabeza)
		{
			this->ultimo = NULL;
			this->cabeza = NULL;
		}
		else {
			this->cabeza = this->cabeza->getSiguiente();
			aux->setSiguiente(NULL);
		}
		this->tamanio--;
	}
	return devolvedor;
}

void Cola::graph() {
	ofstream escribe;
	escribe.open("C:\\EDD\\colaFichas.txt", ios::out);
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

	NodoCola* aux = this->cabeza;


	while (aux != NULL)
	{
		if (this->tamanio == 1)
		{
			acumulador2 += aux->getFicha()->getCaracter() + to_string(aux->getFicha()->getPuntaje()) + "_" +to_string(indice) + "-> NULL ;";
		}
		else
		{
			if (aux->getSiguiente() == NULL)
			{

			}
			else
			{
				acumulador2 += aux->getFicha()->getCaracter() + to_string(aux->getFicha()->getPuntaje()) + "_" + to_string(indice) + "->" + aux->getSiguiente()->getFicha()->getCaracter() + to_string(aux->getSiguiente()->getFicha()->getPuntaje()) + "_" + to_string(indice2) + ";";
				indice++;
				indice2++;
			}

		}
		aux = aux->getSiguiente();

	}



	acumulador += acumulador2 + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\colaFichas.txt -o C:\\EDD\\colaFichas.jpg";
	system(g);
	char e[] = "C:\\EDD\\colaFichas.jpg";
	system(e);
	system("pause");
}

void Cola::vaciar() {
	this->cabeza = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}

void Cola::setTamanio(int tamanio) {
	this->tamanio = tamanio;
}

NodoCola* Cola::getCabeza() {
	return this->cabeza;
}

NodoCola* Cola::getUltimo() {
	return this->ultimo;
}

int Cola::getTamanio() {
	return this->tamanio;
}
