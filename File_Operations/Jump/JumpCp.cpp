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
   double val1,val2;
   Var1->getValue(&val1);
   Var2->getValue(&val2);
   bool result = false;
   
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