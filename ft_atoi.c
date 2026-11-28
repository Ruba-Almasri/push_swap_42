#include "push_swap.h"

int	ft_atoi(char *s,int *err)
{
	int sign;
	long	result;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	*err = 0;
	if(s[i]=='-' || s[i]=='+')
	{
		if(s[i]=='-')
			sign=-1;
		i++;
	}
	while(s[i] == '0')
		i++;
	while(s[i]>='0' && s[i] <='9')
	{
		if (sign == -1 && result>(-(long)INT_MIN-(s[i]-'0'))/10)
		{
			*err = 1;
			return(0);
			}
		if (sign == 1 && result>(INT_MAX-(s[i]-'0'))/10)
		{
			*err = 1;
			return(0);
			}
				result = (10 * result)+(s[i]-'0');
		i++;
		
	}
	return(sign*result);
}