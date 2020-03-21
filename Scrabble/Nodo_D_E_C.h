#pragma once
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Nodo_D_E_C
{
private:
    string palabra;
    Nodo_D_E_C* siguiente;
    Nodo_D_E_C* anterior;

public:
    Nodo_D_E_C();
    Nodo_D_E_C(string palabra);

    void setPalabra(string palabra);
    void setSiguiente(Nodo_D_E_C*);
    void setAnterior(Nodo_D_E_C*);

    string getPalabra();
    Nodo_D_E_C* getSiguiente();
    Nodo_D_E_C* getAnterior();

};

