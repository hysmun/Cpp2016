#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "utils.h"

void bidonnageSec(int* numeroClub,char* login,char* passwd,const Secretaire& s)
{
	*numeroClub = s.getNumClub();
	strcpy(login,s.getLogin());
	strcpy(passwd,s.getPassword());
}
