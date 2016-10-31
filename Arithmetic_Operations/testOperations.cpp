#include "Add.h"
#include "Sub.h"
#include "Mult.h"
#include "Div.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"

int main(){

	//-------------------------------------------------------------
	//Add Operation
	Type * myNumeric = new Numeric("MyNum", 74);
	Type * myNumeric1 = new Numeric("Num1", 6);
	Type * myNumeric2 = new Numeric("Num2", 4);

	Type * myReal = new Real("MyReal", 6.5);
	Type * myReal1 = new Real("MyReal1", 5.5);
	Type * myReal2 = new Real("MyReal2", 5);

	vector<Type *> numVariables;
	vector<Type *> realVariables;

	numVariables.push_back(myNumeric);
	numVariables.push_back(myNumeric1);
	numVariables.push_back(myNumeric2);

	realVariables.push_back(myReal);
	realVariables.push_back(myReal1);
	realVariables.push_back(myReal2);

	ArithmeticOperation* AddObject = new Add(numVariables);
	Add* AddObject2 = new Add(realVariables);

	AddObject->doOperation();
	AddObject2->doOperation();
	

	int a = 0;
	double b = 0;

	myNumeric->getValue(&a);
	myReal->getValue(&b);


	cout << "Add 6 and 4: " << a << endl;
	cout << "Add 5.5 and 5: " << b << endl;


	//-----------------------------------------------------------------------------
	//Sub Operation 

	Type * myNumeric3 = new Numeric("MyNum", 74);
	Type * myNumeric4 = new Numeric("Num1", 6);
	Type * myNumeric5 = new Numeric("Num2", 4);

	Type * myReal3 = new Real("MyReal", 6.5);
	Type * myReal4 = new Real("MyReal1", 5.5);
	Type * myReal5 = new Real("MyReal2", 5);

	vector<Type *> numVariables1;
	vector<Type *> realVariables1;

	numVariables1.push_back(myNumeric3);
	numVariables1.push_back(myNumeric4);
	numVariables1.push_back(myNumeric5);

	realVariables1.push_back(myReal3);
	realVariables1.push_back(myReal4);
	realVariables1.push_back(myReal5);

	ArithmeticOperation* SubObject = new Sub(numVariables1);
	ArithmeticOperation* SubObject2 = new Sub(realVariables1);

	//SubObject->doOperation();
	//SubObject2->doOperation();
	

	int c = 0;
	double d = 0;

	myNumeric3->getValue(&c);
	myReal3->getValue(&d);


	cout <<"Subtract 4 from 6: " << c << endl;
	cout << "Subtract 5 from 5.5: " << d << endl;





    /* this was the testing phase of int pointers instead of Type pointers
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
	free(DivObject);*/
	

	

}