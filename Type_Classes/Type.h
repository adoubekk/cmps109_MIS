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
	// Access Methods
	virtual varType getValue() = 0;

	// Manipulation Methods
	virtual void setValue( varType value) = 0;
};
#endif //!TYPE_H
