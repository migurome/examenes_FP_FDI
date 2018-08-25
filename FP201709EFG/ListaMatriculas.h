#include "ListaAsignaturas.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_MATRICULAS = 50;

typedef struct{

	string apellidos;
	string nombre;
	string NIF;
	string estudios;
	tListaAsignaturas lista;
	float coste;

}tMatricula;

typedef struct {

	tMatricula *lista[MAX_MATRICULAS];
	int num_asignaturas_actual;

}tListaMatriculas;

void mostrarMatricula(tListaMatriculas milista);
bool cargarMatriculas(tListaMatriculas & milista);
void liberar(tListaMatriculas & milista);
int seleccionarMatricula(tListaMatriculas milista);