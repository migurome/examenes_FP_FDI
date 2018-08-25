#include "ListaAsignaturas.h"

bool insertarAsignatura(tListaAsignaturas & listado, tAsignatura asignatura) {

	bool insertada = false;

	if (listado.num_asignaturas_cargadas < MAX_ASIGNATURAS) {
		listado.asignaturas[listado.num_asignaturas_cargadas] = asignatura;
		listado.num_asignaturas_cargadas++;
		insertada = true;
	}
	
	return insertada;
}

void mostrarAsignaturas(tListaAsignaturas listado) {

	for (int i = 0; i < listado.num_asignaturas_cargadas; i++) {
		cout << listado.asignaturas[i].codigo << endl
			<< listado.asignaturas[i].nombre << endl
			<< listado.asignaturas[i].creditos << endl;
	}

}

bool cargarAsignaturas(tListaAsignaturas & listado, ifstream & entrada) {

	bool cargado;
	int num_asignaturas;

	if ((cargado = entrada.is_open()) != false) {

		entrada >> num_asignaturas;
		listado.num_asignaturas_cargadas = 0;
		entrada.ignore();


		for (int i = 0; i < num_asignaturas; i++) {

			getline(entrada, listado.asignaturas[i].codigo);
			getline(entrada, listado.asignaturas[i].nombre);
			entrada >> listado.asignaturas[i].creditos;
			entrada.ignore();
			listado.num_asignaturas_cargadas++;
		}
	}

	return cargado;
}