/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:52:27 by camurill          #+#    #+#             */
/*   Updated: 2024/05/23 18:55:21 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_i(a);
	current_i(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}