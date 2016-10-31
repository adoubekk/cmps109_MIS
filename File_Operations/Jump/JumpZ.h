//JumpZ.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if parameter passed in == 0;

#pragma once
#include <string>
#include "JumpOperation.h"
#include "../../Type_Classes/Numeric.h"
#include "../../Type_Classes/Real.h"

class JumpZ: public JumpOperation{
   public:
      JumpZ (std::string name, Parser* P_, Type* Var, bool Z);
      virtual bool jumpCondition();
   private:
      Type* Var;
      bool Z;
};