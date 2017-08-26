#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int MAX_APUNTES = 500;

struct tFecha {
	int dia;
	int mes;
	int anio;
};

struct tApunte {
	tFecha fecha;
	double importe;
	string concepto;
};

typedef tApunte tCuenta[MAX_APUNTES];

int cargarApuntes(string nombre_fichero, tCuenta &cuenta);
void mostrarCuenta(tCuenta cuenta, int num_apuntes);
double buscaPrimeraNomina(tCuenta cuenta, int num_apuntes);
double gastoMedioLuz(tCuenta cuenta, int num_apuntes, int anio);

int main() {

	tCuenta cuenta;
	int num_apuntes;

	num_apuntes = cargarApuntes("apuntes.txt", cuenta);
	mostrarCuenta(cuenta, num_apuntes);
	cout << "El valor de la primera nomina es: " << buscaPrimeraNomina(cuenta, num_apuntes) << endl;
	cout << "El gasto medio en luz en 2016 ha sido: " << gastoMedioLuz(cuenta, num_apuntes, 2016) << endl;

	system("Pause");

}

int cargarApuntes(string nombre_fichero, tCuenta &cuenta) {

	ifstream file_in;
	int auxiliar, i = 0;

	file_in.open(nombre_fichero);

	if (file_in.is_open()) {
		
		do {
			file_in >> auxiliar;
			if (auxiliar != -1) {
				cuenta[i].fecha.dia = auxiliar;
				file_in >> cuenta[i].fecha.mes;
				file_in >> cuenta[i].fecha.anio;
				file_in >> cuenta[i].importe;
				file_in >> cuenta[i].concepto;
				i++;
			}
		} while (auxiliar != -1);
	}
	else
		cout << "Error en la apertura del fichero";

	return i;
}

void mostrarCuenta(tCuenta cuenta, int num_apuntes) {

	for (int i = 0; i < num_apuntes; i++)
		cout << cuenta[i].fecha.dia << " "
		<< cuenta[i].fecha.mes << " "
		<< cuenta[i].fecha.anio << " "
		<< cuenta[i].importe << " "
		<< cuenta[i].concepto << endl;
	
}

double buscaPrimeraNomina(tCuenta cuenta, int num_apuntes) {

	int i = 0;

	while (cuenta[i].concepto != "Salario")
		i++;

	return cuenta[i].importe;
}

double gastoMedioLuz(tCuenta cuenta, int num_apuntes, int anio) {
	
	int divisor = 0;
	int acumulado = 0;

	for(int i = 0; i < num_apuntes; i++) {
		if (cuenta[i].fecha.anio == anio)
			if (cuenta[i].concepto == "Luz") {
				acumulado += abs(cuenta[i].importe);
				divisor++;
			}
	}


	return acumulado / divisor;
}