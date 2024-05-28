/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:49:49 by camurill          #+#    #+#             */
/*   Updated: 2024/05/28 15:37:25 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*now;

	if (stack == NULL)
		return ;
	now = *stack;
	while (now)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
}

void	error_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL || *matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	message_error(t_stack_node **error, char **ag, bool frag)
{
	free_stack(error);
	if (frag)
		error_matrix(ag);
	write(1, "Error", 6);
	exit(1);
}


int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '+' ||
		(*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') &&
		!(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}