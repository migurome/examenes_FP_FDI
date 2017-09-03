#ifndef LISTA_PELICULAS_H
#define LISTA_PELICULAS_H
#include "pelicula.h"
#include <string>
using namespace std;

const int MAX_PELICULAS = 50;

struct tListaPeliculas {
	tPelicula *lista[MAX_PELICULAS];
	int contador;
};

void cargarListaPelicula(ifstream &fichero, tListaPeliculas &lista_peliculas);
tListaPeliculas filtrarActorListaPelicula(const tListaPeliculas &lista_peliculas, string actor);
void mostrarListaPelicula(const tListaPeliculas &lista_peliculas);
void ordenarPorGeneroListaPelicula(tListaPeliculas &lista_peliculas);
void ordenarPorValoracionListaPelicula(tListaPeliculas &lista_peliculas);
void destruirListaPelicula(tListaPeliculas &lista_peliculas);

#endif
