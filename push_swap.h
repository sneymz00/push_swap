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
	int					current_positions;
	int					index_final;
	int					push_cost;
	bool				adove_mediam;
	bool				cheapest;
	struct s_stack_node *target;
	struct s_stack_node	*next;
	struct s_stack_node *prev;
}				t_stack_node;

/*MAIN*/
void			init_stack(t_stack_node **a, char **ag);
t_stack_node	*find_last(t_stack_node *top);

/*STAKS*/
int				stack_shorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stack(t_stack_node **a, t_stack_node **b);

/*UTILS*/
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	set_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *a);

/*FAIL MESSAGE*/
void			message_error(char **error);
int				error_duplicate(t_stack_node *a, int nbr);
 
/*LIBFT*/
long			my_atoi(const char *str);
char			**ft_mysplit(char const *s, char c);

//Moves
void	sa(t_stack_node **a, bool type);
void	sb(t_stack_node **a, bool type);
void	ss(t_stack_node **a, t_stack_node **b, bool type);
void	pa(t_stack_node *a, t_stack_node **b, bool type);
void	pb(t_stack_node *b, t_stack_node **a, bool type);
void	ra(t_stack_node *a, bool type);
void	rb(t_stack_node *b, bool type);
void	rr(t_stack_node *a, t_stack_node *b, bool type);
void	rra(t_stack_node **a, bool type);
void	rrb(t_stack_node **b, bool type);
void	rrr(t_stack_node **a, t_stack_node **b, bool type);

#endif
