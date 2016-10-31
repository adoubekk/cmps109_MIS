//JumpCp.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if the logic specified is true -- Comparison Jump
//Logic can be GT(>) LT(<) GTE (>=) or LTE (<=)

#pragma once
#include <string>
#include "JumpOperation.h"
#include "../../Type_Classes/Numeric.h"
#include "../../Type_Classes/Real.h"

class JumpCp: public JumpOperation{
   public:
      enum Logic{GT,LT,GTE,LTE};
      JumpCp (std::string name, Parser* P_, Type* Var1, Type* Var2, Logic L);
      virtual bool jumpCondition();
   private:
      Type* Var1;
      Type* Var2;
      Logic L;
};