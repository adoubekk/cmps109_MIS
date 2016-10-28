#ifndef DIV_H
#define DIV_H
#include "ArithmeticOperations.h"
#include <vector>

using namespace std;

class Div : public ArithmeticOperations{
private:
	vector<int *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Div(vector<int *> & MIS_Args); // copy the mis_vector

	~Div();


	void doOperation(); // this will make use of the variable vector.

};




#endif