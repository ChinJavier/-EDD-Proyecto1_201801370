#include "NodoArbol.h"
#include <iostream>
using namespace std;

NodoArbol::NodoArbol() {
	this->der = NULL;
	this->izq = NULL;
	this->jugador = NULL;
	this->numero = 0;
}

NodoArbol::NodoArbol(Usuario* jugador, int numero) {
	this->der = NULL;
	this->izq = NULL;
	this->jugador = jugador;
	this->numero = numero;
}

void NodoArbol::setIzq(NodoArbol* izq) {
	this->izq = izq;
}

void NodoArbol::setDer(NodoArbol* der) {
	this->der = der;
}

void NodoArbol::setJugador(Usuario* jugador) {
	this->jugador = jugador;
}

NodoArbol* NodoArbol::getIzq() {
	return this->izq;
}
NodoArbol* NodoArbol::getDer() {
	return this->der;
}

Usuario* NodoArbol::getJugador() {
	return this->jugador;
}

void NodoArbol::setNumero(int numero) {
	this->numero = numero;
}

int NodoArbol::getNumero() {
	return this->numero;
}