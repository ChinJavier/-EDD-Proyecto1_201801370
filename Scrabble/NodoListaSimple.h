#pragma once
#include <string>
#include <iostream>
using namespace std;
class NodoListaSimple
{
private:
    string nombre;
    NodoListaSimple* siguiente;

public:
    NodoListaSimple();
    NodoListaSimple(string);

    void setNombre(string);
    void setSiguiente(NodoListaSimple*);

    string getNombre();
    NodoListaSimple* getSiguiente();
};


