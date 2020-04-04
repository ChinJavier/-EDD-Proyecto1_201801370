#include "NodoMatriz.h"
#include <iostream>
#include <string>
using namespace std;

NodoMatriz::NodoMatriz() {
	this->izquierda = NULL;
	this->derecha = NULL;
	this->arriba = NULL;
	this->abajo = NULL;
	this->ficha = NULL;
	this->xPos = 0;
	this->yPos = 0;
}

NodoMatriz::NodoMatriz(int x, int y, Ficha* c) {
	this->izquierda = NULL;
	this->derecha = NULL;
	this->arriba = NULL;
	this->abajo = NULL;
	this->ficha = c;
	this->xPos = x;
	this->yPos = y;
}

void NodoMatriz::setIzquierda(NodoMatriz* izq) {
	this->izquierda = izq;
}

void NodoMatriz::setDerecha(NodoMatriz* der) {
	this->derecha = der;
}

void NodoMatriz::setArriba(NodoMatriz* arr) {
	this->arriba = arr;
}

void NodoMatriz::setAbajo(NodoMatriz* aba) {
	this->abajo = aba;
}

void NodoMatriz::setX(int x) {
	this->xPos = x;
}

void NodoMatriz::setY(int y) {
	this->yPos = y;
}

void NodoMatriz::setFicha(Ficha* c) {
	this->ficha = c;
}

int NodoMatriz::getX() {
	return this->xPos;
}

int NodoMatriz::getY() {
	return this->yPos;
}

Ficha* NodoMatriz::getFicha() {
	return this->ficha;
}

NodoMatriz* NodoMatriz::getIzquierda() {
	return this->izquierda;
}

NodoMatriz* NodoMatriz::getDerecha() {
	return this->derecha;
}

NodoMatriz* NodoMatriz::getArriba() {
	return this->arriba;
}

NodoMatriz* NodoMatriz::getAbajo() {
	return this->abajo;
}
     
