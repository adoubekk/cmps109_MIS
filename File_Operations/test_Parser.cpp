//test_Parser.cpp

#include "Jump/Jumps.h"
#include "Parser.h"
#include <iostream>
#include "../Type_Classes/Numeric.h"
#include "../Type_Classes/Real.h"

using namespace std;

string printVector(vector<string> line);

int main(){
   Parser* myParser = new Parser("test.mis");
   vector<string> nextLine;
   while (myParser->hasNextLine()) {
		nextLine = myParser->getNextLine();
		if (nextLine[0].compare("LABEL") == 0) {
         myParser->setLabel(nextLine[1]);
		}
		cout << printVector(nextLine) <<endl;
   }
   Real* R1 = new Real("R1", 4.0);
   Real* R2 = new Real("R2", 3.0);
   JumpZ J("LAB1",myParser,R1,false);
   Jump J2("LAB1",myParser);
   JumpCp J3("LAB1",myParser,R1,R2,JumpCp::GTE);
   J3.execute();
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