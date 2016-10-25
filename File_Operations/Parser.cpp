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
   
   string data = sb.str(); //extract contents of buffer
   
   //store each token to vector, delimiting by ','
   int start = 0, len = 0, n = data.length();
   for (int i = 0; i < n; i++){
      if (data[i] == ','){
         line.push_back(data.substr(start,len));
		 start = i+1;
		 len = 0;
	  } else {
		 len++;
	  }
   }
   
   line.push_back(data.substr(start,len-1)); //get last token
  
   return line;
}

//returns true if there are more characters to get in the file
bool Parser::hasNextLine() {
   return (stream.peek() != EOF);
}

