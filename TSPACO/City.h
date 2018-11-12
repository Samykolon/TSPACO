#pragma once
#include <string>
#include <mutex>
#include <math.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <process.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define RADIUS 6378.137
#define PI 3.14159265358979323846

class City {

public:
	City(string _name, double _latitude, double _longitude);
	~City() { };

private:
	double longitude;
	double latitude;
	string name;
	double earthradius = RADIUS;

public:
	const string getName() const;
	double getLatitude();
	double getLongitude();

	double measureDistance(City _ACity, City _BCity);
	void printCity();
};

