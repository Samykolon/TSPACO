#pragma once
#include "Route.h"
#include "ManualData.h"
#include "XMLData.h"

using namespace std;

class Ant {

public:

	Ant(XMLData &_data, double _reductionvalue, double _pheromonedeposit, double _pheromonereduction, double _alpha, double _beta, int _boolreduce, int _probalgorithm) : route(_data.getCityCount()) {
		this->data = &_data;
		datacitycount = _data.getCityCount();
		startindex = rand() % _data.getCityCount();            // Zufällige Startstadt definieren
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

	double reductionvalue;                  // Wert für die Verringerung des Pheromons bei allgemeiner Reduktion                 
	double pheromonedeposit;                // Menge des abgelegten Pheromons
	double pheromonereduction;              // Menge des Pheromons, welches verdunstet
	double alpha;                           // Parameter für die Wichtigkeit der Pheromonkonzentration beim Finden der nächsten Stadt
	double beta;                            // Parameter für die Wichtigkeit der Distanz beim Finden der nächsten Stadt 

	int boolreduce;                         // Schalter, der entscheidet ob eine allgemeine Pheromonreduktion durchgeführt werden soll                   
	int probabilityalgorithm;               // Schalter für den ausgewählten Tourkonstruktionsalgorithmus

	int datacitycount;                      // Anzahl der Städte

	static double shortestdistance;         // Kürzeste gefundene Distanz
	static int iterationsshortestpath;      // Iterationszähler für den iterativen Algorithmus
	static int mmasant;                     // Ameise, die die kürzeste Route beim iterativen Algorithmus mit eingeschränkter Pheromonaktualisierung gefunden hat

	double routedistance;                   // Routenlänge
	int antnumber;                          // Nummer der Ameise
	int startindex;                         // Index der Startstadt

	vector<bool> visitedVector;             // Vector, der den Besuchsstatus aller Städte enthält
	vector<double> probabilityVector;       // Vector, der die Wahrscheinlichkeit für den Besuch der jeweiligen Städte enthält

	int countvisitedcities;                 // Zählt die Anzahl der besuchten Städte

	int tempcity; int nextcity;             // Variablen für die Tourkonstruktion

	XMLData *data;                          // Datenobjekt

public:
	 
	Route route;

	// Getter und Setter 

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

	// Folgende Methoden und Funktionen sind in cpp-File näher erklärt

	int getNextCity(int currentCity);
	double probPheromone(int i, int j);

	void antRoute();
	void antParallelRoute(int currentCity);
	void mmasRoute();

	void updatePheromone(int i, int j, double distance);
	void CompleteTourPheromonUpdate();
	void reducePheromone();

	void ShortestDistance(double distance);
	void mmasShortestDistance(double distance);

	void reset();
	void backToStart();

	void printRouteWithCity();
	void printOnlyRoute();


};