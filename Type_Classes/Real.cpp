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

void Real::initialize(vector<string> dataList, map<string, Type*> * typeVars, Parser * MISParser){
	this->varMap = typeVars;
	name = dataList[1];
	number = stod(dataList[2]);
}

Keyword * Real::clone(vector<string> dataList, map<string, Type*> * typeVars, Parser * MISParser){
	Real * real = new Real();
	real->initialize(dataList,typeVars,MISParser);
	return real;
}

void Real::execute(){
	(*varMap)[name] = this;
}
