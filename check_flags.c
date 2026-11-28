
#include "push_swap.h"

static int check_str(char *a,char *b)
{
	int i;

	i = 0;
	if(!a || !b)
		return(0);
	while(a[i] && b[i])
	{
		if(a[i] != b[i])
			return(0);
	i++;
	}
	if(a[i] == '\0' && b[i]=='\0')
		return(1);
	return(0);
}
static int set_strategy(char *s,t_strategy *strategy)
{
	if(check_str(s,"--simple"))
	{
		*strategy = SIMPLE;
		return(1);
	}
	if(check_str(s,"--medium"))
	{
		*strategy = MEDIUM;
		return(1);
	}
	if(check_str(s,"--complex"))
	{
		*strategy = COMPLEX;
		return(1);
	}
	if(check_str(s,"--adaptive"))
	{
		*strategy = ADAPTIVE;
		return(1);
	}
	return(0);
}
int check_flags(char *s,t_strategy *strategy,int *bench)
{
	if(check_str(s,"--bench"))
	{
		*bench = 1;
		return(1);
	}
	return(set_strategy(s,strategy));
}