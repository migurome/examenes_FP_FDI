#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_INTERVALOS = 5;
enum tTipocliente {particular, PYME, industria};
typedef int tTabla_intervalos[NUM_INTERVALOS][2];


struct tCliente {
	
	string id_contrato;
	double consumo;
	tTipocliente tipo;

};

bool cargarIntervalos(tTabla_intervalos &tabla, ifstream &intervalos);
int buscarIntervalo(tTabla_intervalos tabla, tCliente cliente);
void frecuenciasConsumo(tTabla_intervalos &tabla, tTipocliente tipo);
void mostrarTabla(tTabla_intervalos tabla);

int main() {

	ifstream intervalos;
	tTabla_intervalos tabla;
	tCliente cliente;

	intervalos.open("intervalos.txt");

	if (intervalos.is_open())
		if (cargarIntervalos(tabla, intervalos))
			mostrarTabla(tabla);

	frecuenciasConsumo(tabla, PYME);
	mostrarTabla(tabla);


	system("Pause");


}

void frecuenciasConsumo(tTabla_intervalos &tabla, tTipocliente tipo) {

	ifstream consumos;
	tCliente cliente;
	string cadena;
	bool next_it = true;
	int tipo_aux, i = 0;

	consumos.open("consumos.txt");

	if (consumos.is_open()) {
		
		do {
			consumos >> cliente.consumo;
			consumos >> tipo_aux;
			 
			if (tipo == tipo_aux) {
				i = 0;
				while (cliente.consumo > tabla[i][0])
					i++;
				tabla[i][1]++;
			}

			consumos >> cliente.id_contrato;
			consumos >> cliente.id_contrato;

		} while (cliente.consumo != -1);

	}
	else
		cout << "Error en la apertura del fichero";


}

bool cargarIntervalos(tTabla_intervalos &tabla, ifstream &intervalos) {

	bool carga = true;
	int i = 0;

	do{
		intervalos >> tabla[i][0];
		tabla[i][1] = 0;
		i++;
	}while (tabla[i][0] != -1 && i < NUM_INTERVALOS);

	if (i != NUM_INTERVALOS)
		carga = false;

	return carga;

}

void mostrarTabla(tTabla_intervalos tabla) {

	cout << " Intervalos: " << endl;
	for (int i = 0; i < NUM_INTERVALOS; i++)
		cout << setw(10) << tabla[i][0] << " " << tabla[i][1]  << endl;
		
}

int buscarIntervalo(tTabla_intervalos tabla, tCliente cliente) {
	
	int intervalo = 0;
	int i = 0;

	while (cliente.consumo > tabla[i][0]) {
		intervalo++;
		i++;
	}

	cout << intervalo << endl;

	return intervalo;

}