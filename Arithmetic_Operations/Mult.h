#ifndef MULT_H
#define MULT_H
#include "ArithmeticOperation.h"
#include "../Type_Classes/Type.h"
#include <vector>
#include <map>

using namespace std;

class Mult : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Mult(vector<Type *> & MIS_Args); // copy the mis_vector

	Mult();

	~Mult();


	void execute(); // this will make use of the variable vector.

    void initialize(vector<string>& args, map<string, Type*>& variables);

    ArithmeticOperation* clone(vector<string>& args, map<string, Type*>& variables);

};




#endif