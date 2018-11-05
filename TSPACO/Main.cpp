#include <chrono>
#include "ManualData.h"
#include "XMLData.h"
#include "Ant.h"

using namespace std;
using namespace std::chrono;

//#define NUMBERANTS 500    // Anzahl an Ameisen
//#define ITERATIONSMAX 300   // Maximale Anzahl an Iterationen in den keine k�rzere Route gefunden wird
//#define ALGORITHM 1 // Entscheidet, ob die L�sung iterativ oder parallel gefunden werden soll : 0 = iterativ; 1 = parallel
//#define PROBABILTYALGORITHM 0 // Entscheidet, welcher Algorithmus zur Berechnung der Wahrscheinlichkeit des n�chsten Knotens verwendet werden soll: 0 = einfach; 1 = komplex

int numberants = 3000;
int iterationsmax = 700;
int algorithm = 0;
int probabilityalgorithm = 1;
int reduce = 0;

string filepath = "TSPLIB/burma14.xml";

double reduceValue = 0.001;
double pheromonedeposit = 2;
double pheromonereduction = 0.13;
double alpha = 0.7;
double beta = 0.9;

int numbercities = 14;

int csv = 0;



void ACO(string Vpath, int Vnumberants, int Viteration, int Vreductionvalue, double Vpheromonedeposit, double Vpheromonereduction, double Valpha, double Vbeta, int Vreduce, int Valgorithm, int VprobAlgorithm, int Vcsv) {

	srand(time(NULL) - _getpid());

	XMLData data1(Vpath);

	if (data1.getCityCount() > 0) {

		vector<Ant> antarmy;
		antarmy.reserve(Vnumberants);
		for (int i = 0; i < Vnumberants; ++i)
		{
			antarmy.push_back(Ant(data1, Vreductionvalue, Vpheromonedeposit, Vpheromonereduction, Valpha, Vbeta, Vreduce, VprobAlgorithm));
		}

		int currentAntNumber = 1;


		if (Valgorithm == 0) {

			for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
				if (ant->getIterations() < Viteration) {
					ant->setNumber(currentAntNumber);
					currentAntNumber++;
					ant->antRoute();
				}
			}
			if (Vcsv == 0) {
				cout << "Algorithmus stopped at Ant Number: " << currentAntNumber << endl;
				antarmy[currentAntNumber - 2].printRouteWithCity();
			}
			else {
				cout << currentAntNumber << ";" << antarmy[currentAntNumber - 2].getShortestDistance();
			}

		}
		else if (Valgorithm == 1) {
			for (int j = 0; j < data1.getCityCount(); j++) {
				for (auto ant = antarmy.begin(); ant != antarmy.end(); ++ant) {
					if (j == 0) {
						ant->setNumber(currentAntNumber);
						currentAntNumber++;
						ant->antParallelRoute(j);
					}
					else {
						ant->antParallelRoute(j);
						if (j == (data1.getCityCount() - 1))
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
			if (Vcsv == 0) {
				cout << "Shortest Path was found by ant number: " << shortestPathAntNumber << endl;
				cout << "Distance: " << shortestPath << endl;
				antarmy[shortestPathAntNumber - 1].printOnlyRoute();
			}
			else {
				cout << shortestPathAntNumber << ";" << shortestPath;
			}


		}
		else
			cout << "Invalid Algorithm-Number Input" << endl;
	}
}

int main(int argc, char *argv[]) {

	filepath = argv[1];
	string strAntNumber = argv[2];
	string strIteration = argv[3];
	string strReductionValue = argv[4];
	string strPheromoneDeposit = argv[5];
	string strPheromoneReduction = argv[6];
	string strAlpha = argv[7];
	string strBeta = argv[8];
	string strReduce = argv[9];
	string strAlgorithm = argv[10];
	string strProbabilityAlgorithm = argv[11];
	string strCSV = argv[12];
	

	numberants = stoi(strAntNumber);
	iterationsmax = stoi(strIteration);
	algorithm = stoi(strAlgorithm);
	reduce = stoi(strReduce);
	reduceValue = stod(strReductionValue);
	pheromonedeposit = stod(strPheromoneDeposit);
	pheromonereduction = stod(strPheromoneReduction);
	alpha = stod(strAlpha);
	beta = stod(strBeta);	
	probabilityalgorithm = stoi(strProbabilityAlgorithm);
	csv = stoi(strCSV);

	ACO(filepath, numberants, iterationsmax, reduceValue, pheromonedeposit, pheromonereduction, alpha, beta, reduce, algorithm, probabilityalgorithm, csv);
	//system("pause");
	return 0;
}