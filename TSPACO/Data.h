#pragma once
#include "City.h"

#define PHEROMONEINIT 0.5   // Paramter für den maximalen Pheromonstartwert wenn dieser zu Beginn zufällig generiert wird

class Data {

public:
	
	Data(vector<City> _cities);

	vector<vector<double>> const &getPheromoneMatrix() const;
	vector<vector<double>> const &getDistanceMatrix() const;

	vector<City> cities;

	vector<vector<double>> pheromoneMatrix;
	vector<vector<double>> distanceMatrix;

	int getCityCount();

	void printPheromoneMatrix();

	

private:

	int citycount;	

};




