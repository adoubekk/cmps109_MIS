#include "Add.h"
#include ""
#include <stdlib.h>
#include <typeinfo>
#include <string>

using namespace std;

Add::Add(vector<Type *> & MIS_Args): variables(MIS_Args){ // copy the arguments into Add object variable vector
};


void Add::doOperation(){
	int* temp = NULL; // using this to fetch the first argument as the one to change
	int globalCounter = 0;
	string type;

	// iterate through argument pointers *it refers to the pointer/address, **it refers to the dereferenced object, in the case, int.
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		if(globalCounter == 0 ){
			temp = *it; // set temp to point to the first argument
			type = typeid(**it.getValue()).name(); // get type for exception purposes
			auto temp2 = *temp.getValue();
		}else{
			int temp2 += += **it; // dereference temp and increment it with the next iteration dereferenced
			if (typeid(**it).name() != type){
				// throw Arithmetic error
			}
		}
  		globalCounter += 1;
	}

   *temp.setValue(temp2);
	temp = NULL;

};

Add::~Add(){
	for( vector<Type *>::iterator it = variables.begin(); it != variables.end(); it++){
		*it = NULL;
	}
}