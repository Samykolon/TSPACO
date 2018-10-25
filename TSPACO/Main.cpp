#include <chrono>
#include <thread>
#include "Data.h"
#include "Ant.h"
#include "ImportTSP.h"


using namespace std;
using namespace std::chrono;

#define NUMBERANTS 300     // Anzahl an Ameisen
#define ITERATIONSMAX 200 // Maximale Anzahl an Iterationen in den keine kürzere Route gefunden wird

void AntThread(Ant ant, int currentAntNumber) {
	if (ant.getIterations() < ITERATIONSMAX) {
		ant.setNumber(currentAntNumber);
		ant.antRoute();
	}
}

int main() {
	
	srand(time(NULL) - _getpid());
	auto runt = 999999999999;
	double at, bt, ct, dt;

	
	// Iteration
	for (double a = 0.1; a <= 0.7; a += 0.1)
		for (double b = 0.05; b <= 0.3; b += 0.05)
			for (double c = 0.4; c <= 1.4; c += 0.2)
				for (double d = 0.5; d <= 12; d += 2) {
					Data data1(convertCities());
					double st;
					high_resolution_clock::time_point t1 = high_resolution_clock::now();
					if (data1.getCityCount() > 0) {
						
						vector<Ant> antarmy;
						antarmy.reserve(NUMBERANTS);
						for (int i = 0; i < NUMBERANTS; ++i)
						{
							antarmy.push_back(Ant(data1, a, b, c, d));
						}

						int currentAntNumber = 1;


						for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
							if (ant->getIterations() < ITERATIONSMAX) {
								ant->setNumber(currentAntNumber);
								currentAntNumber++;
								ant->antRoute();
								st = ant->getShortestDistance();
							}

						}

						//cout << "Algorithmus stopped at Ant Number: " << currentAntNumber << endl;
					}
					high_resolution_clock::time_point t2 = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(t2 - t1).count();
					if (duration < runt && st < 2800 ) {
						runt = duration;
						at = a; bt = b; ct = c; dt = d;
					}

					if(st < 2700)
						cout << a << " " << b << " " << c << " " << d << " time: " << duration << " distance: " << st << endl;

				}
	
	cout << at << " " << bt << " " << ct << " " << dt << " time: " << runt << endl;

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
