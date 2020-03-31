#pragma once
#include <string>
#include <iostream>
#include "Ficha.h"
using namespace std;

class NodoDobleEnl
{
private:
    Ficha* ficha;
    NodoDobleEnl* siguiente;
    NodoDobleEnl* anterior;

public:
    NodoDobleEnl();
    NodoDobleEnl(Ficha*);

    void setFicha(Ficha*);
    void setSiguiente(NodoDobleEnl*);
    void setAnterior(NodoDobleEnl*);

    Ficha* getFicha();
    NodoDobleEnl* getSiguiente();
    NodoDobleEnl* getAnterior();
};


