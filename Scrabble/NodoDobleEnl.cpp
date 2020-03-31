#include "NodoDobleEnl.h"
#include <string>
#include <iostream>
using namespace std;

NodoDobleEnl::NodoDobleEnl() {
	this->anterior = NULL;
	this->siguiente = NULL;
	this->ficha = NULL;
}

NodoDobleEnl::NodoDobleEnl(Ficha* ficha) {
	this->anterior = NULL;
	this->siguiente = NULL;
	this->ficha = ficha;
}

void NodoDobleEnl::setFicha(Ficha* ficha) {
	this->ficha = ficha;
}

void NodoDobleEnl::setSiguiente(NodoDobleEnl* sig) {
	this->siguiente = sig;
}

void NodoDobleEnl::setAnterior(NodoDobleEnl* ant) {
	this->anterior = ant;
}

Ficha* NodoDobleEnl::getFicha() {
	return this->ficha;
}

NodoDobleEnl* NodoDobleEnl::getSiguiente() {
	return this->siguiente;
}
NodoDobleEnl* NodoDobleEnl::getAnterior() {
	return this->anterior;
}
