#ifndef MULT_H
#define MULT_H
#include "ArithmeticOperations.h"
#include <vector>

using namespace std;

class Mult : public ArithmeticOperations{
private:
	vector<int *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Mult(vector<int *> & MIS_Args); // copy the mis_vector

	~Mult();


	void doOperation(); // this will make use of the variable vector.

};




#endif