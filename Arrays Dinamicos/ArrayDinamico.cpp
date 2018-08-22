
/***
*         _                           ____  _                       _
*        / \   _ __ _ __ __ _ _   _  |  _ \(_)_ __   __ _ _ __ ___ (_) ___ ___
*       / _ \ | '__| '__/ _` | | | | | | | | | '_ \ / _` | '_ ` _ \| |/ __/ _ \
*      / ___ \| |  | | | (_| | |_| | | |_| | | | | | (_| | | | | | | | (_| (_) |
*     /_/   \_\_|  |_|  \__,_|\__, | |____/|_|_| |_|\__,_|_| |_| |_|_|\___\___/
*                             |___/
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


const int NUM_JUGADORES_BASE = 5;

typedef struct {
	string nombre;
	int dorsal;
}tJugador;

typedef struct {
	tJugador *jugadores;
	int tam; // NUM JUGADORES ACTUAL
	int capacidad; //QUE TIENES; Y QUE PUEDES AMPLIAR
}tEquipo;


void nuevoEquipo(tEquipo &team);
void mostrarEquipo(const tEquipo &team);
bool anadirEquipo(const string fichero, tEquipo &team);
void ampliar(tEquipo &team);
void liberar(tEquipo &team);

int main() {

	tEquipo miequipo;

	nuevoEquipo(miequipo);
	anadirEquipo("equipo.txt", miequipo);
	mostrarEquipo(miequipo);
	liberar(miequipo);
	nuevoEquipo(miequipo);
	anadirEquipo("equipo.txt", miequipo);

	system("Pause");
	return 0;
}


bool anadirEquipo(const string fichero, tEquipo &team) {

	ifstream entrada;
	string posicion;
	bool apertura = false;
	entrada.open(fichero);
	int i = 0;

	if (entrada.is_open()) {
		apertura = true;

		while (!entrada.eof()) {
			if (team.tam < team.capacidad) {
				entrada >> team.jugadores[i].nombre;
				entrada >> team.jugadores[i].dorsal;

				team.tam++;
				i++;
			}
			else
				ampliar(team);
		}

		entrada.close();
	}

	return apertura;
}


void nuevoEquipo(tEquipo &team) {
	team.tam = 0;
	team.capacidad = NUM_JUGADORES_BASE;
	team.jugadores = new tJugador[team.capacidad];
}

void mostrarEquipo(const tEquipo &team) {

	for (int i = 0; i < team.tam; i++)
		cout << team.jugadores[i].nombre << " " << team.jugadores[i].dorsal << " "  << endl;

}

void ampliar(tEquipo &team) {

	tJugador *aux = new tJugador[team.capacidad + 1];

	for (int i = 0; i < team.tam; i++) {
		aux[i] = team.jugadores[i];
	}

	delete[] team.jugadores;
	team.jugadores = aux;
	team.capacidad += 1;
	aux = nullptr;

}

void liberar(tEquipo &team){
	team.tam = 0;
	team.capacidad = 0;
	delete[] team.jugadores;
	team.jugadores = nullptr;
}
