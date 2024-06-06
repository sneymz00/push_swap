/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:20 by camurill          #+#    #+#             */
/*   Updated: 2024/06/06 16:10:29 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char const *s, char c)
{
	bool	inside;
	int		count;

	count = 0;
	while (*s)
	{
		inside = false;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!inside)
			{
				count++;
				inside = true;
			}
			s++;
		}
	}
	return (count);
}

static char	**my_free(char **s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*my_dupchar(char const *s, char c, int *pos)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = 0;
	while (*s == c)
	{
		s++;
		(*pos)++;
	}
	while (s[len] && s[len] != c)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	if (*s == '-' || *s == '+')
		*pos += 1;
	while (i < len)
	{
		dup[i] = *s;
		i++;
		s++;
	}
	dup[i] = '\0';
	*pos += i;
	return (dup);
}

char	**ft_mysplit(char const *s, char c)
{
	int		word_count;
	char	**split;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	word_count = ft_count_word(s, c);
	split = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!split)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			split[i] = malloc(sizeof(char));
			if (split[i] == NULL)
				my_free(split, word_count);
			split[i++][0] = '\0';
			continue ;
		}
		split[i++] = my_dupchar(s + pos, c, &pos);
	}
	split[i] = NULL;
	return (split);
}

/*
El error que tengo es que en mi split
me guarda el (-) como un numero más que split
y me da el numero nulo, por eso sale error
int main(void)
{
	char const *p = "hello!    222";
	char t = ' ';
	int i = 0;
	char **split;
	split = ft_mysplit(p, t);
	printf("%s", split[1]);
	i++;
	return (0);
}*/
