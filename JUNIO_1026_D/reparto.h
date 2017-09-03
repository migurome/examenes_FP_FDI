#ifndef REPARTO_H
#define REPARTO_H
#include <string>
using namespace std;

const int MAX_ACTORES = 10;

struct tReparto {

	string lista[MAX_ACTORES];
	int contador;
};

void cargarReparto(ifstream &fichero, tReparto &reparto);
bool apareceReparto(tReparto reparto, string nombre, int pos);


#endif