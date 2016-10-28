#include "Numeric.h"
#include <string>

using namespace std;

Numeric::Numeric() {}

Numeric::Numeric(string varName, int value){
	name = varName;
	number = value;
}


Numeric::~Numeric(){
}

int Numeric::getValue() {
	return number;
}

void Numeric::setValue(int value){
	number = value;
}
