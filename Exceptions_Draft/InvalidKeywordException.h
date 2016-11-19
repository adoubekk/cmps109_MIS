/*
 * InvalidKeywordException.h
 * Henry Chang
 */
#ifndef INVALIDKEYWORDEXCEPTION_H
#define INVALIDKEYWORDEXCEPTION_H

#include "stdlib.h"
#include <string>

class InvalidKeywordException(string Estr): public exception{
private:
	string Error;
public:
	InvalidKeywordException(string Estr);

	~InvalidKeywordException() throw();

	const string what() const throw();
}

#endif // INVALIDKEYWORDEXCEPTION_H
