#include "push_swap.h"

int check_duplicate(t_stack *stack)
{
	t_stack *test;

	while(stack)
	{
		test = stack->next;
		while(test)
		{
			if(test->content == stack->content)
				return(1);
			test = test->next;
		}
		stack=stack->next;
	}
	return(0);
}