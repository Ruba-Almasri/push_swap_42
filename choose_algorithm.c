#include "push_swap.h"
void choose_algorithm(t_stack **a,t_stack **b,t_strategy strategy)
{
	if(!a || !b || is_sorted(*a))
		return ;
	if (strategy == SIMPLE)
		sort_simple(a,b);
	else if (strategy == MEDIUM)
		sort_medium(a,b);
	else if (strategy == COMPLEX)
		sort_complex(a,b);
	else
		sort_adaptive(a,b);
}