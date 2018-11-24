#include "City.h"

City::City(string _name, double _latitude, double _longitude)
{
	name = _name;
	longitude = _longitude * (PI / 180.0);
	latitude = _latitude * (PI / 180.0);
}

const string City::getName() const
{
	return this->name;
}

double City::getLatitude()
{
	return this->latitude;
}

double City::getLongitude()
{
	return this->longitude;
}

// Berechnet Distanz zwischen zwei Städten aus, wenn Koordinaten in Dezimalschreibweise vorliegen

double City::measureDistance(City _ACity, City _BCity)
{
	double deltaLongitude = (_ACity.getLongitude() - _BCity.getLongitude());
	double deltaLatitude = (_ACity.getLatitude() - _BCity.getLatitude());
	double x = pow(sin(deltaLatitude / 2.0), 2.0) +
		cos(_BCity.getLatitude()) * cos(_ACity.getLatitude()) * pow(sin(deltaLongitude / 2.0), 2.0);
	return earthradius * 2.0 * atan2(sqrt(x), sqrt(1.0 - x));
}

// Gibt Stadt aus

void City::printCity()
{
	cout << name << " | " << longitude << " | " << latitude << endl;
}
