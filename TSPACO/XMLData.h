#pragma once
#include "City.h"
#include <fstream>
#include <sstream>

#define PHEROMONEINIT 0.5   // Paramter für den maximalen Pheromonstartwert wenn dieser zu Beginn zufällig generiert wird

using namespace std;

class XMLData {

public:

	XMLData(string _path, int _numberofcities);

	vector<vector<double>> const &getPheromoneMatrix() const;
	vector<vector<double>> const &getDistanceMatrix() const;

	vector<City> cities;

	vector<vector<double>> pheromoneMatrix;
	vector<vector<double>> distanceMatrix;

	int getCityCount();

	void printPheromoneMatrix();
	void printDistanceMatrix();



private:

	int numberofcities;

};