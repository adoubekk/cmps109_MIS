#include "ArithmeticException.h"
#include "Exception.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// construct an Exception object and specify the type and specific error.
ArithmeticException:: ArithmeticException(string Estr): Exception((string)"ArithmeticException",Estr) {}; // specific exception


