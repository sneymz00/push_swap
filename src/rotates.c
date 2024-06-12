/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:58:49 by camurill          #+#    #+#             */
/*   Updated: 2024/06/10 12:35:10 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a, bool type)
{
	rotate(a);
	if (!type)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool type)
{
	rotate(b);
	if (!type)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool type)
{
	rotate(a);
	rotate(b);
	if (!type)
		write(1, "rr\n", 3);
}
