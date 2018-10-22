#include "Ant.h"

double Ant::shortestdistance = 9999999.9;
int Ant::iterationsshortestpath = 0;

void Ant::printAnt()
{
	cout << "Index: " << getAntNumber() << " StartCity: " << getStartIndex() << endl;
}

void Ant::printVisited()
{
	for (int i = 0; i < datacitycount; i++)
		cout << visitedVector[i] << " ";
	cout << endl;
}

int Ant::getNextCity(int currentCity)
{
	int nextCity = probabilityCity(currentCity);
	countvisitedCities++;
	return nextCity;
}

int Ant::probabilityCity(int x)
{
	int nextCity = -1;
	for (int i = 0; i < datacitycount; i++) {
		if (visitedVector[i] == 0) {
			if (x == i) probabilityVector[i] = -1;
			else probabilityVector[i] = probPheromone(x, i);
		}
	}
	vector<double>::iterator result;
	result = max_element(probabilityVector.begin(), probabilityVector.end());
	nextCity = distance(probabilityVector.begin(), result);
	return nextCity;
}

double Ant::probPheromone(int i, int j)
{
	double prob = 0.0;
	double pheromoneLevel = this->data->pheromoneMatrix[i][j];

	/*if (pheromoneLevel != 0.0)
	prob = pow(pheromoneLevel, ALPHA) * pow(1 / distanceMatrix[i][j], BETA);	//vereinfachte Form (Test)
	return prob;*/



	double ETAij = pow(1 / this->data->distanceMatrix[i][j], BETA);
	double TAUij = pow(pheromoneLevel, ALPHA);

	double sum = 0.0;
	for (int c = 0; c < datacitycount; c++) {

		double pheromoneLevelCity = this->data->pheromoneMatrix[i][c];

		if (visitedVector[c] == 0) {
			double ETA = pow(1 / this->data->distanceMatrix[i][c], BETA);
			double TAU = pow(pheromoneLevelCity, ALPHA);
			sum += ETA * TAU;
		}
	}

	return (ETAij * TAUij) / sum;
}

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
	updatePheromone(this->getStartIndex(), nextCity, this->data->distanceMatrix[this->getStartIndex()][nextCity]);

	while (this->getVisitedCount() < datacitycount) {
		tempCity = nextCity;
		nextCity = this->getNextCity(nextCity);
		this->setProbability(nextCity);
		this->setVisited(nextCity);
		this->route.setCity(i, nextCity);
		this->routedistance += this->data->distanceMatrix[tempCity][nextCity];
		updatePheromone(tempCity, nextCity, this->data->distanceMatrix[tempCity][nextCity]);
		i++;
	}
	
	// this->routedistance += distances[nextCity][this->getStartIndex()];

	reducePheromone();
	ShortestDistance(this->routedistance);
	this->iterationsshortestpath++;
}

void Ant::updatePheromone(int i, int j, double distance)
{
	double currentpheromone = this->data->pheromoneMatrix[i][j];
	double updatedpheromone = (1 - PHEROMONEREDUCTION)*currentpheromone + PHEROMONEDEPOSIT / distance;

	if (updatedpheromone < 0.0) {
		this->data->pheromoneMatrix[i][j] = 0;
		this->data->pheromoneMatrix[j][i] = 0;
	}
	else {
		this->data->pheromoneMatrix[i][j] = updatedpheromone;
		this->data->pheromoneMatrix[j][i] = updatedpheromone;
	}
}

void Ant::reducePheromone()
{
	for (int i = 0; i < datacitycount; ++i) {
		for (int j = 0; j < datacitycount; ++j) {
			this->data->pheromoneMatrix[i][j] -= REDUCE * this->data->pheromoneMatrix[i][j];
			if (this->data->pheromoneMatrix[i][j] < 0)
				this->data->pheromoneMatrix[i][j] = 0;
		}
	}
}

void Ant::printRouteWithCity()
{
	cout << this->getAntNumber() << ". Ameise: " << endl;
	for (int i = 0; i < datacitycount; i++)
		cout << this->data->cities[this->route.getIndex(i)].getName() << " | ";

	cout << "Distance: " << this->routedistance << endl;
}

void Ant::ShortestDistance(double distance)
{
	if (this->shortestdistance > distance) {
		this->shortestdistance = distance;
		printRouteWithCity();
		this->iterationsshortestpath = 0;
	}
		
}
