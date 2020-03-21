#pragma once
#include <string>
#include <iostream>
using namespace std;
class NodoOrdenado
{
private:
    int puntaje;
    string nombre;
    NodoOrdenado* siguiente;

public:
    NodoOrdenado();
    NodoOrdenado(string, int);

    void setNombre(string);
    void setPuntaje(int);
    void setSiguiente(NodoOrdenado*);

    string getNombre();
    int getPuntaje();
    NodoOrdenado* getSiguiente();
};


