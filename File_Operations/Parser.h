//Parser.h
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Reads in .mis files and returns appropriate information to the MIS system

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Label.h"

class Parser{
   public:
      Parser(std::string filename);
      ~Parser();
      std::vector<std::string> getNextLine();
      void goToPos(std::string name);
      void setLabel(std::string name);
      bool hasNextLine();
   private:
      std::ifstream stream;
      std::vector<Label> labels;
};