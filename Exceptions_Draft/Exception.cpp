#include "Exception.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
Exception::Exception(): Exception_str("Exception"), Exception_type("Unidentifiable"){};

Exception::Exception(string EstrType, string Estr): Exception_str(Estr), Exception_type(EstrType){}; // initialize a more specific exception

void Exception::print(){
	cout << Exception_type << " " << Exception_str << endl;

}