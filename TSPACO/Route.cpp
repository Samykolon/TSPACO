#include "Route.h"

vector<int> const & Route::get() const
{
	return this->route;
}

void Route::setCity(int pos, int value)
{
	this->route[pos] = value;
}

int const Route::getIndex(int index) const
{
	return this->route[index];
}

void Route::printRoute()
{
	for each (int i in this->route)
		cout << i << " ";
	cout << endl;
}
