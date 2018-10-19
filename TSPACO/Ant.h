#include "Data.h"

using namespace std;

class Ant {

public:
	Ant() : route(countcities) {
		startindex = rand() % countcities;
		visitedVector.assign(countcities, 0);
		countvisitedCities = 1;
		visitedVector[startindex] = 1;
		routedistance = 0.0;
		probabilityVector = vector<double>(countcities);
	}

private:

	
	double routedistance;
	int antnumber;
	int startindex;

	vector<bool> visitedVector;
	vector<double> probabilityVector;
	
	int countvisitedCities;

	

public:

	Route route;
	int getAntNumber() { return antnumber; }
	void setNumber(int number) { antnumber = number; }
	int getStartIndex() { return startindex; }
	int getVisitedCount() { return countvisitedCities; }
	void setVisited(int index) { visitedVector[index] = 1; }
	void setProbability(int index) { probabilityVector[index] = -1; }
	int getBool(int index) { return visitedVector[index]; }
	void printAnt() { cout << "Index: " << getAntNumber() << " StartCity: " << getStartIndex() << endl; }
	void printVisited() {
		for (int i = 0; i < countcities; i++)
			cout << visitedVector[i] << " ";
		cout << endl;
	}
	int getNextCity(int currentCity) {
		int nextCity = probabilityCity(currentCity);
		countvisitedCities++;
		return nextCity;
	}


	int probabilityCity(int x) {
		int nextCity = -1;
		for (int i = 0; i < countcities; i++) {
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

	double probPheromone(int i, int j) {
		double prob = 0.0;
		double pheromoneLevel = pheromoneMatrix[i][j];
		
		/*if (pheromoneLevel != 0.0)
			prob = pow(pheromoneLevel, ALPHA) * pow(1 / distanceMatrix[i][j], BETA);	//vereinfachte Form (Test)
		return prob;*/



		double ETAij = pow(1 / distanceMatrix[i][j], BETA);                                  
		double TAUij = pow(pheromoneLevel, ALPHA);

		double sum = 0.0;
		for (int c = 0; c < countcities; c++) {

			double pheromoneLevelCity = pheromoneMatrix[i][c];
			
				if (visitedVector[c] == 0) {
					double ETA = pow(1 / distanceMatrix[i][c], BETA);
					double TAU = pow(pheromoneLevelCity, ALPHA);
					sum += ETA * TAU;
				}
			}
		
		return (ETAij * TAUij) / sum;


	}

	void antRoute() {

		this->route.setCity(0, this->getStartIndex());
		int nextCity = this->getNextCity(this->getStartIndex());
		this->routedistance += distanceMatrix[this->getStartIndex()][nextCity];
		int tempCity;
		int i = 2;
		this->setProbability(nextCity);
		this->setVisited(nextCity);
		this->route.setCity(1, nextCity);
		updatePheromone(this->getStartIndex(), nextCity, distanceMatrix[this->getStartIndex()][nextCity]);

		while (this->getVisitedCount() < countcities) {
			tempCity = nextCity;
			nextCity = this->getNextCity(nextCity);
			this->setProbability(nextCity);
			this->setVisited(nextCity);
			this->route.setCity(i, nextCity);
			this->routedistance += distanceMatrix[tempCity][nextCity];
			updatePheromone(tempCity, nextCity, distanceMatrix[tempCity][nextCity]);
			i++;
		}
		// this->routedistance += distances[nextCity][this->getStartIndex()];
		
		reducePheromone();
		
	}

	void printRouteWithCity() {
		
		cout << this->getAntNumber() << ". Ameise: " << endl;
		for (int i = 0; i < countcities; i++)
			cout << MyCities[this->route.getIndex(i)].getName() << " | ";

		cout << "Distance: " << this->routedistance << endl;

	}



	

};

