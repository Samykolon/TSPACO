#include "XMLData.h"

XMLData::XMLData(string path, int citynumber)
{
	citycount = citynumber;
	
	cities.reserve(citynumber);
	for (int k = 0; k < citynumber; k++)
		cities.push_back(City(to_string(k), 0.0, 0.0));

	srand(time(NULL) - _getpid());

	double random, pheromonerandom;

	pheromoneMatrix.assign(citynumber, vector<double>(citynumber, 0));
	distanceMatrix.assign(citynumber, vector<double>(citynumber, 0));

	for (int i = 0; i < citycount; i++) {
		for (int j = 0; j < citycount; j++) {
			if (pheromoneMatrix[j][i] == 0 && i != j) {
				random = (rand() % 1000);
				pheromonerandom = random / 1000 * PHEROMONEINIT;
				pheromoneMatrix[i][j] = 0.1; // pheromonerandom;
			}
			else
				pheromoneMatrix[i][j] = pheromoneMatrix[j][i];
		}
	}

	string line;
	ifstream in(path);
	int currentCityCount = 0;
	int currentCity = 0;
	bool begindata = false;
	while (getline(in, line)) {
		std::string tmp;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ' && tmp.size() == 0)
			{
			}
			else
			{
				tmp += line[i];
			}
		}

		if (tmp == "<vertex>")
		{
			begindata = true;
			continue;
		}
		else if (tmp == "</vertex>")
		{
			begindata = false;
		}

		if (begindata) {
			size_t pos = tmp.find("\"");
			string doubletmp = tmp.substr(pos + 1, 21);
			double d = stod(doubletmp);
			if (currentCity == currentCityCount)
				currentCityCount++;
			distanceMatrix[currentCity][currentCityCount] = d;
			currentCityCount++;
			if (currentCityCount >= citynumber) {
				currentCity++;
				currentCityCount = 0;
			}
				
		}
	}

}

vector<vector<double>> const & XMLData::getPheromoneMatrix() const
{
	return pheromoneMatrix;
}

vector<vector<double>> const & XMLData::getDistanceMatrix() const
{
	return distanceMatrix;
}

int XMLData::getCityCount()
{
	return citycount;
}

void XMLData::printPheromoneMatrix()
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

void XMLData::printDistanceMatrix()
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
