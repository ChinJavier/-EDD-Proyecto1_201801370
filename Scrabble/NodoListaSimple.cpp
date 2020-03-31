#include "NodoListaSimple.h"
#include <string>
#include <iostream>
using namespace std;

NodoListaSimple::NodoListaSimple() {
    this->nombre = "";
    this->siguiente = NULL;
}

NodoListaSimple::NodoListaSimple(string nombre) {
    this->nombre = nombre;
    this->siguiente = NULL;
}

void NodoListaSimple::setNombre(string nombre) {
    this->nombre = nombre;
}

void NodoListaSimple::setSiguiente(NodoListaSimple* siguiente) {
    this->siguiente = siguiente;
}

string NodoListaSimple::getNombre() {
    return this->nombre;
}

NodoListaSimple* NodoListaSimple::getSiguiente() {
    return this->siguiente;
}
