#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libreries/ft_printf/ft_printf.h"
# include "libreries/libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				adove_medium;
	bool				cheapest;
	struct s_stack_node *target;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}				t_stack_node;

/*MAIN*/
void	message_error(char **error);
void	init_stack(t_stack_node **a, char **ag);
char	**ft_mysplit(char const *s, char c);

/*NODES*/
int		stack_shorted(t_stack_node *stack);
void	sort_three(t_stack_node **a);
void	sort_stack(t_stack_node **a, t_stack_node **b);

/*INSERT NBR*/


/*FAIL MESSAGE*/


/*LIBFT*/
long	my_atoi(const char *str);

#endif
