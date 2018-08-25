#include "Grupo.h"

tGrupo nuevo(string id, int aula) {
	
	tGrupo aux;

	aux.aula = aula;
	aux.id_grupo = id;
	aux.capacidad = 0;
	aux.num_alumnos_grupo = 0;
	aux.grupo_alumnos = new tAlumno[aux.capacidad];

	return aux;
}


int main() {

	tGrupo migrupo;
	tAlumno a;
	tListaMatriculas listado_matriculas;
	tMatricula *matricula;

	cargarMatriculas(listado_matriculas);

	int pos = seleccionarMatricula(listado_matriculas);
	matricula = listado_matriculas.lista[pos];
	migrupo = nuevo("grupo_1", 20);

	a.matricula = matricula;
	a.email = "migurome@ucm.es";

	insertarAlumno(migrupo, a);

	if (buscarAlumno(migrupo, "87654321C") != -1)
		cout << "Encontado" << endl;
	else
		cout << "No encontrado" << endl;

	system("pause");

	return 0;
}

void mostrarGrupo(tGrupo grupo) {

	for (int i = 0; i < grupo.num_alumnos_grupo; i++) {
		
		grupo.grupo_alumnos

	}


}


void insertarAlumno(tGrupo & grupo, tAlumno alumno) {

	if (grupo.num_alumnos_grupo == grupo.capacidad)
		ampliar(grupo);


	grupo.grupo_alumnos[grupo.num_alumnos_grupo] = alumno;
	grupo.num_alumnos_grupo++;

}


void ampliar(tGrupo & grupo) {

	tAlumno *aux = new tAlumno[grupo.capacidad + 1];

	for (int i = 0; i < grupo.num_alumnos_grupo; i++) {
		aux[i] = grupo.grupo_alumnos[i];
	}

	delete[] grupo.grupo_alumnos;
	grupo.grupo_alumnos = aux;
	grupo.capacidad++;
	aux = nullptr;

}


int buscarAlumno(tGrupo grupo, string nif) {	int pos = -1, i = 0;	while (i < grupo.num_alumnos_grupo && grupo.grupo_alumnos[i].matricula->NIF != nif)		i++;	if (i < grupo.num_alumnos_grupo && grupo.grupo_alumnos[i].matricula->NIF == nif)		pos = i;	return pos;}