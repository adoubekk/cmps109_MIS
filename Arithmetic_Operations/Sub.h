#ifndef SUB_H
#define SUB_H
#include "ArithmeticOperations.h"
#include <vector>

using namespace std;

class Sub : public ArithmeticOperations{
private:
	vector<int *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Sub(vector<int *> & MIS_Args); // copy the mis_vector

	~Sub();


	void doOperation(); // this will make use of the variable vector.

};




#endif