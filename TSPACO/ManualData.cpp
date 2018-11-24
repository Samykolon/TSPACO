#include "ManualData.h"


ManualData::ManualData(const vector<City> _cities)
{
	srand(time(NULL) - _getpid());
	this->cities = _cities;
	this->citycount = cities.size();
	double random, pheromonerandom;

	pheromoneMatrix.assign(citycount, vector<double>(citycount, 0));
	distanceMatrix.assign(citycount, vector<double>(citycount, 0));

	for (int i = 0; i < citycount; i++) {
		for (int j = 0; j < citycount; j++) {
			City A = cities[i];
			City B = cities[j];
			distanceMatrix[i][j] = A.measureDistance(A, B);     // Distanzen ermitteln
			if (pheromoneMatrix[j][i] == 0 && i != j) {
				random = (rand() % 1000);
				pheromonerandom = random / 1000 * PHEROMONEINIT;        
				pheromoneMatrix[i][j] = 0.1; // pheromonerandom;      // Startwert der Pheromonwerte in der Pheromonmatrix
			}
			else
				pheromoneMatrix[i][j] = pheromoneMatrix[j][i];
		}
	}
}

vector<vector<double>> const & ManualData::getPheromoneMatrix() const
{
	return pheromoneMatrix;
}

vector<vector<double>> const & ManualData::getDistanceMatrix() const
{
	return distanceMatrix;
}

int ManualData::getCityCount()
{
	return this->citycount;
}

void ManualData::printPheromoneMatrix()
{
	cout.precision(9);

	for (int i = 0; i < citycount; ++i) {
		for (int j = 0; j < citycount; ++j) {
			if (i == j)
				cout << setw(12) << fixed << "X";
			else
				cout << setw(12) << fixed << pheromoneMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void ManualData::printDistanceMatrix()
{
	cout.precision(4);

	for (int i = 0; i < citycount; ++i) {
		for (int j = 0; j < citycount; ++j) {
			if (i == j)
				cout << setw(12) << fixed << "X";
			else
				cout << setw(12) << fixed << distanceMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
