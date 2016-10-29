/*
Henry Chang
hechang
Char.h
*/
#ifndef CHAR_H
#define CHAR_H
#include <string>
#include "Type.h"

using namespace std;

class Char : public Type<char> {
private:
	char value;
	string name;
public:
	// Constructor-Destructor
	// Default Constructor
	Char();

	// Parameterized Constructor with name of Char and value
	Char(string varName, char value);

	// Destructor
	virtual ~Char();

	// Access Methods
	Char getValue();

	// Manipulation Methods
	void setValue(char value);
};
#endif // !CHAR_H
