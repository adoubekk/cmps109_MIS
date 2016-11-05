/*
Henry Chang
hechang
Char.h
*/
#ifndef CHAR_H
#define CHAR_H
#include <string>
#include <vector>
#include <map>
#include "Type.h"

using namespace std;

class Char : public Type{
private:
	char value;
	string name;
	char myType;
	map<string, Type *> &typeMap;
public:
	// Constructor-Destructor
	// Default Constructor
	Char();

	// Parameterized Constructor with name of Char and value
	Char(string varName, char value);

	// Destructor
	virtual ~Char();

	// Access Methods
	virtual void getValue(void * ptr);

	virtual void getType(void * ptr);

	// Manipulation Methods
	virtual void setValue(void * value);

	// Other
	void initialize(vector<string> dataList);
	Keyword * clone(vector<string> dataList, map<string, Type*> &variableType);
	void Numeric::execute();
};
#endif // !CHAR_H
