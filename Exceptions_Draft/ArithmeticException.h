#ifndef ARITHMETICEXCEPTION_H
#define ARITHMETICEXCEPTION_H
#include "Exception.h"
#include <stdlib.h>
#include <string>

using namespace std;

class ArithmeticException : public Exception {

public:
	ArithmeticException(string Estr); //specific exception
};

#endif