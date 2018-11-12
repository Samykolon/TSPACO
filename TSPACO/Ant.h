#pragma once
#include "Route.h"
#include "ManualData.h"
#include "XMLData.h"

//#define REDUCE (double) 0.001     // Paramter für die Reduktion des Pheromons auf allen Kanten
//
//#define PHEROMONEDEPOSIT (double) 40	// Parameter für die Menge des platzierten Pheromons
//#define PHEROMONEREDUCTION (double) 0.15	    // Paramter für die Reduktion des Pheromons
//
//#define ALPHA (double) 0.8  // Parameter für die Wichtigkeit des Pheromons
//#define BETA (double) 0.5		// Parameter für die Wichtigkeit der Distanz

using namespace std;

class Ant {

public:

	Ant(XMLData &_data, double _reductionvalue, double _pheromonedeposit, double _pheromonereduction, double _alpha, double _beta, int _boolreduce, int _probalgorithm) : route(_data.getCityCount()) {
		this->data = &_data;
		datacitycount = _data.getCityCount();
		startindex = rand() % _data.getCityCount();
		visitedVector.assign(_data.getCityCount(), 0);
		countvisitedcities = 1;
		visitedVector[startindex] = 1;
		routedistance = 0.0;
		probabilityVector = vector<double>(_data.getCityCount());
		reductionvalue = _reductionvalue;
		pheromonedeposit = _pheromonedeposit;
		pheromonereduction = _pheromonereduction;
		alpha = _alpha;
		beta = _beta;
		boolreduce = _boolreduce;
		probabilityalgorithm = _probalgorithm;
	}

private:

	double reductionvalue;
	double pheromonedeposit;
	double pheromonereduction;
	double alpha;
	double beta;
	int boolreduce;
	int probabilityalgorithm;

	int datacitycount;

	static double shortestdistance;
	static int iterationsshortestpath;
	static int mmasant;

	double routedistance;
	int antnumber;
	int startindex;

	vector<bool> visitedVector;
	vector<double> probabilityVector;

	int countvisitedcities;

	int tempcity; int nextcity;

	XMLData *data;

public:

	Route route;

	int getAntNumber() { return antnumber; }
	void setNumber(int number) { antnumber = number; }
	int getStartIndex() { return startindex; }
	int getVisitedCount() { return countvisitedcities; }
	void setVisited(int index) { visitedVector[index] = 1; }
	void setProbability(int index) { probabilityVector[index] = -1; }

	double getShortestDistance() { return this->shortestdistance; }
	void setShortestDistance(double distance) { this->shortestdistance = distance; }
	int getOvAnt() { return this->mmasant; }

	double getRouteDistance() { return this->routedistance; }

	int getIterations() { return this->iterationsshortestpath; }
	void setIterations(int iterations) { this->iterationsshortestpath = iterations; }

	int getBool(int index) { return visitedVector[index]; }

	void printAnt();
	void printVisited();
	int getNextCity(int currentCity);
	int probabilityCity(int x);
	double probPheromone(int i, int j);

	void antRoute();
	void antParallelRoute(int currentCity);
	void mmasRoute();
	void mmasUpdatePheromone();
	void reset();

	void backToStart();

	void updatePheromone(int i, int j, double distance);
	void reducePheromone();

	void printRouteWithCity();
	void printOnlyRoute();
	void ShortestDistance(double distance);
	void mmasShortestDistance(double distance);

};