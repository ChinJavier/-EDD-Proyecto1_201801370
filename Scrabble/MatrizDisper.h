#pragma once
#include "NodoMatriz.h"
#include <iostream>
#include <string>
using namespace std;

class MatrizDisper
{
private:
	NodoMatriz* root;
	int tamanio;

public:

	MatrizDisper();

	void setTamanio(int);

	int getTamanio();
	NodoMatriz* getRoot();

	
	NodoMatriz* buscarFila(int); 
	NodoMatriz* buscarColumna(int);
	
	NodoMatriz* crearFila(int);
	NodoMatriz* crearColumna(int);

	NodoMatriz* insertarOrdenadoFila(NodoMatriz*,NodoMatriz*);
	NodoMatriz* insertarOrdenadoColumna(NodoMatriz*,NodoMatriz*);

	void insertar(int, int, char);

	void graph();



};

