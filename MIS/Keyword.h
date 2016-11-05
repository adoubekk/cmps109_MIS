//Keyword.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
// Abstract base class for all keywords processed by the MIS

#pragma once
#include <map>
#include <vector>
#include <string>
#include "../Type_Classes/Type.h"

class Keyword {
   public:
      virtual Keyword* clone(vector<string> rawData, map<string, Type*> typeVars) = 0;
      virtual void initialize(vector<string> rawData) = 0;
      virtual void execute() = 0;
   protected:
      map<string, Type*> &typeVars;
}