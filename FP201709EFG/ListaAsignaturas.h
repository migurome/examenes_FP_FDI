#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_ASIGNATURAS = 3;

typedef struct {
	string codigo;
	string nombre;
	int creditos;
}tAsignatura;

typedef struct {
	tAsignatura asignaturas[MAX_ASIGNATURAS];
	int num_asignaturas_cargadas;
}tListaAsignaturas;

void mostrarAsignaturas(tListaAsignaturas listado);
bool cargarAsignaturas(tListaAsignaturas & listado, ifstream & entrada);
bool insertarAsignatura(tListaAsignaturas & listado, tAsignatura asignatura);