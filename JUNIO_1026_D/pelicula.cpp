#include "pelicula.h"
#include "reparto.h"
#include <fstream>
#include <iostream>

using namespace std;

void cargarPelicula(ifstream &fichero, tPelicula &pelicula) {

	getline(fichero, pelicula.titulo);
	getline(fichero, pelicula.director);
	getline(fichero, pelicula.genero);
	fichero >> pelicula.valoracion;
	cargarReparto(fichero, pelicula.reparto);
	
}
bool intervienePelicula(tPelicula pelicula, string actor) {

	int i = 0;

	while (i < pelicula.reparto.contador && apareceReparto(pelicula.reparto, actor, i) != true)
		i++;

	return apareceReparto(pelicula.reparto, actor, i);

}

/*
mostrar():	 Dada	 una	 pel�cula	 muestra	 por	 pantalla:	 t�tulo,	 director,	 g�nero	 y
valoraci�n,	como	aparece	en	el	ejemplo	de	ejecuci�n	al	final	del	enunciado.
*/
void mostrarPelicula(tPelicula pelicula) {

	cout << "Director: " << pelicula.director << endl;
	cout << "Genero: " << pelicula.genero << endl;
	cout << "Titulo: " << pelicula.titulo << endl;
	cout << "Valoracion: " << pelicula.valoracion << endl;
	cout << "Reparto " << endl;
	for (int i = 0; i < pelicula.reparto.contador; i++)
		cout << pelicula.reparto.lista[i] << endl;

	cout << endl << endl << endl;
}