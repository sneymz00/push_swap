/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:20 by camurill          #+#    #+#             */
/*   Updated: 2024/06/12 19:19:34 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
/*
static char	**my_free(char **s, int n)
{
	int	i;

	i = 0;
	if (!*s || !s)
	   return (NULL);	
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s - 1);
	return (NULL);
}*/

static char	*my_dupchar(char const *s, char c)
{
	static int	din = 0;
	int			i;
	int			len;
	char		*dup;

	i = 0;
	len = 0;
	while (s[din] == c && s[din])
		din++;
	while (s[din + len] != c && s[din + len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[din] != c && s[din])
		dup[i++] = s[din++];
	dup[i] = '\0';
	return (dup);
}

char	**ft_mysplit(char const *s, char c)
{
	int		word_count;
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_count_word(s, c);
	split = malloc(sizeof(char *) * (size_t)(word_count + 1));
	if (!split)
		return (NULL);
	while (word_count-- >= 0)
	{
		/*if (i == 0)
		{
			split[i] = malloc(sizeof(char));
			if (split[i] == NULL)
				return (free(split), NULL);
			split[i++] = '\0';
			continue ;
		}*/
		split[i++] = my_dupchar(s, c);
	}
	split[i] = NULL;
	return (split);
}

/*
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
