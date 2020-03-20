#pragma once
#include <iostream>
#include <string>
using namespace std;
class NodoMatriz
{
private:
    NodoMatriz* izquierda;
    NodoMatriz* derecha;
    NodoMatriz* arriba;
    NodoMatriz* abajo;
    char caracter;
    int xPos;
    int yPos;

public:

    NodoMatriz();
    NodoMatriz(int, int, char);

    void setIzquierda(NodoMatriz*);
    void setDerecha(NodoMatriz*);
    void setArriba(NodoMatriz*);
    void setAbajo(NodoMatriz*);
    void setX(int);
    void setY(int);
    void setCaracter(char);

    int getX();
    int getY();
    char getCaracter();

    NodoMatriz* getIzquierda();
    NodoMatriz* getDerecha();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();
};


