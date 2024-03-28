/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:24:29 by camurill          #+#    #+#             */
/*   Updated: 2024/03/28 17:57:46 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	message_error(void)
{
	ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}

static int	is_alpha(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j  = 0;
		while (str[i][j] )
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (1);
			j++;
		}
		if (!(ft_atoi(str[i]) < INT_MAX && ft_atoi(str[i]) > INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

//static int	is_repeat(char **)

int	main(int argc, char **argv)
{
	int 	i;
	t_lst	**ndo;
	long	nbr;

	i = 1;
	if (argc > 1)
	{
		if (1 == is_alpha(argv))
			message_error();
		while (argv[i])
		{
			ndo = create_n(argv[i]);
			if (!ndo)
				exit(EXIT_FAILURE);
			nbr = nbr_ndo(ndo, ft_atoi(argv[i]));
			if (!nbr)
				return (fail_malloc(ndo));
			//printf("%i", nbr);
		}
	}
	else
		write(1, "\n", 1);
}