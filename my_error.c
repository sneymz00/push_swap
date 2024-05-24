/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:49:49 by camurill          #+#    #+#             */
/*   Updated: 2024/05/24 19:24:22 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_error(char  **error)
{
	exit(2);
}

static int sintax(char *str)
{

}

int	error_syntax(t_stack_node *stack)
{
	if (stack = NULL)
		return (0);
	while(stack)
	{
		if (sintax(stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if ((*a).value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}