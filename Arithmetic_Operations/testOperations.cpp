#include "Add.h"
#include "Sub.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){

	int* a = new int(5);
	int* b = new int (6);
	vector<int *> v;
	v.push_back(a);
	v.push_back(b);
	Add* AddObject = new Add(v); // create a new Add operation object with a vector of int pointers
	AddObject->doOperation();
	cout << * a << endl; // dereferencing a should now be 11 instead of 5;

	Sub* SubObject = new Sub(v);
	SubObject->doOperation(); // 11 - 6.
	cout << * a << endl; 

	free(a); // im getting a memory leak somewhere.. don't know why
	free(b);
	free(AddObject);
	

	

}