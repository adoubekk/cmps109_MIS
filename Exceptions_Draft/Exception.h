#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdlib.h>
#include <string>

using namespace std;

class Exception {
private:
	string Exception_type;
	string Exception_str;

public:
	Exception(); //default unspecified exception
	Exception(string EstrType, string Estr); //specific exception

	virtual void print();
};

#endif