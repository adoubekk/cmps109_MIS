#include "MIS.h"
#include <stdlib.h>
#include <string>

using namespace std;

MIS::MIS(): gloabalCounter(0) {};
MIS::~MIS(){}


void MIS::makeParser(string fileName){

	Parser* MIS_Parser = new Parser(fileName);
	MIS_Parsers[gloabalCounter++] = MIS_Parser;

}

/*

MIS::constructType(vector<string> RawInput){
	
		if(RawInput[0] == "NUMERIC"){
			if (RawInput.size() != 3) {/*throw syntax error*} 
			MIS_variables[RawInput[1]] = new Numeric(RawInput[1], RawInput[2]);
		}
		if(RawInput[0] == "REAL"){
			if (RawInput.size() != 3) {/*throw syntax error*} 
			MIS_variables[RawInput[1]] = new Real(RawInput[1], RawInput[2]);
				}
		if(RawInput[0] == "CHAR"){
			if (RawInput.size() != 3) {/*throw syntax error*} 
			MIS_variables[RawInput[1]] = new Char(RawInput[1], RawInput[2]);
		}
		if(RawInput[0] == "STRING"){
			if (RawInput.size() != 4) {/*throw syntax error*}
			MIS_variables[RawInput[1]] = new String(RawInput[1], RawInput[3], RawInput[2]);
		}
	} */
