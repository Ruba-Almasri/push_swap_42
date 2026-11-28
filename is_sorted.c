#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	if(!stack)
		return(1);
	while(stack->next)
	{
		if(stack->index > stack->next->index)
			return(0);
		stack=stack->next;
	}
	return(1);
}