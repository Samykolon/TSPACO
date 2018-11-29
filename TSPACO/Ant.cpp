#include "Ant.h"

// Statische Member initialisieren

double Ant::shortestdistance = 9999999.9;
int Ant::iterationsshortestpath = 0;
int Ant::mmasant = 0;

// Ermittelt nächste Stadt 

int Ant::getNextCity(int x)
{
	int nextCity = -1;
	for (int i = 0; i < datacitycount; i++) {
		if (visitedVector[i] == 0) {
			if (x == i) probabilityVector[i] = -1;
			else probabilityVector[i] = probPheromone(x, i);
		}
		else
			probabilityVector[i] = 0;
	}

	vector<double>::iterator result;
	result = max_element(probabilityVector.begin(), probabilityVector.end()); 
	nextCity = distance(probabilityVector.begin(), result);
	countvisitedcities++;
	return nextCity;
}

// Ermittelt die Wahrscheinlichkeit mit der eine Ameise von Stadt i zu Stadt j reist

double Ant::probPheromone(int i, int j)
{
	double prob = 0.0;
	double pheromoneLevel = this->data->pheromoneMatrix[i][j];

	// Vereinfachte Form

	if (probabilityalgorithm == 0) {     
		if (pheromoneLevel != 0.0)
			prob = pow(pheromoneLevel, alpha) * pow(1 / this->data->distanceMatrix[i][j], beta);	
		return prob;
	}

	// Komplexere Form

	else {

		double ETAij = pow(1 / this->data->distanceMatrix[i][j], beta);
		double TAUij = pow(pheromoneLevel, alpha);

		double sum = 0.0;
		for (int c = 0; c < datacitycount; c++) {

			double pheromoneLevelCity = this->data->pheromoneMatrix[i][c];

			if (visitedVector[c] == 0) {
				double ETA = pow(1 / this->data->distanceMatrix[i][c], beta);
				double TAU = pow(pheromoneLevelCity, alpha);
				sum += ETA * TAU;
			}
		}

		return (ETAij * TAUij) / sum;
	}
}

// Tourkonstruktion für die iterative Tourkonstruktion

void Ant::antRoute()
{
	this->route.setCity(0, this->getStartIndex());
	int nextCity = this->getNextCity(this->getStartIndex());
	this->routedistance += this->data->distanceMatrix[this->getStartIndex()][nextCity];
	int tempCity;
	int i = 2;
	this->setProbability(nextCity);
	this->setVisited(nextCity);
	this->route.setCity(1, nextCity);
	
	while (this->getVisitedCount() < datacitycount) {
		tempCity = nextCity;
		nextCity = this->getNextCity(nextCity);
		this->setProbability(nextCity);
		this->setVisited(nextCity);
		this->route.setCity(i, nextCity);
		this->routedistance += this->data->distanceMatrix[tempCity][nextCity];
		i++;
	}

	CompleteTourPheromonUpdate();

	this->routedistance += this->data->distanceMatrix[nextCity][this->getStartIndex()];
	if(boolreduce == 1)
		reducePheromone();
	ShortestDistance(this->routedistance);
	this->iterationsshortestpath++;
}

// Tourkonstruktion für die parallele Tourkonstruktion

void Ant::antParallelRoute(int currentCity)
{
	if (currentCity == 0) {
		this->route.setCity(0, this->getStartIndex());
		nextcity = this->getNextCity(this->getStartIndex());
		this->routedistance += this->data->distanceMatrix[this->getStartIndex()][nextcity];
		this->setProbability(nextcity);
		this->setVisited(nextcity);
		this->route.setCity(1, nextcity);
		updatePheromone(this->getStartIndex(), nextcity, routedistance);
		if (boolreduce == 1)
			reducePheromone();
	}
	else if (currentCity > 0 && currentCity < data->getCityCount() - 1) {
		tempcity = nextcity;
		nextcity = this->getNextCity(nextcity);
		this->setProbability(nextcity);
		this->setVisited(nextcity);
		this->route.setCity(currentCity+1, nextcity);
		this->routedistance += this->data->distanceMatrix[tempcity][nextcity];
		updatePheromone(tempcity, nextcity, routedistance);
		if (boolreduce == 1)
			reducePheromone();
	}
}

// Tourkonstruktion für die iterative Tourkonstruktion mit eingeschränkter Pheromonaktualisierung

void Ant::mmasRoute()
{
	this->route.setCity(0, this->getStartIndex());
	int nextCity = this->getNextCity(this->getStartIndex());
	this->routedistance += this->data->distanceMatrix[this->getStartIndex()][nextCity];
	int tempCity;
	int i = 2;
	this->setProbability(nextCity);
	this->setVisited(nextCity);
	this->route.setCity(1, nextCity);	

	while (this->getVisitedCount() < datacitycount) {
		tempCity = nextCity;
		nextCity = this->getNextCity(nextCity);
		this->setProbability(nextCity);
		this->setVisited(nextCity);
		this->route.setCity(i, nextCity);
		this->routedistance += this->data->distanceMatrix[tempCity][nextCity];		
		i++;
	}

	this->routedistance += this->data->distanceMatrix[nextCity][this->getStartIndex()];
	mmasShortestDistance(this->routedistance);
	
}

// Updated die Pheromonkonzentration der gesamten Route

void Ant::CompleteTourPheromonUpdate()
{
	vector<int> ovr = this->route.get();
	for (int i = 0; i < ovr.size() - 1; i++)
		updatePheromone(ovr[i], ovr[i + 1], this->routedistance);
}

// Resettet die statischen Variablen

void Ant::reset()
{
	shortestdistance = 9999999.9;
	iterationsshortestpath = 0;
	mmasant = 0;
}

// Fügt der Route die Distanz der letzten Stadt zur Stadtstadt hinzu

void Ant::backToStart()
{
	this->routedistance += this->data->distanceMatrix[nextcity][this->getStartIndex()];	
}

// Aktualisiert die Pheromonkonzentration zwischen Stadt i und Stadt j

void Ant::updatePheromone(int i, int j, double distance)
{
	double currentpheromone = this->data->pheromoneMatrix[i][j];
	double updatedpheromone = (1 - pheromonereduction)*currentpheromone + (pheromonedeposit / distance);

	if (updatedpheromone < 0.0) {
		this->data->pheromoneMatrix[i][j] = 0;
		this->data->pheromoneMatrix[j][i] = 0;
	}
	else {
		this->data->pheromoneMatrix[i][j] = updatedpheromone;
		this->data->pheromoneMatrix[j][i] = updatedpheromone;
	}
}

// Reduziert die Pheromonkonzentration in der gesamten Pheromonmatrix

void Ant::reducePheromone()
{
	for (int x = 0; x < datacitycount; x++) {
		for (int y = 0; y < datacitycount; y++) {
			if(reductionvalue * this->data->pheromoneMatrix[x][y] < 0)
				this->data->pheromoneMatrix[x][y] = 0.0;
			else
				this->data->pheromoneMatrix[x][y] -= reductionvalue * this->data->pheromoneMatrix[x][y];			
		}
	}
}

// Gibt Route mit Städtenamen und Distanz aus

void Ant::printRouteWithCity()
{
	cout << this->getAntNumber() << ". Ameise: " << endl;
	for (int i = 0; i < datacitycount; i++)
		cout << this->data->cityVector[this->route.getIndex(i)].getName() << " | ";

	cout << "Distance: " << this->routedistance << endl;
}

// Gibt Route mit Städtenamen aus

void Ant::printOnlyRoute()
{
	for (int i = 0; i < datacitycount; i++)
		cout << this->data->cityVector[this->route.getIndex(i)].getName() << " | ";
}

// Weist dem statischen Member shortestDistance die kürzeste Distanz zu

void Ant::ShortestDistance(double distance)
{
	if (this->shortestdistance > distance) {
		this->shortestdistance = distance;		
		this->iterationsshortestpath = 0;
		//cout << antnumber << ";" << distance << endl;
	}

}

// Ermittelt die Nummer der Ameise mit der kürzesten Route 

void Ant::mmasShortestDistance(double distance)
{
	if (this->shortestdistance > distance) {
		this->shortestdistance = distance;
		mmasant = this->antnumber;		
	}
}
