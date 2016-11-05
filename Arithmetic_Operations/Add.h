#ifndef ADD_H
#define ADD_H
#include "../Type_Classes/Type.h"
#include "ArithmeticOperation.h"
#include <vector>
#include <map>

using namespace std;

class Add : public ArithmeticOperation{
private:
	vector<Type *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Add(vector<Type *> & MIS_Args); // copy the mis_vector

	Add();

	~Add();


    void execute(); // this will make use of the variable vector.

    void initialize(vector<string>& args, map<string, Type*>& variables);

    ArithmeticOperation* clone(vector<string>& args, map<string, Type*>& variables);

};




#endif