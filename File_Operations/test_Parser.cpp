//test_Parser.cpp

#include "Parser.h"
#include <iostream>

using namespace std;

string printVector(vector<string> line);

int main(){
   Parser myParser("test.mis");
   vector<string> nextLine;
   while (myParser.hasNextLine()) {
		nextLine = myParser.getNextLine();
		cout << printVector(nextLine) <<endl;
   }
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