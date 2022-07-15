#include "server.h"

int check(int exp, const char *msg)
{
	if(exp = SERVERERROR)
	{
		perror(msg);
		exit(1);
	}
	return exp;
}
