#include "NodoDobleEnl.h"
#include <string>
#include <iostream>
using namespace std;

NodoDobleEnl::NodoDobleEnl() {
	this->anterior = NULL;
	this->siguiente = NULL;
	this->caracter = ' ';
}

NodoDobleEnl::NodoDobleEnl(char c) {
	this->anterior = NULL;
	this->siguiente = NULL;
	this->caracter = c;
}

void NodoDobleEnl::setCaracter(char c) {
	this->caracter = c;
}

void NodoDobleEnl::setSiguiente(NodoDobleEnl* sig) {
	this->siguiente = sig;
}

void NodoDobleEnl::setAnterior(NodoDobleEnl* ant) {
	this->anterior = ant;
}

char NodoDobleEnl::getCaracter() {
	return this->caracter;
}

NodoDobleEnl* NodoDobleEnl::getSiguiente() {
	return this->siguiente;
}
NodoDobleEnl* NodoDobleEnl::getAnterior() {
	return this->anterior;
}
