/*
 * Out.cpp
 * Henry Chang
 */

#include "Out.h"
#include <iostream>
#include <sstream>

using namespace std;

Out::Out(){
}

Out::~Out(){
}

void Out::initialize(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser){
	string token;
	for(int i = 1; i < dataList.size(); i++){
		token = dataList[i];
		if(token[0] == '$'){
			cout << "Out.cpp printVariable()" << endl;
			printVariable(token, typeVars);
		}else if(token[0] == *singleQuote || token[0] == *doubleQuote){
            cout << "Out.cpp printStringLiteral()" << endl;
			printStringLiteral(token);
		}else{ // numeral value
			cout << "Out.cpp printNumeralLiteral()" << endl;
			printNumeralLiteral(token);
			cout<< endl;
		}
	}
	outString = strStream.str();
}

Keyword * Out::clone(vector<string> dataList, map<string, Type*> & typeVars, Parser * MISParser){
	Out * out = new Out();
	out->initialize(dataList, typeVars, NULL);
	return out;
}

void Out::execute(){
	cout << outString;
}

void Out::printVariable(string str, map<string, Type*> & typeVars){
	if(typeVars.count(str) > 0){
		Type * mapToken = typeVars[str];
		string temp;
	    mapToken->getValue(&targetValue);
	    temp = targetValue.str();
	    strStream << temp << endl;
	}else{ // variable is not in the map
		// throw nullVariableException()
	}
}

void Out::printStringLiteral(string str){
	for(unsigned i = 1; i < str.length() - 1; i++){
		if(str.at(i) == '\\'){
			if(str.at(i+1) == 'n' || str.at(i+1) == 'b'){
				strStream << endl;
				i++;
				continue;
			}else if(str.at(i+1) == 't'){
				strStream << "    ";
				i++;
				continue;
			}
		}else{
		    strStream << str.at(i);
		}
	}
}

void Out::printNumeralLiteral(string str){
	strStream << str << endl;
}
