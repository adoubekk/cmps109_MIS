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
	Type* temp; // using this to fetch the first argument as the one to change
	int globalCounter = 0;
	char type;
	char otherType;
	int val = 0;
	int val2;


	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, int.
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
		    temp = *it; // set temp to point to the first argument
			temp->getType(&type); // get type for exception purposes
			temp->getValue(&val);
			temp->setValue(&val); // REMOVE
		}else{
			Type * temp2 = *it;
			temp2->getValue(&val2); // dereference temp and increment it with the next iteration dereferenced
			temp2->getType(&otherType);
			if (otherType != type){
				// throw Arithmetic error
			}

			val += val2;
		}
  		globalCounter += 1;
	}

    temp->setValue(&val);
	temp = NULL;

};

Add::~Add(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}