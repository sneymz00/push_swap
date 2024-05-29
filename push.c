/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:43:51 by camurill          #+#    #+#             */
/*   Updated: 2024/05/29 19:14:50 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (*dst == NULL)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool type)
{
	push(a, b);
	if (!type)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool type)
{
	push(b, a);
	if (!type)
		write(1, "pb\n", 3);
}
