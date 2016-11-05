//Jump.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream

#include "Jump.h"

using namespace std;

Jump::Jump(string name, Parser* P_){
   this->P = P_;
   this->name = name;
}

bool Jump::jumpCondition(){
   return true;
}

Keyword* clone(vector<string> rawData, map<string, Type*> &typeVars){
   Jump * jump = new Jump();
   jump->initialize(vector<string> rawData);
   return jump;
}

void initialize(vector<std::string> rawData){
   if (vector[1] != nullptr){
      this->name = vector[1];
   } else {
      //throw new SyntaxException()
   }
}