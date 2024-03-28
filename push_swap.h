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
int	is_alpha(char **str);

/*LIBFT*/
long	ft_atoi(const char *str);

#endif
