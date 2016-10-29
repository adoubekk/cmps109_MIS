/*
Henry Chang
hechang
String.h
*/
#ifndef STRING_H
#define STRING_H
#include <string>
#include "Type.h"

using namespace std;

class String : public Type<string> {
private:
	int length;
	string value;
	string name;
public:
	// Constructor-Destructor
	// Default Constructor
	String();

	// Parameterized Constructor with name of String and value
	String(string varName, string value);

	// Destructor
	virtual ~String();

	// Access Methods
	string getValue();
	int getLength();

	// Manipulation Methods
	void setValue(string value);
};
#endif // !STRING_H


