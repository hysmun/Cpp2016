#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "InvalidClassementException.h"

InvalidClassementException::InvalidClassementException(const InvalidClassementException &tmp)
{
	msg = NULL;
	setMsg(tmp.getMsg());
}



InvalidClassementException::~InvalidClassementException()
{
	if(msg != NULL)delete msg;
}




int InvalidClassementException::setMsg(const char *tmp)
{
	if(getMsg() != NULL) delete msg;
	if(tmp != NULL)
	{
		msg = new char[strlen(tmp)+1];
		strcpy(msg, tmp);
	}
	return 1;
}
