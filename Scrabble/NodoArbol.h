#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"
using namespace std;
class NodoArbol
{
private:
    NodoArbol* izq;
    NodoArbol* der;
    Usuario* jugador;
    int numero;
public:

    NodoArbol();
    NodoArbol(Usuario*,int);

    void setIzq(NodoArbol*);
    void setDer(NodoArbol*);
    void setJugador(Usuario*);
    void setNumero(int);

    NodoArbol* getIzq();
    NodoArbol* getDer();
    Usuario* getJugador();
    int getNumero();

};

