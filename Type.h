/*
Henry Chang
hechang
Type.h
*/

#ifndef TYPE_H
#define TYPE_H

#include <string>

using namespace std;

class Type {
private:
public:
	// Constructor-Destructor
	// Default Constructor
	Type();

	// Destructor
	~Type();

	// Access Methods
	template<typename varType>
	virtual varType getValue() = 0;

	// Manipulation Methods
	template<typename varType>
	virtual void setValue( varType value) = 0;
};
#endif //!TYPE_H