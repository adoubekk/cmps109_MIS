/*
 * StringTest.cpp
 *      Henry Chang
 *      hechang
 */

#include "String.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	String* sentence;
	string input = "This is a test sentence.";
	string output;
	string variable = "testString";

	sentence = new String( variable, input );
	output = sentence->getValue();
	cout << output << "\n";
	cout << "Length of the string: " << sentence->getLength() << endl;
	sentence->setValue("Test sentence has been changed.");
	output = sentence->getValue();
	cout << output << "\n";
	delete sentence;
	return 0;
}


