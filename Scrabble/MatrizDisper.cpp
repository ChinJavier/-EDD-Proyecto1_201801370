#include "MatrizDisper.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
static int abajo = 0;
static int derecha = 0;
string cadena = "";
string ranker = "";

MatrizDisper::MatrizDisper() {
    this->root = new NodoMatriz(-1,-1, new Ficha('R',0)); //Inicio la raíz fuera de los límites
	this->tamanio = 0;
}

void MatrizDisper::setTamanio(int tamanio) {
	this->tamanio = tamanio;
}

int MatrizDisper::getTamanio() {
	return this->tamanio;
}

NodoMatriz* MatrizDisper::getRoot() {
	return this->root;
}

NodoMatriz* MatrizDisper::buscarFila(int y) { //Veo si existe la fila
	NodoMatriz* temp = new NodoMatriz();
	temp = this->root; //Mi temporal es la raíz
	while (temp != NULL)
	{
		if (temp->getY()==y) //Si existe
		{
			return temp;	//Retorno el temporal
		}
		temp = temp->getAbajo();
	} 
	return NULL;
}

NodoMatriz* MatrizDisper::buscarColumna(int x) { //Veo si existe la columna
	NodoMatriz* temp = new NodoMatriz();
	temp = this->root; //Mi temporal es la raíz
	while (temp != NULL)
	{
		if (temp->getX() == x) //Si existe
		{
			return temp;	//Retorno el temporal
		}
		temp = temp->getDerecha();
	}
	return NULL;
}

NodoMatriz* MatrizDisper::insertarOrdenadoFila(NodoMatriz* nuevo, NodoMatriz* cabezaFil) {
	bool bandera = false;
	NodoMatriz* temp = new NodoMatriz();
	temp = cabezaFil;
	while (true)
	{
		if (temp->getY() == nuevo->getY()) //Solo sobreescribo el temporal
		{
			temp->setX(nuevo->getX());
			temp->getFicha()->setCaracter(nuevo->getFicha()->getCaracter());
			temp->getFicha()->setPuntaje(nuevo->getFicha()->getPuntaje());
			return temp; //Retorno puntero
		}
		else if (temp->getY() > nuevo->getY()) //Al nuevo lo inserto antes que temp
		{
			bandera = true;
			break;
		}
		if (temp->getAbajo() != NULL) //Me permite mover hasta que no sea nulo
		{
			temp = temp->getAbajo();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{
		//Inserto antes de temp
		nuevo->setAbajo(temp);
		temp->getArriba()->setAbajo(nuevo);
		nuevo->setArriba(temp->getArriba());
		temp->setArriba(nuevo);
	}
	else
	{
		temp->setAbajo(nuevo);
		nuevo->setArriba(temp);
	}

	return nuevo;

}

NodoMatriz* MatrizDisper::insertarOrdenadoColumna(NodoMatriz* nuevo, NodoMatriz* cabezaCol) {
	bool bandera = false;
	NodoMatriz* temp = new NodoMatriz();
	temp = cabezaCol;
	while (true)
	{
		if (temp->getX() == nuevo->getX()) //Solo sobreescribo el temporal
		{
			temp->setY(nuevo->getY());
			temp->getFicha()->setCaracter(nuevo->getFicha()->getCaracter());
			temp->getFicha()->setPuntaje(nuevo->getFicha()->getPuntaje());
			return temp; //Retorno puntero
		}
		else if (temp->getX() > nuevo->getX()) //Al nuevo lo inserto antes que temp
		{
			bandera = true;
			break;
		}
		if (temp->getDerecha() != NULL) //Me permite mover hasta que no sea nulo
		{
			temp = temp->getDerecha();
		}
		else //Quiere decir que el que sigue es nulo, nunca cambió la bandera, entonces inserto después de temp
		{
			break;
		}
	}

	if (bandera)
	{
		//Inserto antes de temp
		nuevo->setDerecha(temp);
		temp->getIzquierda()->setDerecha(nuevo);
		nuevo->setIzquierda(temp->getIzquierda());
		temp->setIzquierda(nuevo);
	}
	else 
	{
		temp->setDerecha(nuevo);
		nuevo->setIzquierda(temp);
	}

	return nuevo;

}

NodoMatriz* MatrizDisper::crearFila(int y) {
	NodoMatriz* cabeza_fil = this->root;
	NodoMatriz* fila = MatrizDisper::insertarOrdenadoFila(new NodoMatriz(-1,y, new Ficha('F',0)), cabeza_fil);
	return fila;

}

NodoMatriz* MatrizDisper::crearColumna(int x) {
	NodoMatriz* cabeza_col = this->root;
	NodoMatriz* columna = MatrizDisper::insertarOrdenadoColumna(new NodoMatriz(x,-1, new Ficha('C', 0)), cabeza_col);
	return columna;
}

void MatrizDisper::insertar(int x, int y, Ficha* c) {
	NodoMatriz* nuevo = new NodoMatriz(x,y,c); //Creo nuevo nodo
	NodoMatriz* nodoColumna = MatrizDisper::buscarColumna(x); //Puntero para encontrar si existe o no la columna
	NodoMatriz* nodoFila = MatrizDisper::buscarFila(y); //Puntero para encontrar si existe o no la fila
	//1. Columna no existe y fila no existe
	if (nodoColumna == NULL && nodoFila == NULL)
	{
		//cout << "caso1";
		//Crear columna
		nodoColumna = MatrizDisper::crearColumna(x);
		//Crear fila
		nodoFila = MatrizDisper::crearFila(y);
		//Insertar ordenado columna
		nuevo = MatrizDisper::insertarOrdenadoColumna(nuevo,nodoFila);
		//Insertar ordenado fila
		nuevo = MatrizDisper::insertarOrdenadoFila(nuevo,nodoColumna);
		return;
	}
	//2. Columna no existe y fila existe
	else if (nodoColumna == NULL && nodoFila != NULL)
	{
		//cout << "caso2";
		//Crear columna
		nodoColumna = MatrizDisper::crearColumna(x);
		//Insertar ordenado columna
		nuevo = MatrizDisper::insertarOrdenadoColumna(nuevo, nodoFila);
		//Insertar ordenado fila
		nuevo = MatrizDisper::insertarOrdenadoFila(nuevo, nodoColumna);
		return;
	}
	//3. Columna existe y fila no existe
	else if (nodoColumna != NULL && nodoFila == NULL)
	{
		//cout << "caso3";
		//Crear fila
		nodoFila = MatrizDisper::crearFila(y);
		//Insertar ordenado columna
		nuevo = MatrizDisper::insertarOrdenadoColumna(nuevo, nodoFila);
		//Insertar ordenado fila
		nuevo = MatrizDisper::insertarOrdenadoFila(nuevo, nodoColumna);
	}
	//4. Columna existe y fila existe
	else if (nodoColumna != NULL && nodoFila != NULL)
	{
		//cout << "caso4";
		//Insertar ordenado columna
		nuevo = MatrizDisper::insertarOrdenadoColumna(nuevo, nodoFila);
		//Insertar ordenado fila
		nuevo = MatrizDisper::insertarOrdenadoFila(nuevo, nodoColumna);
	}
	this->tamanio++;
}

void MatrizDisper::graph() {
	ofstream escribe;
	escribe.open("C:\\EDD\\matriz.txt", ios::out);
	if (escribe.fail())
	{
		cout << "*No se pudo abrir el archivo*" << endl;
		system("pause");
		exit(1);
	}

	string diagr = "digraph G ";
	string acumulador = diagr + "{ node[shape = box]" + '\n';
	string acumulador2 = " ";
	bool bandera1 = true;
	bool bandera2 = true;
	NodoMatriz* aux = this->root;
	NodoMatriz* aux2 = this->root;
	NodoMatriz* aux3 = NULL;
	NodoMatriz* aux4 = this->root;
	NodoMatriz* aux5 = this->root;
	NodoMatriz* aux6 = this->root;
	NodoMatriz* aux7 = NULL;
	NodoMatriz* aux8 = this->root;
	NodoMatriz* aux9 = NULL;
	/////////////////////////////////////////////////////////////////// Creo todo los nodos

	while (aux != NULL) // Creo las cabeceras de columnas
	{
		
		if (aux->getX()==-1)
		{

			cadena +=  "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
			ranker += "Raiz ";
		}
		else
		{
			cadena +="C"  + to_string(aux->getX()) + "[ label = \" " + aux->getFicha()->getCaracter() + "_" + to_string(aux->getX()) + "\" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
			ranker += "C" + to_string(aux->getX()) + " ";
		}
		aux = aux->getDerecha();
	}
	

	while (aux2 != NULL) //Creo las cabeceras de Filas y todos los nodos 
	{
		if (aux2->getY() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{
			cadena += "F" + to_string(aux2->getY()) + "[ label = \" " + aux2->getFicha()->getCaracter() +"_" + to_string(aux2->getY()) + "\" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux2->getX()) + " ]; ";
			if (aux2->getDerecha() != NULL)
			{
				aux3 = aux2->getDerecha();
				while (aux3 != NULL)
				{
					cadena += "M" + to_string(aux3->getX()) + to_string(aux3->getY()) + "[ label = \" " + aux3->getFicha()->getCaracter() + "\" , width = 1.5, style = filled, fillcolor = lightskyblue, group = " + to_string(aux3->getX()) + " ]; ";
					aux3 = aux3->getDerecha();
				}
			}
		}
		aux2 = aux2->getAbajo();
	}

	while (aux4 != NULL)
	{
		if (aux4->getX() == -1 && aux4->getY() == -1) //Enlazo Raiz con los nodos de columnas
		{
			cadena += "Raiz -> C" + to_string(aux4->getDerecha()->getX()) + ";";
			cadena += "C" + to_string(aux4->getDerecha()->getX()) + "-> Raiz ;";
		}
		else
		{
			if (aux4->getDerecha()!= NULL)
			{
				cadena += "C" + to_string(aux4->getX()) + "->" + "C" + to_string(aux4->getDerecha()->getX()) + ";";
				cadena += "C" + to_string(aux4->getDerecha()->getX()) + "->" + "C" + to_string(aux4->getX()) + ";";
			}

		}
		aux4 = aux4->getDerecha();
	}
	

	while (aux5 != NULL)
	{
		if (aux5->getX() == -1 && aux5->getY() == -1) //Enlazo Raiz con los nodos de filas
		{
			cadena += "Raiz -> F" + to_string(aux5->getAbajo()->getY()) + ";";
			cadena += "F" + to_string(aux5->getAbajo()->getY()) + "-> Raiz ;";
		}
		else
		{
			if (aux5->getAbajo() != NULL)
			{
				cadena += "F" + to_string(aux5->getY()) + "->" + "F" + to_string(aux5->getAbajo()->getY()) + ";";
				cadena += "F" + to_string(aux5->getAbajo()->getY()) + "->" + "F" + to_string(aux5->getY()) + ";";
			}

		}
		aux5 = aux5->getAbajo();
	}

	cadena += "{rank = same; " + ranker + "};";
	ranker = "";

	while (aux6 != NULL) //Creo las cabeceras de Filas y todos los nodos 
	{
		if (aux6->getY() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{
			if (aux6->getDerecha()!=NULL)
			{
				aux7 = aux6;

					while (aux7 != NULL)
					{
						if (aux7->getX() == -1)
						{
							cadena += "F" + to_string(aux7->getY()) + "->" + "M" + to_string(aux7->getDerecha()->getX()) + to_string(aux7->getDerecha()->getY()) + ";";
							cadena += "M" + to_string(aux7->getDerecha()->getX()) + to_string(aux7->getDerecha()->getY()) + "->" + "F" + to_string(aux7->getY()) + ";";
							ranker += "F" + to_string(aux7->getY()) + " ";
						}
						else if (aux7->getDerecha()!=NULL)
						{
							cadena += "M" + to_string(aux7->getX()) + to_string(aux7->getY()) + "->" + "M" + to_string(aux7->getDerecha()->getX()) + to_string(aux7->getDerecha()->getY()) + ";";
							cadena += "M" + to_string(aux7->getDerecha()->getX()) + to_string(aux7->getDerecha()->getY()) + "->" + "M" + to_string(aux7->getX()) + to_string(aux7->getY()) + ";";
							ranker += "M" + to_string(aux7->getX()) + to_string(aux7->getY()) + " ";
						}
						else 
						{
							ranker += "M" + to_string(aux7->getX()) + to_string(aux7->getY()) + " ";
						}
						aux7 = aux7->getDerecha();
					}
					cadena += "{rank = same; " + ranker + "};";
					ranker = "";
			
			}

		}
		aux6 = aux6->getAbajo();
	}
	
	while (aux8 != NULL) 
	{
		if (aux8->getX() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{

			if (aux8->getAbajo() != NULL)
			{
				aux9 = aux8;

				while (aux9 != NULL)
				{
					if (aux9->getY() == -1)
					{
						cadena += "C" + to_string(aux9->getX()) + "->" + "M" + to_string(aux9->getAbajo()->getX()) + to_string(aux9->getAbajo()->getY()) + ";";
						cadena += "M" + to_string(aux9->getAbajo()->getX()) + to_string(aux9->getAbajo()->getY()) + "->" + "C" + to_string(aux9->getX()) + ";";
					}
					else if (aux9->getAbajo() != NULL)
					{
						cadena += "M" + to_string(aux9->getX()) + to_string(aux9->getY()) + "->" + "M" + to_string(aux9->getAbajo()->getX()) + to_string(aux9->getAbajo()->getY()) + ";";
						cadena += "M" + to_string(aux9->getAbajo()->getX()) + to_string(aux9->getAbajo()->getY()) + "->" + "M" + to_string(aux9->getX()) + to_string(aux9->getY()) + ";";
					}
					aux9 = aux9->getAbajo();
				}

			}

		}
		aux8 = aux8->getDerecha();
	}
	////////////////////////////////////////////////////////////////
	acumulador += cadena + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\matriz.txt -o C:\\EDD\\matriz.jpg";
	system(g);
	char e[] = "C:\\EDD\\matriz.jpg";
	system(e);
	system("pause");

	cadena = "";
} 


void MatrizDisper::graph2() {
	ofstream escribe;
	escribe.open("C:\\EDD\\matrizDos.txt", ios::out);
	if (escribe.fail())
	{
		cout << "*No se pudo abrir el archivo*" << endl;
		system("pause");
		exit(1);
	}

	string diagr = "digraph G ";
	string acumulador = diagr + "{ node[shape = box]" + '\n';
	string acumulador2 = " ";
	bool bandera1 = true;
	bool bandera2 = true;
	NodoMatriz* aux = this->root;
	NodoMatriz* aux2 = this->root;
	NodoMatriz* aux3 = NULL;
	NodoMatriz* aux4 = this->root;
	NodoMatriz* aux5 = this->root;
	NodoMatriz* aux6 = this->root;
	NodoMatriz* aux7 = NULL;
	NodoMatriz* aux8 = this->root;
	NodoMatriz* aux9 = NULL;
	/////////////////////////////////////////////////////////////////// Creo todo los nodos

	while (aux != NULL) // Creo las cabeceras de columnas
	{

		if (aux->getX() == -1)
		{
			cadena += "Raiz[ label = \" root \" , width = 1, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
			ranker += "Raiz ";
		}
		else
		{
			cadena += "C" + to_string(aux->getX()) + "[ label = \" " + aux->getFicha()->getCaracter() + "_" + to_string(aux->getX()) + "\" , width = 1, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
			ranker += "C" + to_string(aux->getX()) + " ";
		}
		aux = aux->getDerecha();
	}


	while (aux2 != NULL) //Creo las cabeceras de Filas y todos los nodos 
	{

		if (aux2->getY() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{
			cadena += "F" + to_string(aux2->getY()) + "[ label = \" " + aux2->getFicha()->getCaracter() + "_" + to_string(aux2->getY()) + "\" , width = 1, style = filled, fillcolor = firebrick1, group = " + to_string(aux2->getX()) + " ]; ";
			if (aux2->getDerecha() != NULL)
			{
				aux3 = aux2->getDerecha();
				while (aux3 != NULL)
				{
					cadena += "M" + to_string(aux3->getX()) + "_"+ to_string(aux3->getY()) + "[ label = \" " + aux3->getFicha()->getCaracter() + "\" , width = 1, style = filled, fillcolor = lightskyblue, group = " + to_string(aux3->getX()) + " ]; ";
					aux3 = aux3->getDerecha();
				}
			}
		}
		aux2 = aux2->getAbajo();
	}

	while (aux4 != NULL)
	{

		if (aux4->getX() == -1 && aux4->getY() == -1) //Enlazo Raiz con los nodos de columnas
		{
			cadena += "Raiz -> C" + to_string(aux4->getDerecha()->getX()) + "[dir=both];";
		}
		else
		{
			if (aux4->getDerecha() != NULL)
			{
				cadena += "C" + to_string(aux4->getX()) + "->" + "C" + to_string(aux4->getDerecha()->getX()) + "[dir=both];";
			}

		}
		aux4 = aux4->getDerecha();
	}


	while (aux5 != NULL)
	{

		if (aux5->getX() == -1 && aux5->getY() == -1) //Enlazo Raiz con los nodos de filas
		{
			cadena += "Raiz -> F" + to_string(aux5->getAbajo()->getY()) + "[dir=both];";
		}
		else
		{
			if (aux5->getAbajo() != NULL)
			{
				cadena += "F" + to_string(aux5->getY()) + "->" + "F" + to_string(aux5->getAbajo()->getY()) + "[dir=both];";
			}

		}
		aux5 = aux5->getAbajo();
	}

	cadena += "{rank = same; " + ranker + "};";
	ranker = "";

	while (aux6 != NULL) //Creo las cabeceras de Filas y todos los nodos 
	{

		if (aux6->getY() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{
			if (aux6->getDerecha() != NULL)
			{
				aux7 = aux6;

				while (aux7 != NULL)
				{
					if (aux7->getX() == -1)
					{
						cadena += "F" + to_string(aux7->getY()) + "->" + "M" + to_string(aux7->getDerecha()->getX()) + "_" + to_string(aux7->getDerecha()->getY()) + "[dir=both];";
						ranker += "F" + to_string(aux7->getY()) + " ";
					}
					else if (aux7->getDerecha() != NULL)
					{
						cadena += "M" + to_string(aux7->getX()) + "_" +to_string(aux7->getY()) + "->" + "M" + to_string(aux7->getDerecha()->getX()) + "_" + to_string(aux7->getDerecha()->getY()) + "[dir=both];";
						ranker += "M" + to_string(aux7->getX()) + "_" + to_string(aux7->getY()) + " ";
					}
					else
					{
						ranker += "M" + to_string(aux7->getX()) + "_" + to_string(aux7->getY()) + " ";
					}
					aux7 = aux7->getDerecha();
				}
				cadena += "{rank = same; " + ranker + "};";
				ranker = "";

			}

		}
		aux6 = aux6->getAbajo();
	}

	while (aux8 != NULL)
	{
		if (aux8->getX() == -1)
		{

			//cadena += "Raiz[ label = \" root \" , width = 1.5, style = filled, fillcolor = firebrick1, group = " + to_string(aux->getX()) + " ]; ";
		}
		else
		{

			if (aux8->getAbajo() != NULL)
			{
				aux9 = aux8;

				while (aux9 != NULL)
				{
					if (aux9->getY() == -1)
					{
						cadena += "C" + to_string(aux9->getX()) + "->" + "M" + to_string(aux9->getAbajo()->getX()) + "_" + to_string(aux9->getAbajo()->getY()) + "[dir=both];";
					}
					else if (aux9->getAbajo() != NULL)
					{
						cadena += "M" + to_string(aux9->getX()) + "_" + to_string(aux9->getY()) + "->" + "M" + to_string(aux9->getAbajo()->getX()) + "_" + to_string(aux9->getAbajo()->getY()) + "[dir=both];";
					}
					aux9 = aux9->getAbajo();
				}

			}

		}
		aux8 = aux8->getDerecha();
	}
	////////////////////////////////////////////////////////////////
	acumulador += cadena + "}";

	escribe << acumulador;
	escribe.close();
	char g[] = "dot -Tjpg C:\\EDD\\matrizDos.txt -o C:\\EDD\\matrizDos.jpg";
	system(g);
	char e[] = "C:\\EDD\\matrizDos.jpg";
	system(e);
	system("pause");

	cadena = "";
}

NodoMatriz* MatrizDisper::retornarBuscador(int x, int y) {
	bool bandera = false;
	NodoMatriz* temp = this->root;
	NodoMatriz* aux2 = new NodoMatriz();
	while (temp != NULL)
	{
		if (temp->getX() == x) //Ya encontré la x
		{
			aux2 = temp;
			while (aux2 != NULL)
			{
				if (aux2->getY() == y)
				{
					return aux2;
				}
				else
				{
					aux2 = aux2->getAbajo();
				}
			}
		}
		else
		{
			temp = temp->getDerecha();
		}
	}
	return NULL;
}

