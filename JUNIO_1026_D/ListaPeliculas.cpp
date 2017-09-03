#include <fstream>
#include "ListaPeliculas.h"
#include "pelicula.h"

using namespace std;

void cargarListaPelicula(ifstream &fichero, tListaPeliculas &lista_peliculas) {

	fichero >> lista_peliculas.contador;
	fichero.ignore();

	for (int i = 0; i < lista_peliculas.contador; i++) {
		lista_peliculas.lista[i] = new tPelicula;
		cargarPelicula(fichero, *lista_peliculas.lista[i]);
	}

}

tListaPeliculas filtrarActorListaPelicula(const tListaPeliculas &lista_peliculas, string actor) {

	tListaPeliculas nueva_lista; // valor a devolver
	nueva_lista.contador = 0;  // inicialmente no hay películas

	// recorremos la lista de películas
	for (int i = 0; i < lista_peliculas.contador; i++) {
		// si el actor interviene en la película....
		if (intervienePelicula(*lista_peliculas.lista[i], actor)) {
			// añadir el puntero a la lista de salida
			nueva_lista.lista[nueva_lista.contador] = nueva_lista.lista[i];
			nueva_lista.contador++; // una peli más del actor
		}
	}

	return nueva_lista;

}


/*
Dada	una	lista	de	películas,	muestra	la	información	de	cada	una	de	
las	películas,	separadas	por	tres	guiones,	como	aparece	en	el	ejemplo	al	final	del	
enunciado.	
*/


void mostrarListaPelicula(const tListaPeliculas &lista_peliculas) {

	for (int i = 0; i < lista_peliculas.contador; i++)
		mostrarPelicula(*lista_peliculas.lista[i]);

}

void ordenarPorGeneroListaPelicula(tListaPeliculas &lista_peliculas) {

	// ordenación por inserción
	for (int i = 1; i < lista_peliculas.contador; i++) {
		tPelicula *p = lista_peliculas.lista[i];
		// insertar p en el lugar que le corresponda, entre 0 e i.
		int j = i - 1;
		// el lugar de p será j+1, y se encuentra cuando en j hay 
		// un genero <=
		while (j >= 0 && lista_peliculas.lista[j]->genero > p->genero) {
			lista_peliculas.lista[j + 1] = lista_peliculas.lista[j];
			j--;
		}

		lista_peliculas.lista[j + 1] = p;
	}
}

void ordenarPorValoracionListaPelicula(tListaPeliculas &lista_peliculas) {
	
	for (int i = 1; i < lista_peliculas.contador; i++) {
		tPelicula *p = lista_peliculas.lista[i];
		// insertar p en el lugar que le corresponda, entre 0 e i.
		int j = i - 1;
		// el lugar de p será j+1, y se encuentra cuando en j hay 
		// una valoración >=
		while (j >= 0 && lista_peliculas.lista[j] -> valoracion < p ->valoracion) {
			lista_peliculas.lista[j + 1] = lista_peliculas.lista[j];
			j--;
		}
		lista_peliculas.lista[j + 1] = p;
	}

}

void destruirListaPelicula(tListaPeliculas &lista_peliculas) {

	for (int i = 0; i < lista_peliculas.contador; i++)
		delete lista_peliculas.lista[i];

	lista_peliculas.contador = 0;
}