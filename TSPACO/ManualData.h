#pragma once
#include "City.h"

#define PHEROMONEINIT 0.5   // Paramter für den maximalen Pheromonstartwert wenn dieser zu Beginn zufällig generiert wird

// Die Klasse ManualData dient nur dazu, wenn die TSP Probleminstanz nicht aus einer XML-Datei eingelesen wird sondern manuell im Code definiert und initialisert wird

class ManualData {

public:
	
	ManualData(vector<City> _cities);

	vector<vector<double>> const &getPheromoneMatrix() const;
	vector<vector<double>> const &getDistanceMatrix() const;

	vector<City> cities;

	vector<vector<double>> pheromoneMatrix;
	vector<vector<double>> distanceMatrix;

	int getCityCount();

	void printPheromoneMatrix();
	void printDistanceMatrix();	

private:

	int citycount;	// Anzahl der Städte

};




