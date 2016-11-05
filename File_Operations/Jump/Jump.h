//Jump.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in

#pragma once
#include "JumpOperation.h"

class Jump: public JumpOperation{
   public:
      Jump(std::string name, Parser* P_);
      virtual bool jumpCondition();
      virtual Keyword* clone(vector<std::string> rawData, map<std::string, Type*> &typeVars);
      virtual void initialize(vector<std::string> rawData);
};