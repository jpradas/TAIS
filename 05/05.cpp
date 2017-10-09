/*
Grupo: TAIS05
Carlos Fernandez Arranz
Josue Pradas Sacristan
*/

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

//O(N log N), con N sindo igual a el número de equipos
bool resuelveCaso() {
	long long N;					//número N de equipos
	long long numSeguidores;		//número de seguidores de cada equipo
	PriorityQueue<long long> monticulo;	//monticulo donde vamos guardando los numeros d seguidores

	cin >> N;
	if (!cin) {
		return false;
	}

	for (int i = 0; i < N; i++) {	//leemos y vamos introduciendo en el monticulo
		cin >> numSeguidores;
		monticulo.push(numSeguidores);
	}

	long long gorrasTotales = 0;
	long long gorras;

	while (monticulo.size() > 1) {
		gorras = 0;
		gorras = gorras + monticulo.top();		//sumamos a gorras la cima del monticulo
		monticulo.pop();						//sacamos del monticulo la cima
		gorras = gorras + monticulo.top();		//sumamos a gorras la nueva cima (antes subcima)
		monticulo.pop();						//sacamos del monticulo la cima
		monticulo.push(gorras);					//introducimos en el monticulo el valor de gorras
		gorrasTotales = gorrasTotales + gorras;	//actualizamos el valor de gorrasTotales
	}

	cout << gorrasTotales << endl;
	return true;
}

int main() {

	// ajustes para que cin extraiga directamente de un fichero
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
}