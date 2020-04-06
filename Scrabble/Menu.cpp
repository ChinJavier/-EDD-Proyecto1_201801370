#include "Menu.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "/Users/Javier C/Downloads/json.hpp";
#include "ListaDobleEnlCircular.h"
#include "MatrizDisper.h"
#include "Ficha.h"
#include "Cola.h"
#include "ArbolBinarioBus.h"
#include <vector>
#include <time.h>
//---------------------------------------------

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
int dimensionLimite = 0;

//---------------------------------------------

static std::vector<Objeto> dobles;
static std::vector<Objeto> triples;
Ficha* monedas[95];
Ficha* desorden[95];

//----------------------------------------------

static ListaDobleEnlCircular listaDC;
static Cola colaFichas;
static ArbolBinarioBus arbolJugadores;
static MatrizDisper matrizDisp;
static MatrizDisper matrizFake;
static MatrizDisper vg;
static Cola colaFake;
static ListaOrdenada listaScore;
//---------------------------------------------

int permitidoIniciarJuego = 0;
int opcionMenu = 0;
int opcionReportes = 0;

//---------------------------------------------
NodoArbol* usuario1;
NodoArbol* usuario2;

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

	if (opcionMenu == 1) //Lee archivo YA ESTÁ
	{
		Menu::leerEntrada();
		listaDC.eliminarTodo();

	}

	else if (opcionMenu == 2) //Inicia el juego
	{

		if (permitidoIniciarJuego == 1) //quiere decir que ya leyó el archivo
		{

			/*COPIO LA MATRIZ ORIGINAL EN LA FAKE*/
			NodoMatriz* aux = matrizDisp.getRoot()->getAbajo();
			NodoMatriz* aux2 = matrizDisp.getRoot();
			matrizFake.getRoot()->setAbajo(NULL); //Le pierdo todos los enlaces
			matrizFake.getRoot()->setDerecha(NULL);//Le pierde todos los enlaces

			while (aux != NULL)
			{
				aux2 = aux->getDerecha();
				while (aux2 != NULL)
				{
					matrizFake.insertar(aux2->getX(), aux2->getY(), aux2->getFicha()); //Cabeceras
					aux2 = aux2->getDerecha();
				}
				aux = aux->getAbajo();
			}


			string p1 = "";
			string p2 = "";
			cout << endl;
			cout << "Estos son los jugadores disponibles: " << endl;
			arbolJugadores.preOrderConsola();
			cout << endl;



			do
			{
				cout << "Ingrese el nombre del jugador 1: " << endl;
				cin >> p1;
				usuario1 = arbolJugadores.buscarAbb(p1);
			} while (usuario1 == NULL);

			do
			{
				cout << "Ingrese el nombre del jugador 2: " << endl;
				cin >> p1;
				usuario2 = arbolJugadores.buscarAbb(p1);
			} while (usuario2 == NULL);

			colaFichas.graph();
			//Lleno sus barajas 
			for (int i = 0; i < 7; i++)
			{
				usuario1->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
			}
			for (int i = 0; i < 7; i++)
			{
				usuario2->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
			}
			
			
			usuario1->getJugador()->getBaraja().codigoGraph();
			system("pause");
			usuario2->getJugador()->getBaraja().codigoGraph();
			int turno = rand() % 2 + 1;
			Menu::menuJuego(turno);
		}
		else {
			system("cls");
			cout << "Debe leer un archivo json antes" << endl;
			Menu::menuPrincipal();
		}
	}

	else if (opcionMenu == 3) //Menú reportes
	{
		Menu::menuReportes(0,0);
	}

	else if (opcionMenu == 4) //Crea jugadores YA ESTA
	{
		string nombre = "";
		system("cls");
		cout << "              *************************************   CREAR USUARIOS   ************************************" << endl << endl;
		cout << "Ingrese el nombre del usuario: " << endl;
		cin >> nombre;
		arbolJugadores.insertarAbb(new Usuario(nombre));
		system("cls");
		cout << "Acción realizada con exito" << endl;
		Menu::menuPrincipal();
	}

	else if (opcionMenu == 5) //Sale de la aplicación YA ESTA
	{
		cout << "HASTA LA PROXIMA" << endl;
		system("pause");
	}

	else  //Mete algo incorrecto
	{
		system("cls");
		cout << "Ingrese una opcion correcta" << endl;
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
			matrizDisp.insertar(cordenadaX, cordenadaY, new Ficha('d',0));
			Objeto d(cordenadaX,cordenadaY,'d');
			dobles.push_back(d);
		}

		tripleJs = juego["casillas"]["triples"]; //Obtengo las coordenada x y del triple
		cout << "--> Estas son las triples: " << endl;
		for (const auto cordenada : tripleJs) {
			cordenadaX = cordenada["x"];
			cordenadaY = cordenada["y"];
			cout << "[" << cordenadaX << "," << cordenadaY << "]" << endl;
			matrizDisp.insertar(cordenadaX, cordenadaY, new Ficha('t', 0));
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

void Menu::menuReportes(int deDondeVengo, int quienSoy) { //0 si vengo del principal  1 si vengo del juego
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
	cout << "12) REGRESAR" << endl;
	cout << "Ingrese la opcion a escoger: ";
	cin >> opcionReportes;
	if (opcionReportes == 1)			//Reporte doble circular YA ESTA
	{
		if (!listaDC.estaVacia()) {
			listaDC.codigoGraph();
		}
		else {
			cout << "No ha leido ningun archivo" << endl;
			system("pause");
			system("cls");
		}
		Menu::menuReportes(deDondeVengo,quienSoy);
	}

	else if (opcionReportes == 2)		//Reporte cola YA ESTA
	{
		colaFichas.graph();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 3)  //Reporte árbol YA ESTA
	{
		arbolJugadores.graph();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 4)  //Reporte preorder del árbol YA ESTA
	{
		arbolJugadores.preOrder();
		arbolJugadores.graphPre();
		arbolJugadores.vaciarListaPre();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 5) //Reporte inorder del árbol YA ESTA
	{
		arbolJugadores.inOrder();
		arbolJugadores.graphIn();
		arbolJugadores.vaciarListaIn();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 6)  ///Reporte postorder del árbol YA ESTA
	{
		arbolJugadores.postOrder();
		arbolJugadores.graphPost();
		arbolJugadores.vaciarListaPost();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 7)
	{
		string name = "";
		do
		{
			cout << "Ingrese el nombre del jugador 1: " << endl;
			cin >> name;
			if (arbolJugadores.buscarAbb(name) == NULL)
			{

			}
			else
			{
				arbolJugadores.buscarAbb(name)->getJugador()->getScoreboard().graph();
			}
		} while (arbolJugadores.buscarAbb(name) == NULL);
		Menu::menuReportes(deDondeVengo, quienSoy);
	}
	else if (opcionReportes == 8)
	{
		arbolJugadores.score();
		arbolJugadores.scoreGraph();
		Menu::menuReportes(deDondeVengo, quienSoy);
	}
	else if (opcionReportes == 9)
	{
		matrizDisp.graph2();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 10)
	{
		usuario1->getJugador()->getBaraja().codigoGraph();
		Menu::menuReportes(deDondeVengo,quienSoy);
	}
	else if (opcionReportes == 11)
	{
		usuario2->getJugador()->getBaraja().codigoGraph();
		Menu::menuReportes(deDondeVengo, quienSoy);
	}
	else if (opcionReportes == 12)
	{
		if (deDondeVengo == 0)
		{
			system("cls");
			Menu::menuPrincipal();
		}
		else {
			system("cls");
			Menu::menuJuego(quienSoy);
		}
	}
	else {
		cout << "Ingrese una opcion correcta " << endl;
		system("pause");
		Menu::menuReportes(deDondeVengo,quienSoy);
	
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

void Menu::menuJuego(int turno) {
	int opcionJuego = 0;
	system("cls");
	matrizDisp.graph2();
	cout << "          *************************************   SCRABBLE   ************************************" << endl << endl;
	if (turno == 1) 
	{
		cout << "TURNO JUGADOR 1" << endl;
	}
	else
	{
		cout << "TURNO JUGADOR 2" << endl;
	}	

	cout << "1) Salir " << endl;
	cout << "2) Reportes " << endl;
	cout << "3) Insertar " << endl;
	cout << "4) Intercambiar " << endl;
	cout << "Ingrese la opcion a escoger: ";
	cin >> opcionJuego;
	
	if (opcionJuego  == 1)
	{
		cout << "El jugador 1 obtuvo: " << usuario1->getJugador()->getPuntaje() << endl;
		usuario1->getJugador()->getScoreboard().insertar(usuario1->getJugador()->getNombre(),usuario1->getJugador()->getPuntaje());

		cout << "El jugador 2 obtuvo: " << usuario2->getJugador()->getPuntaje() << endl;
		usuario2->getJugador()->getScoreboard().insertar(usuario2->getJugador()->getNombre(), usuario2->getJugador()->getPuntaje());

		if (usuario1->getJugador()->getPuntaje() >  usuario2->getJugador()->getPuntaje())
		{
			cout << "El ganador es el jugador 1 !!!!" << endl;
		}
		else if (usuario1->getJugador()->getPuntaje() < usuario2->getJugador()->getPuntaje())
		{
			cout << "El ganador es el jugador 2 !!!!" << endl;
		}
		else
		{
			cout << "Empate :o !!!!" << endl;
		}
		usuario1->getJugador()->getBaraja().eliminarTodo();
		usuario1->getJugador()->setPuntaje(0);
		usuario2->getJugador()->getBaraja().eliminarTodo();
		usuario2->getJugador()->setPuntaje(0);
		colaFichas.vaciar();
		matrizDisp.getRoot()->setAbajo(NULL);
		matrizDisp.getRoot()->setDerecha(NULL);
		Menu::mezclarVector();
		system("pause");
		Menu::menuPrincipal();
		//DEBERÍA HACER EL RECUENTO DE PUNTUACIÓN
	}
	else if (opcionJuego == 2)
	{
		Menu::menuReportes(1,turno);
	}
	else if (opcionJuego == 3)
	{
		Menu::game(turno);
	}
	
	//El intercambio con la cola (Solo puedo 1)
	else if (opcionJuego == 4)
	{
		char sustituto;
		cout << "ingrese el caracter de su ficha: " << endl;
		cin >> sustituto;

		if (turno == 1)
		{
			if (usuario1->getJugador()->getBaraja().getTamanio()!=0)
			{
				NodoDobleEnl* sust = usuario1->getJugador()->getBaraja().buscarNodo(sustituto);
				if (sust != NULL)
				{
					cout << "Ficha encontrada " << endl;
					colaFichas.encolar(sust->getFicha());
					usuario1->getJugador()->getBaraja().eliminarNodo(sustituto);
					usuario1->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
				}
				else
				{
					cout << "No se encontró la ficha " << endl;
				}
			}
			else
			{
				cout << "No cuenta con fichas suficientes" << endl;
			}

			system("pause");
		}
		else
		{
			if (usuario2->getJugador()->getBaraja().getTamanio() != 0)
			{
				NodoDobleEnl* sust = usuario2->getJugador()->getBaraja().buscarNodo(sustituto);
				if (sust != NULL)
				{
					cout << "Ficha encontrada " << endl;
					colaFichas.encolar(sust->getFicha());
					usuario2->getJugador()->getBaraja().eliminarNodo(sustituto);
					usuario2->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
				}
				else
				{
					cout << "No se encontró la ficha " << endl;
				}
			}
			else
			{
				cout << "No cuenta con fichas suficientes" << endl;
			}
			system("pause");
		}



		if (turno == 1)
		{
			turno = 2;

		}
		else
		{
			turno = 1;
		}
		Menu::menuJuego(turno);
	} 
	//Le cedo el turno al siguiente jugador
	else if (opcionJuego == 5)
	{
		if (turno == 1)
		{
			turno = 2;
		}
		else
		{
			turno = 1;
		}
		Menu::menuJuego(turno);
	}
	else
	{
		cout << "Opción incorrecta" << endl;
		Menu::menuJuego(turno);
	}

	


}

void Menu::game(int player) {
	dimensionLimite = dimension;
	int vecesAsignacion = 0;
	int inicial = 0;
	bool bandera = true;
	int tamanio = 0;
	char caracterr = ' ';
	int xPo = 0;
	int yPo = 0;
	char horientacion = ' ';
	string diccion = "";
	NodoMatriz* inicio = new NodoMatriz();
	cout << "Ingrese h si ingresara de forma horizontal o v si ingresara de forma vertical " << endl;
	cin >> horientacion;
	cout << "Ingrese el tamanio de su palabra" << endl;
	cin >> tamanio;

	cout << "Recuerde colocar el signo $ para indicar el fin de su turno" << endl;
	cout << "Recuerde que el límite de su tablero es de " << dimensionLimite << endl;
	system("pause");
	while (bandera)
	{
		if (player == 1)
		{
			cout << "Este es tu mazo :" << endl;
			usuario1->getJugador()->getBaraja().codigoGraph();
		}
		else
		{
			cout << "Este es tu mazo :" << endl;
			usuario2->getJugador()->getBaraja().codigoGraph();
		}
		system("cls");
		cout << "Ingrese el caracter en mayuscula" << endl;
		cin >> caracterr;
		if (player == 1)													//Veo si es el jugador 1
		{
			if (caracterr == '$')											//Indica que dejó de teclear
			{
				bandera = false;
			}
			else											                //Recolecto lo que va metiendo
			{
				if (usuario1->getJugador()->getBaraja().buscarCaracter(caracterr)) //Veo si el jugador 1 tiene esa moneda
				{

					do
					{
						cout << "Ingrese coordenada x" << endl;
						cin >> xPo;
					} while (xPo > dimensionLimite);

					do
					{
						cout << "Ingrese coordenada y" << endl;
						cin >> yPo;
					} while (yPo > dimensionLimite);

					colaFake.encolar(usuario1->getJugador()->getBaraja().buscarNodo(caracterr)->getFicha());
					matrizFake.insertar(xPo, yPo, usuario1->getJugador()->getBaraja().buscarNodo(caracterr)->getFicha());
					usuario1->getJugador()->getBaraja().eliminarNodo(caracterr);
					vecesAsignacion++;
					matrizFake.graph2();
					if (inicial == 0)
					{
						inicio = matrizFake.retornarBuscador(xPo, yPo);
						inicial++;
					}

				}
				else
				{
					cout << "No cuentas con esa ficha bro" << endl;
					system("pause");
				}

			}

		}
		else					//Entonces es el jugador 2
		{
			if (caracterr == '$')											//Indica que dejó de teclear
			{
				bandera = false;
			}
			else											                //Recolecto lo que va metiendo
			{
				if (usuario2->getJugador()->getBaraja().buscarCaracter(caracterr)) //Veo si el jugador 1 tiene esa moneda
				{

					do
					{
						cout << "Ingrese coordenada x" << endl;
						cin >> xPo;
					} while (xPo > dimensionLimite);

					do
					{
						cout << "Ingrese coordenada y" << endl;
						cin >> yPo;
					} while (yPo > dimensionLimite);

					colaFake.encolar(usuario2->getJugador()->getBaraja().buscarNodo(caracterr)->getFicha());
					matrizFake.insertar(xPo, yPo, usuario2->getJugador()->getBaraja().buscarNodo(caracterr)->getFicha());
					usuario2->getJugador()->getBaraja().eliminarNodo(caracterr);
					vecesAsignacion++;
					matrizFake.graph2();
					if (inicial == 0)
					{
						inicio = matrizFake.retornarBuscador(xPo, yPo);
						inicial++;
					}

				}
				else
				{
					cout << "No cuentas con esa ficha bro" << endl;
					system("pause");
				}

			}
		}
	}


	// ACA TENGO LA DEL DICCIONARIO Y LA DEL PUNTAJE
	int puntaje = 0;
	bool dobleBoo = false;
	bool tripleBoo = false;
	if (horientacion == 'h')
	{

		for (int i = 0; i < tamanio; i++)
		{
			dobleBoo = false;
			tripleBoo = false;

			diccion += inicio->getFicha()->getCaracter();
			//Veo si tiene el doble
			for (const auto fc : dobles) {
				if (inicio->getX() == fc.posX && inicio->getY() == fc.posY)
				{
					cout << "Puntuacion doble" << endl;
					puntaje += inicio->getFicha()->getPuntaje() * 2;
					dobleBoo = true;
					break;
				}
			}
			//Veo si tiene el triple
			for (const auto fcv : triples) {
				if (inicio->getX() == fcv.posX && inicio->getY() == fcv.posY)
				{
					cout << "Puntuacion triple" << endl;
					puntaje += inicio->getFicha()->getPuntaje() * 3;
					tripleBoo = true;
					break;
				}
			}

			if (dobleBoo == true || tripleBoo == true)
			{

			}
			else
			{
				cout << "Puntuacion simple" << endl;
				puntaje += inicio->getFicha()->getPuntaje();
			}

			cout << inicio->getFicha()->getCaracter() << " con puntaje inicial de " << inicio->getFicha()->getPuntaje() <<endl;
			inicio = inicio->getDerecha();
		}
	}
	else    //Es vertical
	{

		for (int i = 0; i < tamanio; i++)
		{
			dobleBoo = false;
			tripleBoo = false;

			diccion += inicio->getFicha()->getCaracter();

			//Veo si tiene el doble
			for (const auto fc : dobles) {
				if (inicio->getX() == fc.posX && inicio->getY() == fc.posY)
				{
					cout << "Puntuacion doble" << endl;
					puntaje += inicio->getFicha()->getPuntaje() * 2;
					dobleBoo = true;
					break;
				}
			}
			//Veo si tiene el triple
			for (const auto fcv : triples) {
				if (inicio->getX() == fcv.posX && inicio->getY() == fcv.posY)
				{
					cout << "Puntuacion triple" << endl;
					puntaje += inicio->getFicha()->getPuntaje() * 3;
					tripleBoo = true;
					break;
				}
			}
			if (dobleBoo == true || tripleBoo == true)
			{

			}
			else
			{
				cout << "Puntuacion normal" << endl;
				puntaje += inicio->getFicha()->getPuntaje();
			}
			cout << inicio->getFicha()->getCaracter() << " con puntaje de " << inicio->getFicha()->getPuntaje() << endl;
			inicio = inicio->getAbajo();
		}
	}


	cout << diccion << endl;
	if (listaDC.encontrarPalabra(diccion))
	{
		cout << "Palabra encontrada, bien hecho" << endl;
		if (player == 1)
		{
			for (int i = 0; i < vecesAsignacion; i++)
			{
				usuario1->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
			}
			usuario1->getJugador()->setPuntaje((usuario1->getJugador()->getPuntaje())+puntaje);
			cout << "Wow, obtuviste : " << usuario1->getJugador()->getPuntaje() << endl;

			
		}
		else
		{
			for (int i = 0; i < vecesAsignacion; i++)
			{
				usuario2->getJugador()->getBaraja().insertarFinal(colaFichas.descolar()->getFicha());
			}
			usuario2->getJugador()->setPuntaje((usuario2->getJugador()->getPuntaje()) + puntaje);
			cout << "Wow, obtuviste: " << usuario2->getJugador()->getPuntaje() << endl;
		}
		/*COPIO LA FAKE EN LA ORIGINAL*/
		NodoMatriz* aux = matrizFake.getRoot()->getAbajo();
		NodoMatriz* aux2 = matrizFake.getRoot();
		matrizDisp.getRoot()->setAbajo(NULL); //Le pierdo todos los enlaces
		matrizDisp.getRoot()->setDerecha(NULL);//Le pierde todos los enlaces

		while (aux != NULL)
		{
			aux2 = aux->getDerecha();
			while (aux2 != NULL)
			{
				matrizDisp.insertar(aux2->getX(), aux2->getY(), aux2->getFicha()); //Cabeceras
				aux2 = aux2->getDerecha();
			}
			aux = aux->getAbajo();
		}
		system("pause");

	}
	else
	{
		cout << "La palaba no es del diccionario" << endl;
		if (player == 1)
		{
			for (int i = 0; i < vecesAsignacion; i++)
			{
				usuario1->getJugador()->getBaraja().insertarFinal(colaFake.descolar()->getFicha());
			}
		}
		else
		{
			for (int i = 0; i < vecesAsignacion; i++)
			{
				usuario2->getJugador()->getBaraja().insertarFinal(colaFake.descolar()->getFicha());
			}
		}

		/*COPIO LA MATRIZ ORIGINAL EN LA FAKE*/
		NodoMatriz* aux = matrizDisp.getRoot()->getAbajo();
		NodoMatriz* aux2 = matrizDisp.getRoot();
		matrizFake.getRoot()->setAbajo(NULL); //Le pierdo todos los enlaces
		matrizFake.getRoot()->setDerecha(NULL);//Le pierde todos los enlaces

		while (aux != NULL)
		{
			aux2 = aux->getDerecha();
			while (aux2 != NULL)
			{
				matrizFake.insertar(aux2->getX(), aux2->getY(), aux2->getFicha()); //Cabeceras
				aux2 = aux2->getDerecha();
			}
			aux = aux->getAbajo();
		}
		system("pause");
	}

	if (player == 1)
	{
		player = 2;

	}
	else
	{
		player = 1;
	}
	Menu::menuJuego(player);
}
