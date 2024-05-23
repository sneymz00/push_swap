/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:26:00 by camurill          #+#    #+#             */
/*   Updated: 2024/05/23 19:00:25 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_shorted(t_stack_node *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, -1);
	else if ((*a)->next == big_node)
		rra(a, -1);
	if ((*a)->value > (*a)->next->value)
		sa(a, -1); 
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !s_stack_shorted(*a))
		pb(b, a, -1);
	if (len_a-- > 3 && !stack_shorted(*a))
		pb(b, a, -1);
	while (len_a-- > 3 && !stack_shorted(*a))
	{
		init_nodes(*a, *b);
		move_a_to_b(*a, *b);
	}
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(*a, *b);
	}
	current_i(*a);
	top_min_a(a);
	
}