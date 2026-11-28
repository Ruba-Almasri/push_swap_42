#include "push_swap.h"

void free_split(char **ssplit)
{
	int i;
	if (!ssplit)
	return ;
i = 0;
while(ssplit[i])
{
	free(ssplit[i]);
	i++;
}
free(ssplit);
}
static int print_error(t_stack **stack,char **ssplit)
{
	write(2,"Error\n",6);
	free_split(ssplit);
	free_stack(stack);
	return(1);
}
static int handel_input(char *input,t_stack **stack)
{
	int num;
	int err;
	t_stack *node;

	if(!is_digit(input))
		return(1);
	err=0;
	num=ft_atoi(input,&err);
	if(err)
		return(1);
	node = new_node(num);
	if(!node)
		return(1);
	add_back(stack,node);
	return(0);
}
static int handel_arg(char *argv,t_stack **stack,t_strategy *strategy,int *bench)
{
	char **ssplit;
	int j;

	ssplit=ft_split(argv,' ');
	if(!ssplit)
	return(print_error(stack,NULL));
	if(!ssplit[0])
	{
		free_split(ssplit);
		return(print_error(stack,NULL));	
	}
	j = 0;
	while(ssplit[j])
	{
		if(!check_flags(ssplit[j],strategy,bench))
		{
		if(handel_input(ssplit[j],stack))
			return(print_error(stack,ssplit));
		}
		j++;
	}
	free_split(ssplit);
	return(0);
}
int main(int argc,char **argv)
{
	int i;
	t_stack *stack;
	t_stack *stack_b;
	t_strategy strategy;
	int bench;
	double disorder;

	if(argc <2)
		return(0);

	i = 1;
	stack = NULL;
	strategy = ADAPTIVE;
	bench = 0;
	stack_b = NULL;
	while(i<argc)
	{
			if(handel_arg(argv[i],&stack,&strategy,&bench))
				return(1);
		i++;
	}
	if(check_duplicate(stack))
		return(print_error(&stack,NULL));
	_index(stack);
	disorder = calc_disorder(stack);
	printf("%.2f",disorder);
	if(!is_sorted(stack))
		choose_algorithm(&stack,&stack_b,strategy);
	if(bench)
	{
			//bench function
	}

	free_stack(&stack);
	free_stack(&stack_b);
	return(0);
}
	