/*
Henry Chang
hechang
Numeric.h
*/

#ifndef NUMERIC_H
#define NUMERIC_H
#include <string>
#include "Type.h"

using namespace std;

class Numeric: public Type<int>{
private:
	int number;
	string name;
public:

    // Constructor-Destructor
	// Default Constructor
	Numeric();

	// Parameterized Constructor with name of Numeric and value
	Numeric(string varName, int value);

	// Destructor
	virtual ~Numeric();

	// Access Methods
	int getValue();

	// Manipulation Methods
	void setValue(int value);
};

#endif // !NUMERIC_H

