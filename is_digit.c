#include "push_swap.h"

int is_digit(char *s)
{
	int i;

	i = 0;
	if(!s || !s[i])
		{return(0);}
		if(s[i] == '-' || s[i] == '+')
			i++;
		if(!s[i])
			return(0);
		while(s[i])
		{
			if(s[i]<'0' || s[i] > '9')
			return(0);
			i++;
		}
		return(1);
}
