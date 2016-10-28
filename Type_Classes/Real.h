/*
Henry Chang
hechang
Real.h
*/

#ifndef REAL_H
#define REAL_H
#include <string>
#include "Type.h"

using namespace std;

class Real: public Type {
private:
	double Number;
	string name;
public:

	// Constructor-Destructor
	// Default Constructor
	Real();

	// Parameterized Constructor with name of Real and value
	Real(string varName, double value);

	// Destructor
	~Real();

	// Access Methods
	double getValue();

	// Manipulation Methods
	void setValue(double value);
};

#endif // !REAL_H

