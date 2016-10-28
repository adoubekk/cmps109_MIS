/*
Henry Chang
hechang
Type.h
*/

#ifndef TYPE_H
#define TYPE_H

#include <string>

using namespace std;

template<class varType>

class Type {
private:
public:
	// Constructor-Destructor
	// Default Constructor
	Type();

	// Destructor
	~Type();

	// Access Methods
	varType getValue();

	// Manipulation Methods
	void setValue( varType value);
};
#endif //!TYPE_H