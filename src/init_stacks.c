/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:12:33 by camurill          #+#    #+#             */
/*   Updated: 2024/06/10 12:33:42 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	my_atoi(const char *str)
{
	int		i;
	long	value;
	long	number;

	i = 0;
	value = 1;
	number = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			value = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * value);
}

t_stack_node	*find_last(t_stack_node *top)
{
	if (top == NULL)
		return (NULL);
	while (top->next)
		top = top->next;
	return (top);
}

static void	node_to_append(t_stack_node **a, int n)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack(t_stack_node **a, char **ag, bool frag)
{
	long	n;
	int		i;

	i = 0;
	while (ag[i])
	{
		if (error_syntax(ag[i]))
			message_error(a, ag, frag);
		n = my_atoi(ag[i]);
		if (n > INT_MAX || n < INT_MIN)
			message_error(a, ag, frag);
		if (error_duplicate(*a, (int)n))
			message_error(a, ag, frag);
		node_to_append(a, (int)n);
		i++;
	}
	if (frag)
		error_matrix(ag);
}
