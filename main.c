/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:24:29 by camurill          #+#    #+#             */
/*   Updated: 2024/05/23 18:09:01 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_error(char  **error)
{
	ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

//static int	is_repeat(char **)

int	main(int argc, char **argv)
{
	int				i;
	t_stack_node	*a;
	t_stack_node	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv[i]);
	if (!stack_list(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len == 3)
			sort_three(a);
		else
			sort_stack(&a, &b);
	}
	free_stack(a);
	return (0);
}
