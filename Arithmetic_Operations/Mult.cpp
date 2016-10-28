#include "Mult.h"
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

Mult::Mult(vector<int *> & MIS_Args): variables(MIS_Args){ // copy the arguments into Add object variable vector
};


void Mult::doOperation(){
	int* temp = NULL; // using this to fetch the first argument as the one to change
	int globalCounter = 0;
	string type;

	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, int.
	for( vector<int *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
			temp = *it; // set temp to point to the first argument
			type = typeid(**it).name(); // get type for exception purposes
		}else{
			*temp *= **it; // dereference temp and multiply it with the next iteration dereferenced
			if (typeid(**it).name() != type){
				// throw Arithmetic error
			}
		}
  		globalCounter += 1;
	}

	temp = NULL;

};

Mult::~Mult(){
	for( vector<int *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}