#include <chrono>
#include "Data.h"
#include "Ant.h"


using namespace std;
using namespace std::chrono;

#define NUMBERANTS 500      // Anzahl an Ameisen
#define ITERATIONSMAX 100   // Maximale Anzahl an Iterationen in den keine kürzere Route gefunden wird

const vector<City> MyCities{ City("Boston", 42.3601, -71.0589),
City("Houston", 29.7604, -95.3698), City("Austin", 30.2672, -97.7431),
City("San Francisco", 37.7749, -122.4194), City("Denver", 39.7392, -104.9903),
City("Los Angeles", 34.0522, -118.2437), City("Chicago", 41.8781, -87.6298) };



int main() {
	
	srand(time(NULL) - _getpid());
	
	Data data1(MyCities);
		
	vector<Ant> antarmy;
	antarmy.reserve(NUMBERANTS);
	for (int i = 0; i < NUMBERANTS; ++i)
	{
		antarmy.push_back(Ant(data1));
	}

	int currentAntNumber = 1;

	
	for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
		if(ant->getIterations() < ITERATIONSMAX) {
			ant->setNumber(currentAntNumber);
			currentAntNumber++;
			ant->antRoute();			
		}
	}

	cout << "Algorithmus stopped at Ant Number: " << currentAntNumber << endl;

	system("pause");
	return 0;
}
