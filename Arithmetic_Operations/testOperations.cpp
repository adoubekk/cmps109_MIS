#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Div.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){

	int* a = new int(5);
	int* b = new int (6);
	int* c = new int (30);
	vector<int *> v;
	v.push_back(a);
	v.push_back(b);

	Add* AddObject = new Add(v); // create a new Add operation object with a vector of int pointers
	AddObject->doOperation();
	cout << * a << endl; // dereferencing a should now be 11 instead of 5;

	Sub* SubObject = new Sub(v);
	SubObject->doOperation(); // 11 - 6.
	cout << * a << endl; 

	Mult* MultObject = new Mult(v); // v = 5, 6
	MultObject->doOperation();
	cout << * a << endl;

	vector<int *> v2;
	v2.push_back(a); //30
	v2.push_back(c);//30
	Div* DivObject = new Div(v2);
	DivObject->doOperation();
	cout << *a << endl;

	v2.push_back(b); // (1, 30 , 6) testing with multiple args.
	Add* AddObject2 = new Add(v2);
	AddObject2->doOperation();
	cout << * a << endl;

	free(a); // im getting a memory leak somewhere.. don't know why
	free(b);
	free(AddObject);
	free(SubObject);
	free(MultObject);
	free(DivObject);
	

	

}