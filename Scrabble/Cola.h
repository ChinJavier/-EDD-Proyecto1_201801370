#pragma once
#include <string>
#include <iostream>
#include "NodoCola.h"
using namespace std;
class Cola
{
private:
	NodoCola* cabeza;
	NodoCola* ultimo;
	int tamanio;

public:

	Cola();
	void encolar(Ficha*);
	void graph();
	void vaciar();
	void setTamanio(int);
	NodoCola* descolar();
	NodoCola* getCabeza();
	NodoCola* getUltimo();
	int getTamanio();


};
