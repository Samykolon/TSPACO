#pragma once
#include "City.h"

#define PHEROMONEINIT 0.5   // Paramter für den maximalen Pheromonstartwert wenn dieser zu Beginn zufällig generiert wird

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

	int citycount;	

};




