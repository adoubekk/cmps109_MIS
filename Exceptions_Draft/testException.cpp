#include "ArithmeticException.h"
#include "Exception.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
// test
int main(){
	try{
		//adding two strings
		throw(ArithmeticException((string)"Can't add strings"));  // 
	}
	catch(ArithmeticException e){
		e.print();
	}

}