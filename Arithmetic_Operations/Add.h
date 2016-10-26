#ifndef ADD_H
#define ADD_H
#include <vector>

using namespace std;

class Add{
private:
	vector<int *> variables; // right now this is <int> should change to <Type> when implemented..
public:
	

	Add(vector<int *> & MIS_Args); // copy the mis_vector

	~Add();


	void doOperation(); // this will make use of the variable vector.

};




#endif