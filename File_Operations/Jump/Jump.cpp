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

void Jump::execute(){
   P->goToLabel(name);
}