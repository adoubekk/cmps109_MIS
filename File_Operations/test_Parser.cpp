//test_Parser.cpp

#include "Jump.h"
#include "Parser.h"
#include <iostream>

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
   
   Jump J("LAB1",myParser);
   J.execute();
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