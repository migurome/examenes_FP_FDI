#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "reparto.h"
using namespace std;

struct tPelicula {

	string titulo;
	string director;
	string genero;
	double valoracion;
	tReparto reparto;

};

void cargarPelicula(ifstream &fichero, tPelicula &pelicula);
bool intervienePelicula(tPelicula pelicula, string actor);
void mostrarPelicula(tPelicula pelicula);

#endif