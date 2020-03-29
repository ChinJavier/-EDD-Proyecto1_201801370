#include "Ficha.h"
#include <string>
#include <iostream>
using namespace std;

Ficha::Ficha() {
	this->caracter = '_';
	this->puntaje = 0;
}

Ficha::Ficha(char c, int p) {
	this->caracter = c;
	this->puntaje = p;
}

void Ficha::setCaracter(char caracter) {
	this->caracter = caracter;
}

void Ficha::setPuntaje(int puntaje) {
	this->puntaje = puntaje;
}

char Ficha::getCaracter() {
	return this->caracter;
}

int Ficha::getPuntaje() {
	return this->puntaje;
}
