#include "InvalidKeywordException.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// construct an Exception object and specify the type and specific error.
InvalidKeywordException:: InvalidKeywordException(string Estr): Error("Keyword Error: " + Estr) {}; // specific exception

InvalidKeywordException:: ~InvalidKeywordException() throw() {};

const char* InvalidKeywordException::what() const throw() {return Error.c_str();};


