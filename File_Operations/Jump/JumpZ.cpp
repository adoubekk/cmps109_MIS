//JumpZ.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream
//only if parameter passed in == 0;

#include "JumpZ.h"

using namespace std;

JumpZ::JumpZ(string name, Parser* P_, Type* Var, bool Z){
   this->P = P_;
   this->name = name;
   this->Var = Var;
   this->Z = Z;
}


JumpZ::JumpZ(){}

bool JumpZ::jumpCondition(){
   double val;
   Var->getValue(&val);
   if (Z) {
      return (val == 0);
   } else {
      return (val != 0);
   }
}

Keyword* JumpZ::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpZ * jump = new JumpZ();
   jump->initialize(rawData,typeVars,P);
   return jump;
}

void JumpZ::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   if (rawData.size() > 1){
      this->name = rawData[1];
      this->P = P;
   } else {
      //throw new SyntaxException()
   }
}