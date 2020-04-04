#pragma once
#include <iostream>
#include <string>
#include "Ficha.h"
using namespace std;
class NodoMatriz
{
private:
    NodoMatriz* izquierda;
    NodoMatriz* derecha;
    NodoMatriz* arriba;
    NodoMatriz* abajo;
    Ficha* ficha;
    int xPos;
    int yPos;

public:

    NodoMatriz();
    NodoMatriz(int, int, Ficha*);

    void setIzquierda(NodoMatriz*);
    void setDerecha(NodoMatriz*);
    void setArriba(NodoMatriz*);
    void setAbajo(NodoMatriz*);
    void setX(int);
    void setY(int);
    void setFicha(Ficha*);

    int getX();
    int getY();
    Ficha* getFicha();

    NodoMatriz* getIzquierda();
    NodoMatriz* getDerecha();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();
};


