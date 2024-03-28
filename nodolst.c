/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodolst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:12:33 by camurill          #+#    #+#             */
/*   Updated: 2024/03/28 17:47:52 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*fail_malloc(t_lst **mtx)
{
	int	i;

	i = 0;
	while(mtx[i]->nbr != NULL)
	{
		free(mtx[i]);
		i++;
	}
	write(1, "ERROR MALLOC", 13);
	return (NULL);
}

void	**create_n(t_lst **init, int sze) //Corregir
{
	t_lst	*tmp;
	if (!*init)
	{
		*init = (t_lst **)malloc(sizeof(int) * (sze + 1));
		if (!init)
			return (fail_malloc(init));
		if (init)
		{
			tmp = *init;
			tmp->lst = malloc(sizeof(int) * (strlen(tmp->nbr) + 1));
		}
	}
	return ;
}

int	nbr_ndo(t_lst *data, int nbr)
{
	if (!data)
		return (0);
	data->nbr = nbr;
	return nbr; 
}