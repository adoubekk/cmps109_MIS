//Label.cpp
//Aaron Doubek-Kraft, adoubekk@ucsc.edu
//CMPS 109 Fall '16
//MIS Project
//Sets a label a specific place in the input stream

#include "Label.h"

using namespace std;

Label::Label(int pos, string name){
   this->position = pos;
   this->name = name;
}

int Label::getPosition(){
   return position;
}

string Label::nameOf(){
   return name;
}