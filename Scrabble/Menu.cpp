#include "Menu.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "/Users/Javier C/Downloads/json.hpp";
#include "ListaDobleEnlCircular.h"
#include "NodoMatriz.h"
#include "Ficha.h"
#include "Cola.h"
#include <vector>
#include <time.h>
//---------------------------------------------

using namespace std;
using namespace std;
using json = nlohmann::json;

//--------------------------------------------

class Objeto {
public:
	int posX;
	int posY;
	char caracter;
	Objeto(int x,int y, char t) {
		posX = x;
		posY = y;
		caracter = t;
	}
};

//---------------------------------------------

json juego;
json dimensionJs;
json dobleJs;
json tripleJs;
json diccionarioJs;
int dimension;
int cordenadaX = 0;
int cordenadaY = 0;

//---------------------------------------------

static std::vector<Objeto> dobles;
static std::vector<Objeto> triples;
Ficha* monedas[95];
Ficha* desorden[95];

//----------------------------------------------

static ListaDobleEnlCircular listaDC;
static Cola colaFichas;

//---------------------------------------------

int permitidoIniciarJuego = 0;
int opcionMenu = 0;
int opcionReportes = 0;

//---------------------------------------------

void Menu::menuPrincipal() {

	cout << "              *********   *********   *********   *********   *********   *********   ***       *********" <<endl;
	cout << "              *********   *********   ***   ***   ***   ***   *********   *********   ***       *********" << endl;
	cout << "              ***         ***         ***   ***   ***   ***   ***   ***   ***   ***   ***       ***      " << endl;
	cout << "              ***         ***         *********   *********   ***   ***   ***   ***   ***       ***      " << endl;
	cout << "              *********   ***         *********   *********   *********   *********   ***       *********" << endl;
	cout << "              *********   ***         ***  ***    ***   ***   *********   *********   ***       *********" << endl;
	cout << "                    ***   ***         ***  ***    ***   ***   ***   ***   ***   ***   ***       ***      " << endl;
	cout << "                    ***   ***         ***  ***    ***   ***   ***   ***   ***   ***   *******   ***      " << endl;
	cout << "              *********   *********   ***  ***    ***   ***   *********   *********   *******   *********" << endl;
	cout << "              *********   *********   ***  ***    ***   ***   *********   *********   *******   *********" << endl;
	cout << "              ----------------------------------------------------------------------Javier Chin 201801370" << endl;
	cout << endl << endl;
	cout << "              *************************************     SCRABBLE     ************************************" << endl;
	cout << "1) Lectura de archivo " << endl;
	cout << "2) Juego " << endl;
	cout << "3) Reportes " << endl;
	cout << "4) Crear jugador " << endl;
	cout << "5) Salir " << endl;
	cout << "Ingrese la opcion a escoger: ";
	cin >> opcionMenu;

	if (opcionMenu == 1) //Lee archivo
	{
		Menu::leerEntrada();

	}
	else if (opcionMenu == 2) //Inicia el juego
	{
		if (permitidoIniciarJuego == 1) //quiere decir que ya leyó el archivo
		{

		}
		else {
			system("cls");
			cout << "Debe leer un archivo json antes" << endl;
			Menu::menuPrincipal();
		}
	}
	else if (opcionMenu == 3) //Menú reportes
	{
		Menu::menuReportes(0);
	}
	else if (opcionMenu == 4) //Crea jugadores
	{
		system("pause");
		Menu::llenarVector();
		Menu::mezclarVector();
		colaFichas.graph();
	}
	else if (opcionMenu == 5) //Sale de la aplicación
	{
		cout << "HASTA LA PROXIMA" << endl;
		system("pause");
	}
	else  //Mete algo incorrecto
	{
		system("cls");
		cout << "Ingrese una opción correcta" << endl;
		Menu::menuPrincipal();
	}
}

void Menu::leerEntrada() {
	try
	{
		string ruta = "";
		cout << "Ingrese la ruta del json" << endl;
		cin >> ruta;
		std::ifstream file(ruta);
		file >> juego;
		//cout << juego << endl << endl << endl;

		dimensionJs = juego["dimension"]; //Obtengo la dimensión del juego
		dimension = dimensionJs;


		dobleJs = juego["casillas"]["dobles"]; //Obtengo las coordenada x y del doble
		cout << "--> Estas son las dobles: " << endl;
		int d = 0;
		for (const auto cordenada : dobleJs) {
			cordenadaX = cordenada["x"];
			cordenadaY = cordenada["y"];
			cout << "[" << cordenadaX << "," << cordenadaY << "]" << endl;
			NodoMatriz* aux = new NodoMatriz(cordenadaX, cordenadaY, 'd');
			Objeto d(cordenadaX,cordenadaY,'d');
			dobles.push_back(d);
		}

		tripleJs = juego["casillas"]["triples"]; //Obtengo las coordenada x y del triple
		cout << "--> Estas son las triples: " << endl;
		for (const auto cordenada : tripleJs) {
			cordenadaX = cordenada["x"];
			cordenadaY = cordenada["y"];
			cout << "[" << cordenadaX << "," << cordenadaY << "]" << endl;
			Objeto t(cordenadaX, cordenadaY, 't');
			triples.push_back(t);

		}

		diccionarioJs = juego["diccionario"]; //Obtengo las coordenada x y del triple
		cout << "--> Esto es el diccionario: " << endl;
		for (const auto wri : diccionarioJs) {
			listaDC.insertarFinal(wri["palabra"]);
			cout << wri["palabra"];
			cout << endl;
		}
		system("pause");
		permitidoIniciarJuego = 1;
		system("cls");
	}
	catch (const std::exception&)
	{
		system("cls");
		cout << endl;
		cout << "No se ha podido leer la ruta";
		cout << endl;
	}
	Menu::menuPrincipal();

}

void Menu::menuReportes(int deDondeVengo) { //le mando 0
	system("cls");
	cout << "              *************************************    REPORTES     ************************************" << endl << endl;
	cout << "1) Lista doblemente circular DICCIONARIO "<< endl;
	cout << "2) Cola FICHAS DISPONIBLES " << endl;
	cout << "3) Arbol binario de busqueda USUARIOS " << endl;
	cout << "4) PreOrder Arbol binario de busqueda " << endl;
	cout << "5) InOrder Arbol binario de busqueda " << endl;
	cout << "6) PostOrder Arbol binario de busqueda " << endl;
	cout << "7) Lista Odenada HISTORIAL PUNTAJES POR JUGADOR " << endl;
	cout << "8) Lista Ordenada SOCOREBOARD GENERAL" << endl;
	cout << "9) Matriz dispersa TABLERO" << endl;
	cout << "10) Lista doblemente enlazada FICHAS JUGADOR 1" << endl;
	cout << "11) Lista doblemente enlazada FICHAS JUGADOR 2" << endl;
	cout << "Ingrese la opcion a escoger: ";
	cin >> opcionReportes;
	if (opcionReportes == 1)
	{
		if (!listaDC.estaVacia()) {
			listaDC.codigoGraph();
		}
		else {
			cout << "No ha leído ningún archivo";
			if (deDondeVengo == 0)
			{
				Menu::menuPrincipal();
			}
		}
	}
	else if (opcionReportes == 2)
	{

	}
	else if (opcionReportes == 3)
	{

	}
	else if (opcionReportes == 4)
	{

	}
	else if (opcionReportes == 5)
	{

	}
	else if (opcionReportes == 6)
	{

	}
	else if (opcionReportes == 7)
	{

	}
	else if (opcionReportes == 8)
	{

	}
	else if (opcionReportes == 9)
	{

	}
	else if (opcionReportes == 10)
	{

	}
	else if (opcionReportes == 11)
	{

	}
	else {
	
	}	
	

} 

void Menu::llenarVector() {

	// 1 punto
	for (int i = 0; i < 12; i++)			//Las 12 del A
	{
		monedas[i] = new Ficha('A', 1);
	}
	for (int i = 12; i <24 ; i++)		    //Las 12 del E
	{
		monedas[i] = new Ficha('E', 1);   
	}
	for (int i = 24; i < 33; i++)			//Las 9 del O
	{
		monedas[i] = new Ficha('O',1);
 	}
	for (int i = 33; i < 39; i++)			//Las 6 del I
	{
		monedas[i] = new Ficha('I',1);
	}
	for (int i = 39; i < 45; i++)			//Las 6 del S
	{
		monedas[i] = new Ficha('S',1);
	}
	for (int i = 45; i < 50; i++)			//Las 5 del N
	{
		monedas[i] = new Ficha('N', 1);
	}
	for (int i = 50; i < 54; i++)			//Las 4 del L
	{
		monedas[i] = new Ficha('L', 1);
	}
	for (int i = 54; i < 59; i++)			//Las 5 del R
	{
		monedas[i] = new Ficha('R',1);
	}
	for (int i = 59; i < 64; i++)			//Las 5 del U
	{
		monedas[i] = new Ficha('U',1);
	}
	for (int i = 64; i < 68; i++)			//Las 4 del T
	{
		monedas[i] = new Ficha('T',1);
	}

	//2 puntos
	for (int i = 68; i < 73; i++)			//Las 5 del D
	{
		monedas[i] = new Ficha('D', 2);
	}
	for (int i = 73; i < 75; i++)			//Las 2 del G
	{
		monedas[i] = new Ficha('G',2);
	}

	//3 puntos
	for (int i = 75; i < 79; i++)			//Las 4 del C
	{
		monedas[i] = new Ficha('C',3);
	}
	for (int i = 79; i < 81; i++)			//Las 2 del B
	{
		monedas[i] = new Ficha('B',3);
	}
	for (int i = 81; i < 83; i++)			//Las 2 del M
	{
		monedas[i] = new Ficha('M',3);
	}
	for (int i = 83; i < 85; i++)			//Las 2 del P
	{
		monedas[i] = new Ficha('P',3);
	}

	//4puntos
	for (int i = 85; i < 87; i++)			//Las 2 del H
	{
		monedas[i] = new Ficha('H',4);
	}
	monedas[87] = new Ficha('F',4);			//La 1 del F
	monedas[88] = new Ficha('V', 4);		//La 1 del V
	monedas[89] = new Ficha('Y', 4);		//La 1 del Y

	//5 puntos
	monedas[90] = new Ficha('Q', 5);		//La 1 del Q

	//8 puntos
	monedas[91] = new Ficha('J', 8);		//La 1 del J
	monedas[92] = new Ficha('J', 8);		//La 1 del Ñ   PEEERO LA CAMBIE POR OTRA J
	monedas[93] = new Ficha('X', 8);		//La 1 del X
	
	//10 puntos
	monedas[94] = new Ficha('Z', 10);		//La 1 del Z

}

void Menu::mezclarVector() {
	int random = 0;
	int pos = 0;
	int estalibre[95];

	Ficha* aux = new Ficha();
	srand(time(NULL));
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	//variable = 0 + rand() % (sup + 1 -0)
	for (int i = 0; i < 95; i++)
	{
		estalibre[i] = 1;					 //1 es libre
	}
	for (int i = 0; i < 95; i++) {
		pos = 0 + rand() % (94 + 1 - 0);
		while (estalibre[pos] == 0) {		//Encuentro una posición libre
			pos = 0 + rand() % (94 + 1 - 0);
		}
		desorden[pos] = monedas[i];
		estalibre[pos] = 0;					//Ahora ya está ocupado 
	}

	Menu::llenarCola();
}

void Menu::llenarCola() {
	for (const auto fc : desorden) {
		colaFichas.encolar(fc);
	}
}


	
