#pragma once
#include "Route.h"
#include "Data.h"

#define REDUCE 0.01       // Paramter für die Reduktion des Pheromons auf allen Kanten

#define PHEROMONEDEPOSIT 5	// Parameter für die Menge des platzierten Pheromons
#define PHEROMONEREDUCTION 0.1	    // Paramter für die Reduktion des Pheromons

#define ALPHA 0.5   // Parameter für die Wichtigkeit des Pheromons
#define BETA 0.8		// Parameter für die Wichtigkeit der Distanz

using namespace std;

class Ant {

public:

	Ant(Data &_data) : route(_data.getCityCount()) {
		this->data = &_data;
		datacitycount = _data.getCityCount();
		startindex = rand() % _data.getCityCount();
		visitedVector.assign(_data.getCityCount(), 0);
		countvisitedCities = 1;
		visitedVector[startindex] = 1;
		routedistance = 0.0;
		probabilityVector = vector<double>(_data.getCityCount());		
	}
	~Ant();

private:

	int datacitycount;

	static double shortestdistance;
	static int iterationsshortestpath;

	double routedistance;
	int antnumber;
	int startindex;

	vector<bool> visitedVector;
	vector<double> probabilityVector;
	
	int countvisitedCities;

	Data *data;

public:

	Route route;
	
	int getAntNumber() { return antnumber; }
	void setNumber(int number) { antnumber = number; }
	int getStartIndex() { return startindex; }
	int getVisitedCount() { return countvisitedCities; }
	void setVisited(int index) { visitedVector[index] = 1; }
	void setProbability(int index) { probabilityVector[index] = -1; }

	double getShortestDistance() { return this->shortestdistance; }
	void setShortestDistance(double distance) { this->shortestdistance = distance; }

	double getRouteDistance() { return this->routedistance; }

	int getIterations() { return this->iterationsshortestpath;}
	void setIterations(int iterations) { this->iterationsshortestpath = iterations; }
	
	int getBool(int index) { return visitedVector[index]; }

	void printAnt();
	void printVisited();
	int getNextCity(int currentCity);
	int probabilityCity(int x);
	double probPheromone(int i, int j);
	void antRoute();
	void updatePheromone(int i, int j, double distance);
	void reducePheromone();
	void printRouteWithCity();	
	void ShortestDistance(double distance);

};

