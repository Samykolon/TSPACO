#pragma once
#include <fstream>
#include <sstream>
#include "City.h"

using namespace std;

const vector<City> convertCities() {
	
	vector<City> MyCities{ City("Boston", 42.3601, -71.0589), 
			City("Houston", 29.7604, -95.3698), 
			City("Austin", 30.2672, -97.7431), 
			City("San Francisco", 37.7749, -122.4194), 
			City("Denver", 39.7392, -104.9903), 
			City("Los Angeles", 34.0522, -118.2437),
			City("Chicago", 41.8781, -87.6298), 
			City("New York", 40.7128,-74.0059)};

	//vector<City> MyCities;
	ifstream file("TSPLIB/burma14.txt");

	double latitude;
	double longitude;
	string name;
	string line;
	bool start = false;

	if (file.is_open())
	{
		while (getline(file, line)) {
			if (line == "NODE_COORD_SECTION")
				start = true;
			if (line == "EOF")
				start = false;

			if (start == true && line != "NODE_COORD_SECTION")
			{
				istringstream ss(line);
				ss >> name >> latitude >> longitude;
				City city(name, latitude, longitude);
				//MyCities.push_back(city);
			}
		}
	}
	file.close();
	return MyCities;

}

