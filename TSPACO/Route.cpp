#include "Route.h"

vector<int> const & Route::get() const
{
	return this->theRoute;
}

void Route::setCity(int pos, int value)
{
	this->theRoute[pos] = value;
}

int const Route::getIndex(int index) const
{
	return this->theRoute[index];
}

void Route::printRoute()
{
	for each (int i in this->theRoute)
		cout << i << " ";
	cout << endl;
}
