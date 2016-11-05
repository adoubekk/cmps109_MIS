//JumpOperation.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Abstract Base class for file input stream operations

#pragma once
#include <string>
#include "../Parser.h"
#include "../../MIS/Keyword.h"

class JumpOperation: public Keyword{
   public:
      virtual void execute() final;
      virtual bool jumpCondition() = 0;
   protected:
      std::string name;
      Parser* P;
};