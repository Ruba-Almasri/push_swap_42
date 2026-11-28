#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
typedef struct s_stack
{
	int	content;
	int	index;
	struct s_stack *next;
}	t_stack;

typedef enum e_strategy
{
	ADAPTIVE = 0,
	SIMPLE = 1,
	MEDIUM=2,
	COMPLEX=3
} t_strategy;

//part 1
void add_back(t_stack **stack,t_stack *node);
void	free_stack(t_stack **stack);
int	stack_size(t_stack *stack);
t_stack *new_node(int content);

//part 2
int	ft_atoi(char *s,int *err);
int is_digit(char *s);
int check_duplicate(t_stack *stack);

//part 3(edge case)
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void free_split(char **ssplit);
//part 4(check_flags+index+check sort)
int check_flags(char *s,t_strategy *strategy,int *bench);
void _index(t_stack *stack);
int is_sorted(t_stack *stack);

//choose algorithm
void choose_algorithm(t_stack **a,t_stack **b,t_strategy strategy);
double calc_disorder(t_stack *stack);

//algorithm
void sort_adaptive(t_stack **a,t_stack **b);
void sort_simple(t_stack **a,t_stack **b);
void sort_medium(t_stack **a,t_stack **b);
void sort_complex(t_stack **a,t_stack **b);
#endif