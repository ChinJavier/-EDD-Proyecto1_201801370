#include "ListaDobleEnlCircular.h"
#include <iostream>
#include <string>
using namespace std;
static ListaDobleEnlCircular listaDC;
int main()
{
    listaDC.insertarFinal("hola");
    listaDC.insertarFinal("mundo");
    listaDC.insertarFinal("prueba");
    listaDC.insertarFinal("edd");
    listaDC.insertarFinal("ldc");
    listaDC.codigoGraph();

    return 0;
}

