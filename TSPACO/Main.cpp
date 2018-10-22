#include <chrono>
#include "Data.h"
#include "Ant.h"
#include "ImportTSP.h"


using namespace std;
using namespace std::chrono;

#define NUMBERANTS 500      // Anzahl an Ameisen
#define ITERATIONSMAX 300   // Maximale Anzahl an Iterationen in den keine kürzere Route gefunden wird



int main() {
	
	srand(time(NULL) - _getpid());
	
	Data data1(convertCities());
	
	if (data1.getCityCount() > 0) {
		vector<Ant> antarmy;
		antarmy.reserve(NUMBERANTS);
		for (int i = 0; i < NUMBERANTS; ++i)
		{
			antarmy.push_back(Ant(data1));
		}

		int currentAntNumber = 1;


		for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
			if (ant->getIterations() < ITERATIONSMAX) {
				ant->setNumber(currentAntNumber);
				currentAntNumber++;
				ant->antRoute();
			}
		}

		cout << "Algorithmus stopped at Ant Number: " << currentAntNumber << endl;
	}

	system("pause");
	return 0;
}
