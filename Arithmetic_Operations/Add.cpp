#include "Add.h"
#include "../Type_Classes/Type.h"
#include "../Type_Classes/Numeric.h"
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

Add::Add(vector<Type *> & MIS_Args): variables(MIS_Args){ // copy the arguments into Add object variable vector
};


void Add::doOperation(){
	Type* first_arg; // using this to fetch the first argument as the one to change
	Type* second_arg;
	int globalCounter = 0;
	char type1;
	char type2;
	char otherType;
	double val = 0;
	double val2;


	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, int.
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
		    first_arg = *it; // set temp to point to the first argument
			first_arg->getType(&type1); // get type for exception purposes
		}
		if(globalCounter == 1){

			second_arg = *it;
			second_arg->getValue(&val);
			second_arg->getType(&type2);
			if(type2 != type1){
			//throw error
			}
		}
		else
		{
			Type * other_arg = *it;
			other_arg->getValue(&val2); // dereference temp and increment it with the next iteration dereferenced
			other_arg->getType(&otherType);
			if (otherType != type1){
				// throw Arithmetic error
			}

			val += val2;
		}
  		globalCounter += 1;
	}

    first_arg->setValue(&val);
	first_arg = NULL;

};

Add::~Add(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}