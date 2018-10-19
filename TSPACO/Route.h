#pragma once
#include <vector>
#include "City.h"
#include "Data.h"

using namespace std;

class Route {

public:

	Route(int size) : theRoute(size) { }
	
	vector<int> const &get() const { return theRoute; }
	void setCity(int pos, int value) { theRoute[pos] = value; }
	int const getIndex(int index) const { return theRoute[index]; }
	
	void printRoute() {
		for each (int i in theRoute)
			cout << i << " " << endl;
	}
	

private:

	vector<int> theRoute;
	int cityIndex;



};
