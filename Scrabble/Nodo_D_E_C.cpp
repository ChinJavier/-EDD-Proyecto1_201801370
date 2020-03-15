#include "Nodo_D_E_C.h"
#include <string>
using namespace std;

Nodo_D_E_C::Nodo_D_E_C() {
	this->anterior = NULL;
	this->siguiente = NULL;
};
Nodo_D_E_C::Nodo_D_E_C(string palabra) {
	this->palabra = palabra;
	this->anterior = NULL;
	this->siguiente = NULL;
}

void Nodo_D_E_C::setPalabra(string palabra) {
	this->palabra = palabra;
}

void Nodo_D_E_C::setSiguiente(Nodo_D_E_C* sig) {
	this->siguiente = sig;
}
void Nodo_D_E_C::setAnterior(Nodo_D_E_C* ant) {
	this->anterior = ant;
}

string Nodo_D_E_C::getPalabra() {
	return this->palabra;
}
Nodo_D_E_C* Nodo_D_E_C::getSiguiente() {
	return this->siguiente;
}
Nodo_D_E_C* Nodo_D_E_C::getAnterior() {
	return this->anterior;
}