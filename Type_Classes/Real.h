/*
Henry Chang
hechang
Numeric.h
*/

#ifndef REAL_H
#define REAL_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

using namespace std;

class Real: public Type{
private:
	double number;
	string name;
	char myType;
	map<string, Type *> &typeMap;
public:

	

    // Constructor-Destructor
	// Default Constructor
	Real();

	// Parameterized Constructor with name of Numeric and value
	Real(string varName, double value);

	// Destructor
	virtual ~Real();

	// Access Methods
	virtual void getValue(void* ptr);

	virtual void getType(void* ptr);
	

	// Manipulation Methods
	virtual void setValue(void* value_ptr);

	// Other
	virtual void initialize(vector<string> dataList);
	virtual Keyword * clone(vector<string> dataList, map<string, Type *> &variableType);
	virtual void execute();
};

#endif // !NUMERIC_H

