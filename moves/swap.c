/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:23:09 by camurill          #+#    #+#             */
/*   Updated: 2024/05/24 18:43:20 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/***SWAP***/

static void	swap(t_stack_node **top)
{
	if (*top == NULL || top = NULL)
		return ;
	*top = (**top).next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	sa(t_stack_node **a, bool type)
{
	swap(a);
	if (!type)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool type)
{
	swap(b);
	if (!type)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool type)
{
	swap(a);
	swap(b);
	if (!type)
		write(1, "ss\n", 3);
}