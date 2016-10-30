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

//close input stream on destruct
Parser::~Parser() {
   stream.close();
}

//returns the next line as a vector of strings
vector<string> Parser::getNextLine() {
   vector<string> line;
   stringbuf sb(ios_base::in | ios_base::out);
   
   stream.get(sb,' '); //extract the function type
   stream.ignore(1); //skip space character
   line.push_back(sb.str()); //push it to vector
   
   sb.str(""); //clear stringbuffer
   
   stream.get(sb,'\n'); //extract other data
   stream.ignore(1); //skip newline character
   
   //store each token to vector, delimiting by ','
   int start = 0, len = 0, n = sb.str().length();
   for (int i = 0; i < n; i++){
      if (sb.str()[i] == ','){
         line.push_back(sb.str().substr(start,len));
		 start = i+1;
		 len = 0;
	  } else {
		 len++;
	  }
   }
   
   line.push_back(sb.str().substr(start,len-1)); //get last token
  
   return line;
}

//go to the position indicated by the label with name
void Parser::goToLabel(string name){
   int len = labels.size();
   int pos;
   for (int i = 0; i < len; i++) {
      if (name.compare(labels[i].nameOf()) == 0){
         pos = labels[i].getPosition();
      }
   }
	stream.clear(); //supposedly C++11 does this automatically, but seekg fails without this call if eof has been reached
	stream.seekg(pos, stream.beg);
}

void Parser::setLabel(string name){
	int pos = stream.tellg();
   Label L(pos,name);
   labels.push_back(L);
}

//returns true if there are more characters to get in the file
bool Parser::hasNextLine() {
   return (stream.peek() != EOF);
}

