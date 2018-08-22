/***
*         _                           _____     _    __  _   _
*        / \   _ __ _ __ __ _ _   _  | ____|___| |_ /_/_| |_(_) ___ ___
*       / _ \ | '__| '__/ _` | | | | |  _| / __| __/ _` | __| |/ __/ _ \
*      / ___ \| |  | | | (_| | |_| | | |___\__ \ || (_| | |_| | (_| (_) |
*     /_/   \_\_|  |_|  \__,_|\__, | |_____|___/\__\__,_|\__|_|\___\___/
*                      _      |___/  _             ____  _         __            _
*     __   ____ _ _ __(_) __ _| |__ | | ___  ___  |  _ \(_)_ __   /_/_ _ __ ___ (_) ___ __ _ ___
*     \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __| | | | | | '_ \ / _` | '_ ` _ \| |/ __/ _` / __|
*      \ V / (_| | |  | | (_| | |_) | |  __/\__ \ | |_| | | | | | (_| | | | | | | | (_| (_| \__ \
*       \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/ |____/|_|_| |_|\__,_|_| |_| |_|_|\___\__,_|___/
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



const int NUM_JUGADORES_TOTAL = 11;

typedef struct {
	string nombre;
	int dorsal;
}tJugador;



typedef struct {
	tJugador *jugadores[NUM_JUGADORES_TOTAL];
	int tam;
}tEquipo;




void mostrarEquipo(const tEquipo &team);
bool anadirEquipo(const string fichero, tEquipo &team);
void liberarEquipo(tEquipo & team);

int main() {

	tEquipo los_lunes;

	tJugador *mijugador;

	anadirEquipo("equipo.txt", los_lunes);
	mostrarEquipo(los_lunes);
	liberarEquipo(los_lunes);
	system("pause");
	return 0;
}

bool anadirEquipo(const string fichero, tEquipo & team) {

	ifstream entrada;
	bool apertura = false;

	entrada.open(fichero);

	if (entrada.is_open()) {
		apertura = true;
		team.tam = 0;

		while (!entrada.eof() && team.tam < NUM_JUGADORES_TOTAL) {


			team.jugadores[team.tam] = new tJugador;
			
			entrada >> team.jugadores[team.tam]->nombre;
			entrada >> team.jugadores[team.tam]->dorsal;

			team.tam++;
				
		}

		entrada.close();
	}

	return apertura;
}


void liberarEquipo(tEquipo & team){

	for (int i = 0; i < team.tam; i++)
		delete[] team.jugadores[0];
}

void mostrarEquipo(const tEquipo &team) {

	for (int i = 0; i < team.tam; i++)
		cout << team.jugadores[i]->nombre << " " << team.jugadores[i]->dorsal << " " << endl;

}

