#ifndef DIV_H
#define DIV_H
#include "ArithmeticOperation.h"
#include "../Type_Classes/Type.h"
#include <vector>

using namespace std;

class Div : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Div(vector<Type *> & MIS_Args); // copy the mis_vector

	~Div();


	void doOperation(); // this will make use of the variable vector.

};




#endif