#include "MIS.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

MIS::MIS(){
   Keyword_Factory["NUMERIC"] = new Numeric();
   Keyword_Factory["REAL"] = new Real();
   Keyword_Factory["CHAR"] = new Char();
   Keyword_Factory["STRING"] = new String();
   Keyword_Factory["ADD"] = new Add();
   Keyword_Factory["SUB"] = new Sub();
   Keyword_Factory["DIV"] = new Div();
   Keyword_Factory["MULT"] = new Mult();
   Keyword_Factory["ASSIGN"] = new Assign();
   //Keyword_Factory["OUT"] = new Out();
   //Keyword_Factory["SET_STR_CHAR"] = new SetStrChar();
   //Keyword_Factory["GET_STR_CHAR"] = new GetStrChar();
   Keyword_Factory["JMP"] = new Jump();
   Keyword_Factory["JMPGTE"] = new JumpGTE();
   Keyword_Factory["JMPLTE"] = new JumpLTE();
   Keyword_Factory["JMPGT"] = new JumpGT();
   Keyword_Factory["JMPLT"] = new JumpLT();
   Keyword_Factory["JMPZ"] = new JumpZ();
   Keyword_Factory["JMPNZ"] = new JumpNZ();
   Keyword_Factory["LABEL"] = new Label();
   //Keyword_Factory["SLEEP"] = new Sleep();   
};

MIS::~MIS(){
}


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
