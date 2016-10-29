//Label.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Sets a label a specific place in the input stream

#pragma once
#include <string>

class Label{
   public:
      Label(int pos, std::string name);
      int getPosition();
      std::string nameOf();
   private:
      int position;
      std::string name;
};