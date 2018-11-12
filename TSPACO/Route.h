#pragma once
#include <vector>
#include "City.h"

using namespace std;

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
