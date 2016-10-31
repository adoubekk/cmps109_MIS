#ifndef SUB_H
#define SUB_H
#include "ArithmeticOperation.h"
#include "../Type_Classes/Type.h"
#include <vector>

using namespace std;

class Sub : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Sub(vector<Type *> & MIS_Args); // copy the mis_vector

	~Sub();


	void doOperation(); // this will make use of the variable vector.

};




#endif