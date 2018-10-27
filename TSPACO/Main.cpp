#include <chrono>
#include "ManualData.h"
#include "XMLData.h"
#include "Ant.h"

using namespace std;
using namespace std::chrono;

#define NUMBERANTS 500    // Anzahl an Ameisen
#define ITERATIONSMAX 300   // Maximale Anzahl an Iterationen in den keine kürzere Route gefunden wird
#define ALGORITHM 1 // Entscheidet, ob die Lösung iterativ oder parallel gefunden werden soll : 0 = iterativ; 1 = parallel
#define PROBABILTYALGORITHM 0 // Entscheidet, welcher Algorithmus zur Berechnung der Wahrscheinlichkeit des nächsten Knotens verwendet werden soll: 0 = einfach; 1 = komplex

void ACO(string path, int numberofcities) {

	srand(time(NULL) - _getpid());

	XMLData data1(path, numberofcities);

	if (data1.getCityCount() > 0) {

		vector<Ant> antarmy;
		antarmy.reserve(NUMBERANTS);
		for (int i = 0; i < NUMBERANTS; ++i)
		{
			antarmy.push_back(Ant(data1, PROBABILTYALGORITHM));
		}

		int currentAntNumber = 1;


		if (ALGORITHM == 0) {

			for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
				if (ant->getIterations() < ITERATIONSMAX) {
					ant->setNumber(currentAntNumber);
					currentAntNumber++;
					ant->antRoute();
				}
			}

			cout << "Algorithmus stopped at Ant Number: " << currentAntNumber << endl;

		}
		else if (ALGORITHM == 1) {
			for (int j = 0; j < data1.getCityCount(); j++) {
				for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
					if (j == 0) {
						ant->setNumber(currentAntNumber);
						currentAntNumber++;
						ant->antParallelRoute(j);
					}
					else {
						ant->antParallelRoute(j);
						if (j == data1.getCityCount() - 1)
							ant->backToStart();
					}
				}
			}

			int shortestPathAntNumber = -1;
			double shortestPath = 99999999.9;

			for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
				if (ant->getRouteDistance() < shortestPath) {
					shortestPath = ant->getRouteDistance();
					shortestPathAntNumber = ant->getAntNumber();
				}
			}

			cout << "Shortest Path was found by ant number: " << shortestPathAntNumber << endl;
			cout << "Distance: " << shortestPath << endl;


		}
		else
			cout << "Invalid Algorithm-Number Input" << endl;
	}
}

int main() {

	ACO("TSPLIB/burma14.xml", 14);
	system("pause");
	return 0;
}