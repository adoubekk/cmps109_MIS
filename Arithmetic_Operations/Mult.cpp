#include "Mult.h"
#include "../Type_Classes/Type.h"
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

Mult::Mult(vector<Type *> & MIS_Args): variables(MIS_Args){ // copy the arguments into Add object variable vector
};


void Mult::doOperation(){
	Type* first_arg; // using this to fetch the first argument as the one to change
	Type* second_arg;
	int globalCounter = 0;
	char type1;
	char type2;
	char otherType;
	double val = 0;
	double val2 = 0;
	int Nval = 0;
	int Nval2 = 0;

	if(variables.size() <= 2){
		// throw error
	}

	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, Type.
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
			first_arg = *it; // set temp to point to the first argument
			first_arg->getType(&type1); // get type for exception purposes
		}
		if(globalCounter == 1){
			second_arg = *it;
			second_arg->getType(&type2);
			if (type2 != type1 || type2 != 'N' && type2 != 'R'){ // type checking
				// throw Arithmetic error
			}

			if(type2 == 'N'){
			second_arg->getValue(&Nval);
		}else{
			second_arg->getValue(&val);
		}

		}

		else{
			Type* other_arg = *it; // dereference it and multiply it with the next iteration dereferenced
			other_arg->getType(&otherType);
			if (otherType != type1 || otherType != 'N' && otherType != 'R'){
				// throw Arithmetic error
			}

			if(type2 == 'N'){
			other_arg->getValue(&Nval2);
			Nval *= Nval2;
		}else{
			other_arg->getValue(&val2);
			val *= val2;
		}

		}

  		globalCounter += 1;
	}

	if(type1 == 'N'){
	first_arg->setValue(&Nval);
}else{
	first_arg->setValue(&val);	
}
	first_arg = NULL;

};

Mult::~Mult(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}