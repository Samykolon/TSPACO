#pragma once
#include "City.h"
#include "Route.h"
#include <vector>
#include <iostream>
#include <iomanip> 
#include <time.h>
#include <math.h>
#include <algorithm>

#define NUMBERANTS 500      // Anzahl an Ameisen
#define PHEROMONEINIT 0.5   // Paramter für den maximalen Pheromonstartwert wenn dieser zu Beginn zufällig generiert wird
#define REDUCE 0.05         // Paramter für die Reduktion des Pheromons auf allen Kanten

#define PHEROMONEDEPOSIT 30		// Parameter für die Menge des platzierten Pheromons
#define PHEROMONEREDUCTION 0.1	    // Paramter für die Reduktion des Pheromons

#define ALPHA 0.5   // Parameter für die Wichtigkeit des Pheromons
#define BETA 20		// Parameter für die Wichtigkeit der Distanz

const vector<City> MyCities{ City("Boston", 42.3601, -71.0589),
City("Houston", 29.7604, -95.3698), City("Austin", 30.2672, -97.7431),
City("San Francisco", 37.7749, -122.4194), City("Denver", 39.7392, -104.9903),
City("Los Angeles", 34.0522, -118.2437), City("Chicago", 41.8781, -87.6298) };

vector<vector<double>> pheromoneMatrix;
vector<vector<double>> distanceMatrix;

int countcities = MyCities.size();

void printPheromoneMatrix() {

	cout.precision(9);

	for (int i = 0; i < countcities; ++i) {
		for (int j = 0; j < countcities; ++j) {
			if (i == j)
				cout << setw(12) << fixed << "X";
			else 
				cout << setw(12) << fixed << pheromoneMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


void init() {

	srand(time(NULL));
	double random, pheromonerandom;

	pheromoneMatrix.assign(countcities, vector<double>(countcities, 0));
	distanceMatrix.assign(countcities, vector<double>(countcities, 0));

	for (int i = 0; i < countcities; i++) {
		for (int j = 0; j < countcities; j++) {
			City A = MyCities[i];
			City B = MyCities[j];
			distanceMatrix[i][j] = A.measureDistance(A, B);
			if (pheromoneMatrix[j][i] == 0 && i != j) {
				random = (rand() % 1000);
				pheromonerandom = random / 1000 * PHEROMONEINIT;
				pheromoneMatrix[i][j] = 0.1; // pheromonerandom;
			}
			else
				pheromoneMatrix[i][j] = pheromoneMatrix[j][i];
		}
	}

	printPheromoneMatrix();
}

void updatePheromone(int i, int j, double distance)
{
	double currentpheromone = pheromoneMatrix[i][j];
	double updatedpheromone = (1 - PHEROMONEREDUCTION)*currentpheromone + PHEROMONEDEPOSIT / distance;

	if (updatedpheromone < 0.0) {
		pheromoneMatrix[i][j] = 0;
		pheromoneMatrix[j][i] = 0;
	}
	else {
		pheromoneMatrix[i][j] = updatedpheromone;
		pheromoneMatrix[j][i] = updatedpheromone;
	}

}

void reducePheromone()
{
	for (int i = 0; i < countcities; ++i) {
		for (int j = 0; j < countcities; ++j) {
			pheromoneMatrix[i][j] -= REDUCE * pheromoneMatrix[i][j];
			if (pheromoneMatrix[i][j] < 0)
				pheromoneMatrix[i][j] = 0;
		}
	}
}

void printCities() {
	for each (City city in MyCities)
		cout << city.getName() << " | " << city.getLongitude() << " | " << city.getLatitude() << endl;
}



