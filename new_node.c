#include "push_swap.h"

t_stack *new_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if(!node)
		return(NULL);
	node->content=content;
	node->index=0;
	node->next = NULL;
	return(node);
}