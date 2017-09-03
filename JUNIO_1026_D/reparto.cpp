#include "reparto.h"
#include <fstream>
using namespace std;

void cargarReparto(ifstream &fichero, tReparto &reparto) {

	fichero >> reparto.contador;
	fichero.ignore();

	for (int i = 0; i < reparto.contador; i++)
		getline(fichero, reparto.lista[i]);
	
}

bool apareceReparto(tReparto reparto, string nombre, int pos){
	
	return reparto.lista[pos] == nombre;
}