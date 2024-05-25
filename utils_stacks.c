/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:48:17 by camurill          #+#    #+#             */
/*   Updated: 2024/05/25 14:40:39 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			small;
	t_stack_node	*small_node;

	if (stack == NULL)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
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

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}