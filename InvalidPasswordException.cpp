#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "InvalidPasswordException.h"

int InvalidPasswordException::BAD_LENGTH_ERROR = 1;
int InvalidPasswordException::MISSING_ALPHA_ERROR = 2;
int InvalidPasswordException::MISSING_DIGIT_ERROR = 3;


InvalidPasswordException::InvalidPasswordException(const InvalidPasswordException &tmp)
{
	msg = NULL;
	setCode(tmp.getCode());
	setMsg(tmp.getMsg());
}



InvalidPasswordException::~InvalidPasswordException()
{
	if(msg != NULL)delete msg;
}




int InvalidPasswordException::setMsg(const char *tmp)
{
	if(getMsg() != NULL) delete msg;
	if(tmp != NULL)
	{
		msg = new char[strlen(tmp)+1];
		strcpy(msg, tmp);
	}
	return 1;
}


void InvalidPasswordException::perror(const char *tmp)
{
	if(tmp != NULL)
	cout << tmp << " : ";
	
	switch(code)
	{
		case 1:
			cout << "Bad lenght error";
			break;
		case 2:
			cout << "Missing alpha error";
			break;
		case 3:
			cout << "Missing digit error";
			break;
		default:
			break;
	}
}













