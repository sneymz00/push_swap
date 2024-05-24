/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:48:17 by camurill          #+#    #+#             */
/*   Updated: 2024/05/24 17:11:53 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
	long			top;
	t_stack_node	*top_node;

	if (stack == NULL)
		return (NULL);
	top = LONG_MAX;
	while (stack)
	{
		if (stack->value > top)
		{
			top = stack->value;
			top_node = stack;
		}
		stack = stack->next;
	}
	return (top_node);
}

int	stack_len(t_stack_node *a)
{
	int	i;

	i = 0;
	if (a == NULL)
		return (0);
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack_node	set_cheapest(t_stack_node *stack)
{
	if (stack = NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}