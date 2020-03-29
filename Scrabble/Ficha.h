#pragma once
#include <string>
#include <iostream>
using namespace std;
class Ficha
{
private:
	char caracter;
	int puntaje;

public:
	Ficha();
	Ficha(char, int);

	void setCaracter(char);
	void setPuntaje(int);

	char getCaracter();
	int getPuntaje();
};

