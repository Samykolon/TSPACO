#include "Ant.h"

using namespace std;

int main() {

	init();

	vector<Ant> antarmy;
	antarmy.resize(NUMBERANTS);
	int currentAntNumber = 1;
	

	for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
		ant->setNumber(currentAntNumber);
		currentAntNumber++;
		ant->antRoute();
		if (currentAntNumber == 3 || currentAntNumber == 50 || currentAntNumber == 150 || currentAntNumber == 399 || currentAntNumber == 500) {
			printPheromoneMatrix();
			//ant->route.printRoute();
			ant->printRouteWithCity();
		}

			
	}



	system("pause");
	return 0;
}
