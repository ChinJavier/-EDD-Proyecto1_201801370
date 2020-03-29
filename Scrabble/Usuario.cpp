#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

Usuario::Usuario() {
	this->nombre = "";
	this->puntaje = 0;
}

Usuario::Usuario(string nombre) {
	this->nombre = nombre;
	this->puntaje = 0;
}

void Usuario::setNombre(string nombre) {
	this->nombre = nombre;
}

void Usuario::setPuntaje(int puntaje) {
	this->puntaje = puntaje;
}

string Usuario::getNombre() {
	return this->nombre;
}

int Usuario::getPuntaje() {
	return this->puntaje;
}

ListaDobleEnl& Usuario::getBaraja() {
	return this->baraja;
}
ListaOrdenada& Usuario::getScoreboard() {
	return this->scoreboard;
}
