#pragma once
#include <vector>
#include "City.h"

using namespace std;

// Klasse, die die Route darstellt, die eine Ameise generiert - sie besteht im wesentlichen aus einem Int-Vector mit den Indizies der Städte

class Route {

public:

	Route(int _size) : route(_size) { }	

	vector<int> const &get() const;
	void setCity(int pos, int value);
	int const getIndex(int index) const;

	void printRoute();	

private:

	vector<int> route;
	int cityindex;

};
