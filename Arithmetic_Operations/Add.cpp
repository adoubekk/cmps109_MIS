#include "Add.h"
#include <cstdarg>
#include <iostream>

Add::Add(){};

template<class Last> Add::Add(Last last) { variables.push_back(last);}

template<class First, class ... rest>
Add::Add(First n, rest ... theRest) : Add(theRest...) {

	variables.push_back(n);

}

auto Add::doOperation(){}; // not implemented yet.

int main(){

	Add* AddObject = new Add(3,4,5);
	int a;
    a = AddObject->variables.back();
	std::cout << a << "\n";
	AddObject->variables.pop_back();
	a = AddObject->variables.back();
	std::cout << a << "\n";
	AddObject->variables.pop_back();
	a = AddObject->variables.back();
	std::cout << a << "\n";

}