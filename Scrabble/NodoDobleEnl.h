#pragma once
#include <string>
#include <iostream>
using namespace std;

class NodoDobleEnl
{
private:
    char caracter;
    NodoDobleEnl* siguiente;
    NodoDobleEnl* anterior;

public:
    NodoDobleEnl();
    NodoDobleEnl(char);

    void setCaracter(char);
    void setSiguiente(NodoDobleEnl*);
    void setAnterior(NodoDobleEnl*);

    char getCaracter();
    NodoDobleEnl* getSiguiente();
    NodoDobleEnl* getAnterior();
};


