#pragma once
#include "Nodo_D_E_C.h"
#include <string>
using namespace std;

class ListaDobleEnlCircular
{

private:
	Nodo_D_E_C* primero;
	Nodo_D_E_C* ultimo;
	int tamanio;


public:

	ListaDobleEnlCircular();				 //Constructor

	void insertarFinal(string);				//Utilizado para insertar al teclear
	bool encontrarPalabra(string);			//Utilizado para validar existencia
	Nodo_D_E_C* Buscar(string);			//Utilizado para buscar un nodo
	bool estaVacia();						//Indica si está vacia
	void eliminarTodo();

	void codigoGraph();					//Genera el código para graficar 
	void imprimirContenido();				//Imprime el contenido que tiene mi lista

	void setTamanio(int);
	Nodo_D_E_C* getPrimero();				 //Obtengo el primer nodo
	Nodo_D_E_C* getUltimo();				 //Obtengo el segundo nodo
	int getTamanio();						 //Devuelve el tamaño de mi lista

};

