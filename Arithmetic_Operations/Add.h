#ifndef ADD_H
#define ADD_H
#include <vector>

class Add{
private:
	//std::vector<int> variables; // right now this is <int> should change to <Type> when implemented..
public:
	std::vector<int> variables; 

	template<class First, class ... rest> Add(First n, rest ... theRest); // recursivly striping the arguments

	template<class Last>Add(Last last);

	Add();


	auto doOperation(); // this will make use of the variable vector.

};




#endif