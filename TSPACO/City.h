#pragma once
#include <string>
#include <math.h>
#include <iostream>

using namespace std;

#define RADIUS 6378.137
#define PI 3.14159265358979323846

class City {

public:
	City(string _name, double _latitude, double _longitude) {
		name = _name;
		longitude = _longitude * PI / 180.0;
		latitude = _latitude * PI / 180.0;
	}
	~City() { };

private:
	double longitude;
	double latitude;
	string name;
	double earthRadius = RADIUS;

public:
	const string getName() const { return name; }
	double getLatitude() { return latitude; }
	double getLongitude() { return longitude; }

	double measureDistance(City _ACity, City _BCity) {
		double deltaLongitude = (_ACity.getLongitude() - _BCity.getLongitude());
		double deltaLatitude = (_ACity.getLatitude() - _BCity.getLatitude());
		double x = pow(sin(deltaLatitude / 2.0), 2.0) +
			cos(_BCity.getLatitude()) * cos(_ACity.getLatitude()) * pow(sin(deltaLongitude / 2.0), 2.0);
		return earthRadius * 2.0 * atan2(sqrt(x), sqrt(1.0 - x));
	}
	void printCity() { cout << name << " | " << longitude << " | " << latitude << endl; }
};

