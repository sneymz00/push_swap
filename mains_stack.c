/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:26:00 by camurill          #+#    #+#             */
/*   Updated: 2024/05/25 18:11:07 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top, char type)
{
	while (*stack != top)
	{
		if (type == 'a')
		{
			if (top->adove_mediam)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (type == 'b')
		{
			if (top->adove_mediam)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = return_cheapest(*b);
	if (cheap_node->adove_mediam && cheap_node->target->adove_mediam)
		rotate_both(a, b, cheap_node);
	else if (!(cheap_node->adove_mediam) && 
			!(cheap_node->target->adove_mediam))
		reverse_rotate_both(a, b, cheap_node);
	finish_rotation(b, cheap_node, 'b');
	finish_rotation(a, cheap_node->target, 'a');
	pa(a, b, false);
}

static void hadle_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*data;

	while (stack_len(*a) > 3)
	{
		data = find_smallest(*a);
		init_node(*a, *b);
		finish_rotation(a, data, 'a');
		pb(b, a, false);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*small;
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		hadle_five(a, b);
	else
	{
		while(len_a-- < 3)
			pb(b, a, false);
	}
	sort_three(a);
	while(b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	small = find_smallest(*a);
	if (small->adove_mediam)
	{
		while (*a != small)
			ra(a, false);
	}
	else
		while (*a != small)
			rra(a, false);
}