#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_lst
{
	int		nbr;
	t_lst	*lst;
}				t_lst;

/*MAIN*/

/*CREATE A NODO*/
void	**create_n(t_lst **init, int sze);

/*INSERT NBR*/
int	nbr_ndo(t_lst *data);

/*FAIL MESSAGE*/
char	*fail_malloc(t_lst **mtx);

/*LIBFT*/
long	ft_atoi(const char *str);

#endif
