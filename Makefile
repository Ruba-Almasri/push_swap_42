
NAME = push_swap

CC = cc

CF = -Wall -Wextra -Werror

SRCS = add_back.c check_duplicate.c free_stack.c ft_atoi.c ft_split.c \
ft_substr.c is_digit.c main.c new_node.c stack_size.c\
check_flags.c _index.c is_sorted.c choose_algorithm.c disorder.c adaptive.c\
sort_simple.c sort_medium.c sort_complex.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CF) $(OBJS) -o $(NAME)

%.o : %.c  $(HEADER)
	$(CC) $(CF) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
