#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#include "ExceptionMessage.h"

ExceptionMessage::ExceptionMessage(const ExceptionMessage &tmp)
{
	msg = NULL;
	nbrErr = 0;
	setMsg(tmp.getMsg());
	setNbrErr(tmp.getNbrErr());
}



ExceptionMessage::~ExceptionMessage()
{
	if(msg != NULL)delete msg;
}




int ExceptionMessage::setMsg(const char *tmp)
{
	if(getMsg() != NULL) delete msg;
	if(tmp != NULL)
	{
		msg = new char[strlen(tmp)+1];
		strcpy(msg, tmp);
	}
	return 1;
}
