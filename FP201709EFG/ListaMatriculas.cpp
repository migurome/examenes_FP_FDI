#include "ListaMatriculas.h"

void mostrarMatricula(tListaMatriculas milista) {

	for (int i = 0; i < milista.num_asignaturas_actual; i++) {
		cout << milista.lista[i]->apellidos << endl
			<< milista.lista[i]->nombre << endl
			<< milista.lista[i]->NIF << endl
			<< milista.lista[i]->estudios << endl 
			<< endl << "Asignaturas:" << endl;
			

			mostrarAsignaturas(milista.lista[i]->lista);
			cout << "---------------------------" << endl;
	}

}

bool cargarMatriculas(tListaMatriculas & milista) {

	bool apertura;
	ifstream entrada;
	int num_matriculas;

	entrada.open("matriculas.txt");

	if (apertura = entrada.is_open() == true) {

		milista.num_asignaturas_actual = 0;
		entrada >> num_matriculas;
		entrada.ignore();
		for (int i = 0; i < num_matriculas; i++) {

			milista.lista[i] = new tMatricula;
			getline(entrada, milista.lista[i]->apellidos);
			getline(entrada, milista.lista[i]->nombre);
			getline(entrada, milista.lista[i]->NIF);
			getline(entrada, milista.lista[i]->estudios);
			cargarAsignaturas(milista.lista[i]->lista, entrada);
			
			milista.num_asignaturas_actual++;
		}

	}

	return apertura;
}

void liberar(tListaMatriculas & milista){

	for (int i = 0; i < milista.num_asignaturas_actual; i++) {
		delete milista.lista[i];
		milista.lista[i] = nullptr;
	}
	
	milista.num_asignaturas_actual = 0;


}

int seleccionarMatricula(tListaMatriculas milista) {

	int posicion = 0;

	mostrarMatricula(milista);

	do{
		cout << "Introduce una matricula de la lista: ";
		cin >> posicion;
	} while (posicion < 0 || posicion >= milista.num_asignaturas_actual);

	return posicion;
}