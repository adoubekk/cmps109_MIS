//test_Parser.cpp

#include "Parser.h"
#include <iostream>

using namespace std;

int main(){
   Parser myParser("test.mis");
   vector<string> nextLine = myParser.getNextLine();
   cout << nextLine[0]  << nextLine[1] << endl;
   //nextLine = myParser.getNextLine();
   //cout << nextLine << endl;
}