#include "XMLData.h"

XMLData::XMLData(string _path, int _numberofcities)
{
	numberofcities = _numberofcities;
	
	cities.reserve(_numberofcities);
	for (int k = 0; k < _numberofcities; k++)
		cities.push_back(City(to_string(k), 0.0, 0.0));

	srand(time(NULL) - _getpid());

	double random, pheromonerandom;

	pheromoneMatrix.assign(_numberofcities, vector<double>(_numberofcities, 0));
	distanceMatrix.assign(_numberofcities, vector<double>(_numberofcities, 0));

	for (int i = 0; i < numberofcities; i++) {
		for (int j = 0; j < numberofcities; j++) {
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
	ifstream in(_path);
	int maincitycount = 0;
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
			if (currentCity == maincitycount)
				maincitycount++;
			distanceMatrix[currentCity][maincitycount] = d;
			maincitycount++;
			if (maincitycount >= _numberofcities) {
				currentCity++;
				maincitycount = 0;
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
	return numberofcities;
}

void XMLData::printPheromoneMatrix()
{
	cout.precision(9);

	for (int i = 0; i < numberofcities; ++i) {
		for (int j = 0; j < numberofcities; ++j) {
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

	for (int i = 0; i < numberofcities; ++i) {
		for (int j = 0; j < numberofcities; ++j) {
			if (i == j)
				cout << setw(12) << fixed << "X";
			else
				cout << setw(12) << fixed << distanceMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
