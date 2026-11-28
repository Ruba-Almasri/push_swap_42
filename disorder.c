#include "push_swap.h"

static long count_mistakes(t_stack *node)
{
	t_stack *cmp;
	long mistakes;

	mistakes = 0;
	cmp = node->next;
	while(cmp)
	{
		if(node->content > cmp->content)
			mistakes++;
		cmp= cmp-> next;
	}
	return(mistakes);
}
double calc_disorder(t_stack *stack)
{
	long mistakes;
	long total;
	long size;

	mistakes = 0;
	total = 0;
	size = stack_size(stack);
	if(size < 2)
		return(0.0);
	total = size * (size-1)/2;
	while(stack)
	{
		mistakes += count_mistakes(stack);
		stack = stack->next;
	}
	return((double)mistakes/(double)total);
}