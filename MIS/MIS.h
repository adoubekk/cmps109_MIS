#include <stdlib.h>
#include <vector>

#include "IncludeAll.h"


using namespace std;

class MIS{

private:
	Parser MIS_Parser;
	vector<Type* > MIS_variables;

public:

	MIS();
	~MIS();

	makeParser(string fileName); // file name taken from user input

    constructType(vector<string> RawInput); // create a type and push it to the MIS_variables

	ArithmeticOperation constructArithmeticOperation(vector<string> RawInput); // creates an  Arithmetic Operation object

	executeArithmeticOperation(AritheticOperation Arithmetic_Operation_Object); // execute the operation of an Arithmetic Operation Object

	JumpOperation constructJumpOperation(vector<string> RawInput); // 

	executeJumpOperation(JumpOperation Jump_Operation_Object); //

	Assign(Type* var1, Type* var2); // takes in two Types, first argument must exist in the MIS_variables, second argument must be made into a type if it is a constant

	Out(...); // takes in 1 to 12 arguments, prints each one out

	Execute(); // iterates through the parser object, uses switch statements based on the first Raw string keyword.
}