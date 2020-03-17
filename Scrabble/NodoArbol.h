#pragma once
#include <iostream>
#include <string>
using namespace std;
class NodoArbol
{
private:
    NodoArbol* izq;
    NodoArbol* der;
    string jugador;
    int numero;
public:

    NodoArbol();
    NodoArbol(string,int);

    void setIzq(NodoArbol*);
    void setDer(NodoArbol*);
    void setJugador(string);
    void setNumero(int);

    NodoArbol* getIzq();
    NodoArbol* getDer();
    string getJugador();
    int getNumero();

};

