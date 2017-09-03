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
	nueva_lista.contador = 0;  // inicialmente no hay pel�culas

	// recorremos la lista de pel�culas
	for (int i = 0; i < lista_peliculas.contador; i++) {
		// si el actor interviene en la pel�cula....
		if (intervienePelicula(*lista_peliculas.lista[i], actor)) {
			// a�adir el puntero a la lista de salida
			nueva_lista.lista[nueva_lista.contador] = nueva_lista.lista[i];
			nueva_lista.contador++; // una peli m�s del actor
		}
	}

	return nueva_lista;

}


/*
Dada	una	lista	de	pel�culas,	muestra	la	informaci�n	de	cada	una	de	
las	pel�culas,	separadas	por	tres	guiones,	como	aparece	en	el	ejemplo	al	final	del	
enunciado.	
*/


void mostrarListaPelicula(const tListaPeliculas &lista_peliculas) {

	for (int i = 0; i < lista_peliculas.contador; i++)
		mostrarPelicula(*lista_peliculas.lista[i]);

}

void ordenarPorGeneroListaPelicula(tListaPeliculas &lista_peliculas) {

	// ordenaci�n por inserci�n
	for (int i = 1; i < lista_peliculas.contador; i++) {
		tPelicula *p = lista_peliculas.lista[i];
		// insertar p en el lugar que le corresponda, entre 0 e i.
		int j = i - 1;
		// el lugar de p ser� j+1, y se encuentra cuando en j hay 
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
		// el lugar de p ser� j+1, y se encuentra cuando en j hay 
		// una valoraci�n >=
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