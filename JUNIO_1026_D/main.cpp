#include "ListaPeliculas.h"
#include <fstream>
#include <iostream>

using namespace std;

void main() {


	tListaPeliculas listado;
	ifstream fich_in;

	fich_in.open("peliculas.txt");

	if (fich_in.is_open()) {
		cargarListaPelicula(fich_in, listado);
		mostrarListaPelicula(listado);
	}
	else
		cout << "Error en la apertura del fichero" << endl;

	cout << endl;
	system("Pause");
	

}