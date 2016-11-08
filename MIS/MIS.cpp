#include "MIS.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

MIS::MIS(){};
MIS::~MIS(){}


void MIS::makeParser(string fileName){

	MIS_Parser = new Parser(fileName);

}

void MIS::run(){

	vector<string> args;

	if(MIS_Parser == NULL){
		cout << "parser has not been created" << endl;
	}

	while(MIS_Parser->hasNextLine()){
		args = MIS_Parser->getNextLine();
		Keyword* KeywordObj = Keyword_Factory[args[0]];
		if(KeywordObj != NULL){
			try{
			KeywordObj = KeywordObj->clone(args, MIS_variables, MIS_Parser);
			KeywordObj->execute();
		}
		catch(exception& e){
			cout << e.what() << endl;
		}

		}
		else{
			cout << "Unidentified Keyword" << endl;
		}


	}
}
