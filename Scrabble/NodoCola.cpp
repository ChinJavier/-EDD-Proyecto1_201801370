#include "NodoCola.h"

#include <string>
#include <iostream>
using namespace std;

NodoCola::NodoCola() {
    this->ficha = NULL;
    this->siguiente = NULL;
}

NodoCola::NodoCola(Ficha* ficha) {
    this->ficha = ficha;
    this->siguiente = NULL;
}

void NodoCola::setFicha(Ficha* ficha) {
    this->ficha = ficha;
}

void NodoCola::setSiguiente(NodoCola* siguiente) {
    this->siguiente = siguiente;
}

Ficha* NodoCola::getFicha() {
    return this->ficha;
}

NodoCola* NodoCola::getSiguiente() {
    return this->siguiente;
}


