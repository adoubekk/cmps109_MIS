#include "Char.h"

Char::Char(){
}

Char::Char(string varName, char value){
	name = varName;
	this->value = value;
}

Char::~Char(){
}

Char Char::getValue(){
	return name;
}

void Char::setValue(char value){
	this->value = value;
}
