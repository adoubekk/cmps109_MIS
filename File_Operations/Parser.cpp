// Parser.cpp
// Aaron Doubek-Kraft, adoubekk@ucsc.edu
// CMPS 109 Fall '16
// MIS Project
// Reads in .mis files and returns appropriate information to the MIS system

#include "Parser.h"
#include <iostream>

using namespace std;

//construct a parser object from the provided filename
Parser::Parser(string filename){
   this->stream = ifstream(filename,ifstream::in);
}

Parser::~Parser() {
   stream.close();
}
   
vector<string> Parser::getNextLine() {
   vector<string> line;
   char* cur;
   
   stream.get(cur,50,' '); //extract the function type
   stream.ignore(1); //skip space character
   line.push_back(cur); //push it to vector
   
   stream.get(cur,1000,'\n'); //extract other data
   string data(cur); //construct string
   int start = 0, len = 0, n = data.length();
   //for (int i = 0; i < n-1; i++){
      //if (data[i] == ','){
          line.push_back(data.substr(start,n));
          //start = i+1;
          len = 0;
      //} else {
         len++;
      //}
   //}
   
   stream.ignore(1); //jump to next line
  
   return line;
}