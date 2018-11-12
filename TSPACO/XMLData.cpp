#include "XMLData.h"
#include <regex>
#include <string>
#include <iostream>


XMLData::XMLData(string _path)
{
	string nbline;
	ifstream nbin(_path);
	while (getline(nbin, nbline)) {
		std::string nbtmp;

		for (int i = 0; i < nbline.length(); i++)
		{
			if (nbline[i] == ' ' && nbtmp.size() == 0)
			{
			}
			else
			{
				nbtmp += nbline[i];
			}
		}

		if (nbtmp.find("name") != std::string::npos) {
			string strNumber = nbtmp;
			std::size_t const n = strNumber.find_first_of("0123456789");
			if (n != std::string::npos)
			{
				std::size_t const m = strNumber.find_first_not_of("0123456789", n);
				strNumber = strNumber.substr(n, m != std::string::npos ? m - n : m);
			}

			numberofcities = stoi(strNumber);
		}
	}

	cityVector.reserve(numberofcities);
	for (int k = 0; k < numberofcities; k++)
		cityVector.push_back(City(to_string(k), 0.0, 0.0));

	srand(time(NULL) - _getpid());

	double random, pheromonerandom;

	pheromoneMatrix.assign(numberofcities, vector<double>(numberofcities, 0));
	distanceMatrix.assign(numberofcities, vector<double>(numberofcities, 0));

	for (int i = 0; i < numberofcities; i++) {
		for (int j = 0; j < numberofcities; j++) {
			if (pheromoneMatrix[j][i] == 0 && i != j) {
				random = (rand() % 1000);
				pheromonerandom = random / 1000 * PHEROMONEINIT;
				pheromoneMatrix[i][j] = 0.01; //pheromonerandom;
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

		if (begindata && numberofcities != 0) {
			size_t pos = tmp.find("\"");
			string doubletmp = tmp.substr(pos + 1, 21);
			double d = stod(doubletmp);
			if (currentCity == maincitycount)
				maincitycount++;
			distanceMatrix[currentCity][maincitycount] = d;
			maincitycount++;
			if (maincitycount >= numberofcities) {
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
