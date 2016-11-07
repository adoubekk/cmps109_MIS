//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Comparison Jump
//Logic can be GT(>) LT(<) GTE (>=) or LTE (<=)

#include "JumpCp.h"
#include <iostream>

using namespace std;

JumpCp::JumpCp(string name, Parser* P_, Type* Var1, Type* Var2, Logic L){
   this->P = P_;
   this->name = name;
   this->Var1 = Var1;
   this->Var2 = Var2;
   this->L = L;
}

bool JumpCp::jumpCondition(){
   char type1,type2;
   double val1_R,val2_R, val1,val2;
   int val1_N,val2_N;
   bool result = false;
   
   Var1->getType(&type1);
   Var2->getType(&type2);
   
   //type safety checking
   if (type1 == 'R'){
      Var1->getValue(&val1_R);
      val1 = val1_R;
   } else if (type1 == 'N'){
      Var1->getValue(&val1_N);
      val1 = (double) val1_N;
   } else {
      //throw invalid type exception
   }
   
   if (type2 == 'R'){
      Var2->getValue(&val2_R);
      val2 = val2_R;
   } else if (type2 == 'N'){
      Var2->getValue(&val2_N);
      val2 = (double) val2_N;
   } else {
      //throw invalid type exception
   }
   
   switch(this->L){
      case JumpCp::GT:
         result = (val1 > val2);
         break;
      case JumpCp::LT:
         result = (val1 < val2);
         break;
      case JumpCp::GTE:
         result = (val1 >= val2);
         break;
      case JumpCp::LTE:
         result = (val1 <= val2);
         break;
   }
   
   return result;
}

JumpCp::JumpCp(){}

Keyword* JumpCp::clone(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   JumpCp * jump = new JumpCp();
   jump->initialize(rawData,typeVars,P);
   return jump;
}

void JumpCp::initialize(std::vector<std::string> rawData, std::map<std::string, Type*> &typeVars, Parser* P){
   if (rawData.size() > 1){
      this->name = rawData[1];
      this->P = P;
   } else {
      //throw new SyntaxException()
   }
}