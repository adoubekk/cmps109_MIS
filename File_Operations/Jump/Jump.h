//Jump.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in

#pragma once
#include <string>
#include "../Parser.h"

class Jump{
   public:
      Jump(std::string name, Parser* P_);
      void execute();
   private:
      std::string name;
      Parser* P;
};