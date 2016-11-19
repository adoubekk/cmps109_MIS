#include "InvalidIndexException.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// construct an Exception object and specify the type and specific error.
InvalidIndexException:: InvalidIndexException(string Estr): Error("Index Error: " + Estr) {}; // specific exception

InvalidIndexException:: ~InvalidIndexException() throw() {};

const char* InvalidIndexException::what() const throw() {return Error.c_str();};


