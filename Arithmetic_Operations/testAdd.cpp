#include "Add.h"
#include <cstdarg>
#include <iostream>
#include <vector>

int main(){

	int* a = new int(5);
	int* b = new int (6);
	std::vector<int *> v;
	v.push_back(a);
	v.push_back(b);
	Add* AddObject = new Add(v); // create a new Add operation object with a vector of int pointers
	AddObject->doOperation();
	cout << * a << endl; // dereferencing a should now be 11 instead of 5;

	free(a); // im getting a memory leak somewhere.. don't know why
	free(b);
	free(AddObject);
	

	

}