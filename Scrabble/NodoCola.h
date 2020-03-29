#pragma once
#include <string>
#include <iostream>
#include "Ficha.h"
using namespace std;
class NodoCola
{
private:
    Ficha* ficha;
    NodoCola* siguiente;

public:
    NodoCola();
    NodoCola(Ficha*);

    void setFicha(Ficha*);
    void setSiguiente(NodoCola*);

    Ficha* getFicha();
    NodoCola* getSiguiente();

};


