#include "String.h"

String::String()
{
}

String::String(string varName, string value){
	name = varName;
	this->value = value;
}

String::~String(){
}

string String::getValue()
{
	return value;
}

int String::getLength()
{
	return (this->name.length());
}

void String::setValue(string value){
	this->value = value;
}
