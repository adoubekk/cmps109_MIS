//JumpZ.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream
//only if parameter passed in == 0;

#include "JumpZ.h"

using namespace std;

JumpZ::JumpZ(string name, Parser* P_, Type* Var){
   this->P = P_;
   this->name = name;
   this->Var = Var;
}

bool JumpZ::jumpCondition(){
   double val;
   Var->getValue(&val);
   return (val == 0);
}