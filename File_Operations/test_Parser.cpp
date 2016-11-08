//test_Parser.cpp

#ifndef TESTPARSER
#define TESTPARSER

#include "Jump/Jumps.h"
#include "Parser.h"
#include <iostream>
#include <map>
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"

using namespace std;

string printVector(vector<string> line);

int main(){
   Parser* myParser = new Parser("test.mis");
   vector<string> nextLine;
   map<string, Type*> Vars; // represents the variable storage in the MIS
	Vars["$myVar1"] = new Numeric("$myVar1" , 41);
	Vars["$myVar2"] = new Numeric("$myVar2", 30);
	Vars["$myVar3"] = new Real("$myVar3", 40.2);
	Vars["$myVar4"] = new Real("$myVar4", 50.1);
   map<string, Keyword*> Factory; //Made in china
   Factory["JMP"] = new Jump();
   Factory["JMPGTE"] = new JumpGTE();
   Factory["JMPLTE"] = new JumpLTE();
   Factory["JMPGT"] = new JumpGT();
   Factory["JMPLT"] = new JumpLT();
   Factory["JMPZ"] = new JumpZ();
   Factory["JMPNZ"] = new JumpNZ();
   
   while (myParser->hasNextLine()) {
		nextLine = myParser->getNextLine();
		if (nextLine[0].compare("LABEL") == 0) {
         myParser->setLabel(nextLine[1]);
		}
		cout << printVector(nextLine) <<endl;
   }
   vector<string> myLine1;
   myLine1.push_back("JMP");
   myLine1.push_back("LAB1");
   vector<string> myLine2;
   myLine2.push_back("JMPGTE");
   myLine2.push_back("LAB1");
   myLine2.push_back("$myVar1");
   myLine2.push_back("$myVar3");
   vector<string> myLine3;
   myLine3.push_back("JMPNZ");
   myLine3.push_back("LAB1");
   myLine3.push_back("$myVar1");
   Keyword* K1 = Factory["JMP"]->clone(myLine1,Vars,myParser);
   Keyword* K2 = Factory["JMPLT"]->clone(myLine2,Vars,myParser);
   Keyword* K3 = Factory["JMPNZ"]->clone(myLine3,Vars,myParser);
   K3->execute();
   cout << endl;
   while (myParser->hasNextLine()) {
		nextLine = myParser->getNextLine();
		cout << printVector(nextLine) << endl;
   }
   delete(myParser);
}

string printVector(vector<string> line){
	string result = "[";
	int n = line.size();
	//char temp;
	for (int i = 0; i < n; i++){
		result += line[i];
		result += (i < n-1)?(','):(']');
	}
	
	return result;
}

#endif