#pragma once
#include <string>
#include <iostream>
#include "ListaDobleEnl.h"
#include "ListaOrdenada.h"
using namespace std;
class Usuario
{
private:
	string nombre;
	int puntaje;
	ListaDobleEnl baraja;
	ListaOrdenada scoreboard;

public:
	Usuario();
	Usuario(string);

	void setNombre(string);
	void setPuntaje(int);

	string getNombre();
	int getPuntaje();
	ListaDobleEnl& getBaraja();
	ListaOrdenada& getScoreboard();


};

