//JumpOperation.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Abstract Base class for file input stream operations

#pragma once
#include <string>
#include "../Parser.h"

class JumpOperation{
   public:
      virtual void execute() final;
      virtual bool jumpCondition() = 0;
      virtual JumpOperation* clone
   protected:
      std::string name;
      Parser* P;
};