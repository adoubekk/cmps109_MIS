#include "Numeric.h"
#include <string>

using namespace std;

Numeric::Numeric(){
	myType = 'N';
	name = "";
	number = 0;
	varMap = nullptr;

}

Numeric::Numeric(string varName, int value){
	myType = 'N';
	name = varName;
	number = value;
}


Numeric::~Numeric(){
}

void Numeric::getValue(void * ptr) {
	int* intPtr = static_cast<int*>(ptr);
	*intPtr = number;

}

void Numeric::getType(void * ptr){
	char* charPtr = static_cast<char*>(ptr);
	*charPtr = myType;
}

void Numeric::setValue(void* value_ptr){
	int* intPtr = static_cast<int*>(value_ptr);
	number = *intPtr;
}

void Numeric::initialize(vector<string> dataList, map<string, Type*> * typeVars, Parser * MISParser){
	varMap = typeVars;
	name = dataList[VARIABLENAME];
	number = stod(dataList[VARIABLEVALUE]);
}

Keyword * Numeric::clone(vector<string> dataList, map<string, Type*> * typeVars, Parser * MISParser){
	Numeric * numeric = new Numeric();
	numeric->initialize(dataList, typeVars, MISParser);
	return numeric;
}

void Numeric::execute(){
	(*varMap)[name] = this;
}
