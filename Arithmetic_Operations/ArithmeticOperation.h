#ifndef ARITHMETICOPERATION_H
#define ARITHMETICOPERATION_H

#include "../Type_Classes/Type.h"
#include <vector>
#include <map>

using namespace std;

class ArithmeticOperation{

public:

	//virtual void doOperation() = 0; // pure virtual method. Needs to be implemented by all inheriters/children

	virtual void execute() = 0;

	virtual void initialize(vector<string>& args, map<string, Type*>& variables) = 0;

	virtual ArithmeticOperation* clone(vector<string>& args, map<string, Type*>& variables) = 0;
};


#endif