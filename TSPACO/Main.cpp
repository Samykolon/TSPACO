#include <chrono>
#include <thread>
#include "Data.h"
#include "Ant.h"
#include "ImportTSP.h"


using namespace std;
using namespace std::chrono;

#define NUMBERANTS 2000     // Anzahl an Ameisen
#define ITERATIONSMAX 1500   // Maximale Anzahl an Iterationen in den keine kürzere Route gefunden wird

void AntThread(Ant ant, int currentAntNumber) {
	if (ant.getIterations() < ITERATIONSMAX) {
		ant.setNumber(currentAntNumber);
		ant.antRoute();
	}
}

int main() {
	
	srand(time(NULL) - _getpid());
	
	Data data1(convertCities());
	
	// Iteration

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

	// Parallel

	/*int currentAntNumber = 1;
	if (data1.getCityCount() > 0) {
		vector<Ant> antarmy;
		antarmy.reserve(NUMBERANTS);
		vector<thread> ThreadVector;
		ThreadVector.reserve(NUMBERANTS);
		for (int i = 0; i < NUMBERANTS; ++i)
		{
			antarmy.push_back(Ant(data1));
		}
		for (int j = 0; j < NUMBERANTS; ++j)
		{
			ThreadVector.push_back(thread(AntThread, antarmy[j], currentAntNumber));
			currentAntNumber++;

		}

		for (thread & th : ThreadVector)
		{		
			if (th.joinable())
				th.join();
		}
	}*/

	system("pause");
	return 0;
}
