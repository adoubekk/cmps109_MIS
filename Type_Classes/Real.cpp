#include "Real.h"
#include <string>

using namespace std;

Real::Real() {}

Real::Real(string varName, double value) {
	myType='R';
	name = varName;
	number = value;
}

Real::~Real() {
}

void Real::getValue(void * ptr) {
	double* DPtr = static_cast<double*>(ptr);
	*DPtr = number;
}

void Real::getType(void * ptr){
	char* charPtr = static_cast<char*>(ptr);
	*charPtr = myType;
}

void Real::setValue(void * ptr) {
	double* DPtr = static_cast<double*>(ptr);
	number = *DPtr;
}

void Real::initialize(vector<string> dataList){
	name = dataList[0];
	number = dataList[1];
}

Keyword * Real::clone(vector<string> dataList, map<string, Type*> &variableType){
	typeMap = variableType;
	Real * real = new Numeric();
	real->initialize(dataList);
	return real;
}

void Real::execute(){
	typeMap[name] = this;
}
