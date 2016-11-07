//JumpZ.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Jump to a specific label in the input stream of the parser passed in
//only if parameter passed in == 0;

#include <string>
#include "JumpOperation.h"
#include "../../Type_Classes/Numeric.h"
#include "../../Type_Classes/Real.h"

class JumpZ: public JumpOperation{
   public:
      JumpZ (std::string name, Parser* P_, Type* Var, bool Z);
      JumpZ ();
      virtual bool jumpCondition();
      virtual Keyword* clone(std::vector<std::string> rawData, std::map<std::string, Type*> *typeVars, Parser* P);
      virtual void initialize(std::vector<std::string> rawData, std::map<std::string, Type*> *typeVars, Parser* P);
   private:
      Type* Var;
      bool Z;
};