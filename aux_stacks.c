/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:26:00 by camurill          #+#    #+#             */
/*   Updated: 2024/06/06 14:16:57 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a,
		t_stack_node **b, t_stack_node *cheap)
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
