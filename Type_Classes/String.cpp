#include "String.h"
#include <string>
#include <stdlib.h>

using namespace std;

String::String()
{
}

String::String(string varName, string value, int size){
	name = varName;
	this->value = value;
	length = size;
}

String::~String(){
}

void String::getValue(void * ptr)
{
	string * Sptr = static_cast<string*>(ptr);
	*Sptr = value;
}

void String::getType(void * ptr){

	char* type = static_cast<char *>(ptr);
	*type = myType;

}

int String::getLength()
{
	return length;
}

char String::getChar(int index){
	if(index < 0 || index > length-1){
		//throw error
	}else{
		return value[index];
	}

}

void String::setValue(void * ptr){
	this->value = value;
}

void String::setChar(int index, char c){
	if(index < 0 || index > length-1){
		//throw error
	}else{
	  value[index]= c;
	}
}
