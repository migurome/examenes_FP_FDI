#include "ListaMatriculas.h"

typedef struct {

	tMatricula *matricula;
	string email;
}tAlumno;


typedef struct{

	tAlumno *grupo_alumnos;
	string id_grupo;
	int aula;
	int capacidad;
	int num_alumnos_grupo;

}tGrupo;

tGrupo nuevo(string id, int aula);
void ampliar(tGrupo & grupo);
void insertarAlumno(tGrupo & grupo, tAlumno alumno);
int buscarAlumno(tGrupo grupo, string nif);
void mostrarGrupo(tGrupo grupo);