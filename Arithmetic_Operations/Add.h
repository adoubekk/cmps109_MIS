#ifndef ADD_H
#define ADD_H
#include "../Type_Classes/Type.h"
#include "ArithmeticOperations.h"
#include <vector>

using namespace std;

class Add : public ArithmeticOperations{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Add(vector<Type *> & MIS_Args); // copy the mis_vector

	~Add();


	void doOperation(); // this will make use of the variable vector.

};




#endif