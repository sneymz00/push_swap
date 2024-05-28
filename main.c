/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:24:29 by camurill          #+#    #+#             */
/*   Updated: 2024/05/28 15:49:25 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_max(t_stack_node *stack)
{
		int				max;
		t_stack_node	*max_node;

		if (stack == NULL)
			return (NULL);
		max = INT_MIN;
		while (stack)
		{
			if (stack->value > max)
			{
				max = stack->value;
				max_node = stack;
			}
			stack = stack->next;
		}
		return (max_node);
}

bool	stack_shorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, false);
	else if ((*a)->next == big_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false); 
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_mysplit(argv[1], ' ');
	init_stack(&a, argv + 1, argc == 2);
	if (!stack_shorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
