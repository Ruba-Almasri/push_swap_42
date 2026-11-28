#include "push_swap.h"

void add_back(t_stack **stack,t_stack *node)
{
	t_stack *temp;

	if (!stack || !node)
		return;
	if(!*stack)
	{	*stack = node;
		return;
	}
	temp = *stack;
	while(temp->next)
	{	temp = temp->next;}
	temp->next=node;
}