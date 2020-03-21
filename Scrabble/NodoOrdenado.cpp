#include "NodoOrdenado.h"
#include <iostream>
#include <string>

NodoOrdenado::NodoOrdenado() {
	this->nombre = "";
	this->puntaje = 0;
	this->siguiente = NULL;
}

NodoOrdenado::NodoOrdenado(string nombre, int puntaje) {
	this->nombre = nombre;
	this->puntaje = puntaje;
	this->siguiente = NULL;
}

void NodoOrdenado::setNombre(string nombre) {
	this->nombre = nombre;
}

void NodoOrdenado::setPuntaje(int puntaje) {
	this->puntaje = puntaje;
}

void NodoOrdenado::setSiguiente(NodoOrdenado* siguiente) {
	this->siguiente = siguiente;
}

string NodoOrdenado::getNombre() {
	return this->nombre;
}

int NodoOrdenado::getPuntaje() {
	return this->puntaje;
}

NodoOrdenado* NodoOrdenado::getSiguiente() {
	return this->siguiente;
}
