#ifndef DIV_H
#define DIV_H
#include "ArithmeticOperation.h"
#include <vector>

using namespace std;

class Div : public ArithmeticOperation{
private:
	vector<int *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Div(vector<int *> & MIS_Args); // copy the mis_vector

	~Div();


	void doOperation(); // this will make use of the variable vector.

};




#endif