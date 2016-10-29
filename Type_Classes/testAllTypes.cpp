#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
#include "Type.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){

	Numeric StackNumeric("myStackN", 6);
	Numeric* myNumeric = new Numeric("HeapNum", 5);
	Type* myNumericT = new Numeric("TypePtrNumeric", 9);
	int a = 0;
	int b = 0;
	int c = 0;

	StackNumeric.getValue(&a);
	myNumeric->getValue(&b);
	myNumericT->getValue(&c);

	cout << a << endl; //6
	cout << b << endl; //5
	cout << c << endl; //9

    //------------------------------------------------------------------------
    //Reals
    
	Real StackReal("myStackR", 6.5);
	Real* myReal = new Real("HeapReal", 5.2);
	Type* myRealT = new Real("TypePtrReal", 9.4);
	double d = 0;
	double e = 0;
	double f = 0;

	StackReal.getValue(&d);
	myReal->getValue(&e);
	myRealT->getValue(&f);

	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

	//-------------------------------------------------------------------------
	//Chars

	Char StackChar("myStackC", 'a');
	Char* myChar = new Char("HeapC", 'b');
	Type* myCharT = new Char("TypePtrC", 'c');
	char g = 0;
	char h = 0;
	char i = 0;

	StackChar.getValue(&g);
	myChar->getValue(&h);
	myCharT->getValue(&i);

	cout << g << endl;
	cout << h << endl;
	cout << i << endl;

	//---------------------------------------------------------------------------
	//Strings

	String StackString("myStackS", "this is a",9);
	String* myString = new String("HeapString", "this is b", 9);
	Type* myStringT = new String("TypePtrString", "this is c", 9);
	string j;
	string k;
	string l;

	StackString.getValue(&j);
	myString->getValue(&k);
	myStringT->getValue(&l);

	char x;
	char y;
	char z;

	x = StackString.getChar(8);
	y = myString->getChar(8);
	myStringT->setChar(8, 'w');
	z = myStringT->getChar(8);

	cout << j << endl;
	cout << k << endl;
	cout << l << endl;

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

}