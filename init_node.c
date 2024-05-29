/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:11:21 by camurill          #+#    #+#             */
/*   Updated: 2024/05/29 19:12:53 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	if (stack == NULL)
		return ;
	i = 0;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_positions = i;
		if (i <= center)
			stack->adove_mediam = true;
		else
			stack->adove_mediam = false;
		stack = stack->next;
		i++;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_positions;
		if (!(b->adove_mediam))
			b->push_cost = len_b - (b->current_positions);
		if (b->target->adove_mediam)
			b->push_cost += b->target->current_positions;
		else
			b->push_cost += len_a - (b->target->current_positions);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_value;
	t_stack_node	*best_node;

	if (b == NULL)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_value)
		{
			best_value = b->push_cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*node_a;
	t_stack_node	*target;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX;
		node_a = a;
		while (node_a)
		{
			if (node_a->value > b->value && node_a->value < best_index)
			{
				best_index = node_a->value;
				target = node_a;
			}
			node_a = node_a->next;
		}
		if (best_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_node(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
