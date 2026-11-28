#include "push_swap.h"
static int calc_index(t_stack *head,int content)
{
	int index;

	index = 0;
	while(head)
	{
		if(head->content < content)
			index++;
		head = head->next;
	}
	return(index);
}
void _index(t_stack *stack)
{
	t_stack *head;
	head = stack;
	while(stack)
	{
		stack->index = calc_index(head,stack->content);
		stack=stack->next;
	}
}