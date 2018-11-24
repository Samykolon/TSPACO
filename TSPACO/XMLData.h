#pragma once
#include "City.h"
#include <fstream>
#include <sstream>

#define PHEROMONEINIT 0.5   // Paramter f�r den maximalen Pheromonstartwert wenn dieser zu Beginn zuf�llig generiert wird

using namespace std;

// Klasse, die das Datenobjekt generiert

class XMLData {

public:

	XMLData(string _path);

	vector<vector<double>> const &getPheromoneMatrix() const;
	vector<vector<double>> const &getDistanceMatrix() const;

	vector<City> cityVector;

	vector<vector<double>> pheromoneMatrix;
	vector<vector<double>> distanceMatrix;

	int getCityCount();

	void printPheromoneMatrix();
	void printDistanceMatrix();

private:

	int numberofcities;

};