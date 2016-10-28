#include "Real.h"
#include <string>

using namespace std;

Real::Real() {}

Real::Real(string varName, double value) {
	name = varName;
	number = value;
}

Real::~Real() {
}

double Real::getValue() {
	return number;
}

void Real::setValue(double value) {
	number = value;
}
